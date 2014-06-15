/*
// Ia.cpp for Ia in /home/telenc_r/cpp_bomberman
//
// Made by Remi telenczak
// Login   <telenc_r@epitech.net>
//
// Started on  Fri Jun 13 12:28:13 2014 Remi telenczak
// Last update Sun Jun 15 19:11:51 2014 Steven Martreux
*/

#include	"IaBomber.hpp"
#include	"EventManager.hpp"
#include	"DefaultBomb.hpp"
#include	"ABonus.hpp"
#include	"AFire.hpp"

IaBomber::IaBomber(int x, int y, int z, Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : APlayer(x, y, z, map, model, event, clock)
{
  this->getList();
  this->set_x(x);
  this->set_z(z);
  this->set_roty(90);
  time(&_timeBomb);
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("isInRisk", &IaBomber::isInRiskIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("enemyDistance", &IaBomber::enemyDistanceIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("wallDistance", &IaBomber::wallDistanceIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("bonusDistance", &IaBomber::bonusDistanceIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("enemyNear", &IaBomber::enemyNearIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("targetPlayer", &IaBomber::targetPlayerIa));

  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goSafe", &IaBomber::goSafeIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("poseBomb", &IaBomber::poseBombIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goBonus", &IaBomber::goBonusIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goWall", &IaBomber::goWallIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goEnemyNear", &IaBomber::goEnemyNearIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goPlayer", &IaBomber::goPlayerIa));
  this->_positionTo.x = -1;
  this->changeRot(0, 1);
}

IaBomber::~IaBomber()
{

}

int	IaBomber::isInRiskIa()
{
  if (this->isInRisk() == true)
    return 1;
  return -1;
}

int	IaBomber::targetPlayerIa()
{
  return 1;
}

int	IaBomber::enemyDistanceIa()
{
  APlayer	*result;

  result = this->minDistanceEnemy();
  if (result)
    return _map->distanceObj(result, this);
  return -1;
}

int	IaBomber::wallDistanceIa()
{
  AObjectPhysic	*result;

  result = this->minDistanceDestruc();
  if (result)
    return _map->distanceObj(result, this);
  return -1;
}

int	IaBomber::bonusDistanceIa()
{
  ABonus	*result;

  result = this->getBonus(100);
  if (result)
    return _map->distanceObj(result, this);
  return -1;
}

int	IaBomber::enemyNearIa()
{
  APlayer	*result;

  result = this->minDistanceEnemy();
  if (result)
    return 1;
  return -1;
}

bool		IaBomber::goSafeIa()
{
  glm::vec2	target;
  glm::vec2	target2;


  target = getPositionNoRisk();
  target2 = target;
  changeRot(target2.x, target2.y);
  this->_positionTo.x = target.x;
  this->_positionTo.y = target.y;
  this->move(glm::vec3(0, 0, -0.2));
  return true;
}

bool		IaBomber::goPlayerIa()
{
  APlayer	*player;
  glm::vec2	target;

  player = (APlayer *)(_map->getPlayer());
  target.x = player->get_x();
  target.y = player->get_z();

  changeRot(target.x, target.y);
  this->_positionTo.x = target.x;
  this->_positionTo.y = target.y;
  this->move(glm::vec3(0, 0, -0.2));
  return true;
}

bool		IaBomber::poseBombIa()
{
  DefaultBomb	*bomb;
  int		x;
  int		z;
  glm::vec3	t;
  time_t	currTime;
  glm::vec2	testNoRisk;
  double	second;

  time(&currTime);
  if (this->_nbrBomb <= 0)
    return false;
  if (this->checkPositionCollision(BOMB) != NULL)
    return false;
  second = difftime(currTime, _timeBomb);
  if (second < 7)
    return true;
  time(&_timeBomb);
  x = (int)this->get_x() - ((int)this->get_x() % 3);
  if (x + 1.5 < this->get_x())
    x += 3;
  z = (int)this->get_z() - ((int)this->get_z() % 3);
  if (z + 1.5 < this->get_z())
    z += 3;
  testNoRisk = getPositionNoRisk();
  if (testNoRisk.x == x && testNoRisk.y == z)
    return true;
  this->_nbrBomb--;
  bomb = new DefaultBomb(_map, _modelList, _event, this, _clock);
  bomb->setPo(this->_po);
  bomb->set_x(x);
  bomb->set_z(z);
  t.x = x;
  t.y  = 0;
  t.z = z;
  _event->dispatchEvent("bombDrop", &(t));
  this->_map->setBomb(bomb);
  return true;
}

glm::vec2	IaBomber::getChemin(int x, int z)
{
  glm::vec3	pos;
  glm::vec3	tmp;

  pos.x = (int)this->get_x() - ((int)this->get_x() % 3);
  if (pos.x + 1.5 < this->get_x())
    {
      pos.x += 3;
    }
  pos.z = (int)this->get_z() - ((int)this->get_z() % 3);
  if (pos.z + 1.5 < this->get_z())
    pos.z += 3;
  if (std::max((int)pos.x, (int)x) - std::min((int)pos.x,(int) x) <=  3 && std::max((int)pos.z,(int) z) - std::min((int)pos.z, (int)z) <= 3)
    return glm::vec2(x, z);
  if (x <= pos.x)
    {
      tmp.x = pos.x - 3;
      tmp.y = 0;
      tmp.z = pos.z;
      if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      if (z <= pos.z)
	{
	  tmp.x = pos.x;
	  tmp.z = pos.z - 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	  tmp.x = pos.x;
	  tmp.z = pos.z + 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	}
      else
	{
	  tmp.x = pos.x;
	  tmp.z = pos.z + 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	  tmp.x = pos.x;
	  tmp.z = pos.z - 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	}
      tmp.x = pos.x - 3;
      tmp.z = pos.z;
      if (_map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      tmp.x = pos.x;
      tmp.z = pos.z - 3;
      if (_map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      tmp.x = pos.x;
      tmp.z = pos.z + 3;
      if (_map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      return glm::vec2(x, z);
    }
  else
    {
      tmp.x = pos.x + 3;
      tmp.y = 0;
      tmp.z = pos.z;
      if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      if (z <= pos.z)
	{
	  tmp.x = pos.x;
	  tmp.z = pos.z - 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	  tmp.x = pos.x;
	  tmp.z = pos.z + 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	}
      else
	{
	  tmp.x = pos.x;
	  tmp.z = pos.z + 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	  tmp.x = pos.x;
	  tmp.z = pos.z - 3;
	  if (isInRisk(tmp.x, tmp.z) == false && _map->isBlock(tmp.x, tmp.z) == false)
	    return glm::vec2(tmp.x, tmp.z);
	}
      tmp.x = pos.x + 3;
      tmp.z = pos.z;
      if (_map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      tmp.x = pos.x;
      tmp.z = pos.z - 3;
      if (_map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      tmp.x = pos.x;
      tmp.z = pos.z + 3;
      if (_map->isBlock(tmp.x, tmp.z) == false)
	return glm::vec2(tmp.x, tmp.z);
      return glm::vec2(x, z);
    }
  return glm::vec2(x, z);
}

bool	IaBomber::goBonusIa()
{
  ABonus	*result;
  glm::vec2	target;

  result = this->getBonus(100);
  target = getChemin(result->get_x(), result->get_z());
  if (isInRisk(target.x, target.y) == false)
    {
      changeRot(target.x, target.y);
      this->_positionTo.x = result->get_x();
      this->_positionTo.y = result->get_z();
      this->move(glm::vec3(0, 0, -0.2));
    }
  return true;
}

bool	IaBomber::goWallIa()
{
  AObjectPhysic	*result;
  glm::vec2	target;

  result = this->minDistanceDestruc();
  target = getChemin(result->get_x(), result->get_z());
  if (isInRisk(target.x, target.y) == false)
    {
      changeRot(target.x, target.y);
      this->_positionTo.x = result->get_x();
      this->_positionTo.y = result->get_z();
      this->move(glm::vec3(0, 0, -0.2));
    }
  return true;
}

bool	IaBomber::goEnemyNearIa()
{
  APlayer	*result;
  glm::vec2	target;

  result = this->minDistanceEnemy();
  if (result)
    {
      target = getChemin(result->get_x(), result->get_z());
      if (isInRisk(target.x, target.y) == false)
	{
	  changeRot(target.x, target.y);
	  this->_positionTo.x = result->get_x();
	  this->_positionTo.y = result->get_z();
	  this->move(glm::vec3(0, 0, -0.2));
	}
    }
  return true;
}

void	IaBomber::changeRot(int x, int z)
{
  glm::vec3	A(0, 0, 0);
  glm::vec3	B(0, 0, 0);
  float		or1;

  A.x = 100;
  A.z = 0;
  B.x = x - this->get_x();
  B.z = z - this->get_z();
  if (B.x == 0 && B.z == 0)
    return;
  or1 = glm::orientedAngle(glm::normalize(A), glm::normalize(B), glm::vec3(0, 1, 0));
  this->set_roty(-1 * (or1 + 90));
}

bool	IaBomber::move(glm::vec3 direct)
{
  glm::vec3	posSauv;
  glm::vec3	positionTrans;

  if (this->_map->getTypeMap() == ZOMBIE)
    direct /= 3;
  posSauv = this->_position;
  positionTrans = this->translate(direct);
  if (checkPositionCollisionPlayer() == false)
    {
      this->_position.x -= positionTrans.x;
      if (checkPositionCollisionPlayer() == false)
	{
	  this->_position.x += positionTrans.x;
	  this->_position.z -= positionTrans.z;
	  if (checkPositionCollisionPlayer() == false)
	    {
	      this->_position = posSauv;
	      return false;
	    }
	  else
	    {
	      positionTrans.z = 0;
	      return true;
	    }
	}
      else
	{
	  positionTrans.x = 0;
	  return true;
	}
    }
  else
    return true;
}

int		IaBomber::calcPositionNoRisk(glm::vec2 position, glm::vec2 old, int taille)
{
  int		max;
  int		res;

  max = -1;
  if (isInRisk(position.x, position.y) == false)
    return taille;
  if (old.x != position.x - 3 && _map->isBlock(position.x - 3, position.y, true) == false)
    {
      res = calcPositionNoRisk(glm::vec2(position.x - 3, position.y), position, taille + 1);
      if (max == -1 || (res < max && res > 0))
	max = res;
    }
  if (old.x != position.x + 3 && _map->isBlock(position.x + 3, position.y, true) == false)
    {
      res = calcPositionNoRisk(glm::vec2(position.x + 3, position.y), position, taille + 1);
      if (max == -1 || (res < max && res > 0))
	max = res;
    }
  if (old.y != position.y + 3 &&  _map->isBlock(position.x, position.y + 3, true) == false)
    {
      res = calcPositionNoRisk(glm::vec2(position.x, position.y + 3), position, taille + 1);
      if (max == -1 || (res < max && res > 0))
	max = res;
    }
  if (old.y != position.y - 3 && _map->isBlock(position.x, position.y - 3, true) == false)
    {
      res = calcPositionNoRisk(glm::vec2(position.x, position.y - 3), position, taille + 1);
      if (max == -1 || (res < max && res > 0))
	max = res;
    }
  return max;
}

glm::vec2	IaBomber::getPositionNoRisk()
{
  glm::vec2	result;
  int		x;
  int		y;
  int		max;
  int		res;

  x = (this)->get_x() - ((int)this->get_x() % 3);
  if (x + 1.5 < this->get_x())
    x += 3;
  y = (this)->get_z() - ((int)this->get_z() % 3);
  if (y + 1.5 < this->get_z())
    y += 3;
  max = -1;
  result.x = x;
  result.y = y;
  res = -1;
  if (_map->isBlock(x - 3, y, true) == false)
    {
      if (((res = calcPositionNoRisk(glm::vec2(x - 3, y), glm::vec2(x, y), 1)) < max && res > 0) || max == -1)
	{
	  result.x = x - 3;
	  result.y = y;
	  max = res;
	}
    }
  if (_map->isBlock(x + 3, y, true) == false)
    {
      if (((res = calcPositionNoRisk(glm::vec2(x + 3, y), glm::vec2(x, y), 1)) < max && res > 0) || max == -1)
	{
	  result.x = x + 3;
	  result.y = y;
	  max = res;
	}
    }
  if (_map->isBlock(x, y - 3, true) == false)
    {
      if (((res = calcPositionNoRisk(glm::vec2(x, y - 3), glm::vec2(x, y), 1)) < max && res > 0) || max == -1)
	{
	  result.x = x;
	  result.y = y-3;
	  max = res;
	}
    }
  if (_map->isBlock(x, y + 3, true) == false)
    {
      if (((res = calcPositionNoRisk(glm::vec2(x, y + 3), glm::vec2(x, y), 1)) < max && res > 0) || max == -1)
	{
	  result.x = x ;
	  result.y = y + 3;
	  max = res;
	}
        }
  return result;
}

APlayer	*IaBomber::minDistanceEnemy()
{
  std::list<IaBomber *>	listIa;
  std::list<IaBomber *>::iterator	it;
  int			result;
  APlayer		*resultPlayer;

  result = -1;
  listIa = _map->getIa();
  it = listIa.begin();
  resultPlayer = NULL;
  while (it != listIa.end())
    {
      if ((*it) != this)
	{
	  if (result == -1 || result > _map->distanceObj(*it, this))
	    {
	      result = _map->distanceObj(*it, this);
	      resultPlayer = *it;
	    }
	}
      it++;
    }
  if (result == -1 || result > _map->distanceObj(this))
    {
      result = _map->distanceObj(this);
      resultPlayer = (APlayer *)(_map->getPlayer());
    }
  return resultPlayer;
}

AObjectPhysic	*IaBomber::minDistanceDestruc()
{
  std::vector<AObjectPhysic *>	list;
  std::vector<AObjectPhysic *>::iterator	it;
  int			result;
  AObjectPhysic		*resultBloc;
  int		sauvX;
  int		sauvY;

  sauvX = (this)->get_x() - ((int)this->get_x() % 3);
  if (sauvX + 1.5 < this->get_x())
    sauvX += 3;
  sauvY = (this)->get_z() - ((int)this->get_z() % 3);
  if (sauvY + 1.5 < this->get_z())
    sauvY += 3;
  resultBloc = NULL;
  result = -1;
  list = _map->getObjectsPrecisPos(this, 10000, DESTRUCTWALL);
  it = list.begin();
  while (it != list.end())
    {
      if ((*it) != this)
	{
	  if (result == -1 || result > _map->distanceObj(*it, this))
	    {
	      if ((*it)->get_x() == sauvX || (*it)->get_z() == sauvY)
		{
		  result = _map->distanceObj(*it, this);
		  resultBloc = *it;
		}
	    }
	}
      it++;
    }
  return resultBloc;
}

ABonus	*IaBomber::getBonus(int size)
{
  std::vector<AObjectPhysic *>	list;
  std::vector<AObjectPhysic *>::iterator	it;
  int			result;
  ABonus		*resultBonus;

  result = -1;
  list = _map->getObjectsPos(this, size, BONUS);
  it = list.begin();
  resultBonus = NULL;
  while (it != list.end())
    {
      if ((*it) != this)
	{
	  if (result == -1 || result > _map->distanceObj(*it, this))
	    {
	      resultBonus = (ABonus *)*it;
	      result = _map->distanceObj(*it, this);
	    }
	}
      it++;
    }
  return resultBonus;
}


bool	IaBomber::poseBomb()
{
  DefaultBomb	*bomb;
  int		x;
  int		z;
  time_t	currTime;
  double	second;
  glm::vec2	testNoRisk;
  int		nbr;

  time(&currTime);
  if (this->_nbrBomb <= 0)
    return false;
  if (this->checkPositionCollision(BOMB) != NULL)
    return false;
  second = difftime(currTime, _timeBomb);
  if (second < 7)
    return true;
  time(&_timeBomb);
  x = (int)this->get_x() - ((int)this->get_x() % 3);
  if (x + 1.5 < this->get_x())
    x += 3;
  z = (int)this->get_z() - ((int)this->get_z() % 3);
  if (z + 1.5 < this->get_z())
    z += 3;
  testNoRisk = getPositionNoRisk();
  if (testNoRisk.x == x && testNoRisk.y == z)
    return true;
  nbr = 0;
  if (_map->isBlock(x - 3, z) == false)
    nbr += 1;
  if (_map->isBlock(x + 3, z) == false)
    nbr += 1;
  if (_map->isBlock(x , z - 3) == false)
    nbr += 1;
  if (_map->isBlock(x, z + 3) == false)
    nbr += 1;
  if (nbr < 3)
    return true;
  this->_nbrBomb--;
  bomb = new DefaultBomb(_map, _modelList, _event, this, _clock);
  bomb->setPo(this->_po);
  x = (int)this->_position.x;
  z = (int)this->_position.z;
  while (x % 3 != 0)
    x++;
  while (z % 3 != 0)
    z++;
  bomb->set_x(x);
  bomb->set_z(z);
  this->_map->setBomb(bomb);
  return true;
}

bool	IaBomber::isInRisk(int x, int z)
{
  std::list<AFire *>		listFire;
  std::list<AFire *>::iterator	itF;
  std::list<ABomb *>		list;
  std::list<ABomb *>::iterator	it;
  int				xB;
  int				zB;
  int				i;
  int				ok;

  if (x == -1 || z == -1)
    {
      x = (int)this->get_x() - ((int)this->get_x() % 3);
      if (x + 1.5 < this->get_x())
	{
	  x += 3;
	}
      z = (int)this->get_z() - ((int)this->get_z() % 3);
      if (z + 1.5 < this->get_z())
	z += 3;
    }
  list = this->_map->getBombs();
  it = list.begin();
  while (it != list.end())
    {
      xB = (int)(*it)->get_x();
      zB = (int)(*it)->get_z();
      if (xB == x && zB == z)
	return true;
      if (xB == x)
	{
	  if (std::max(zB, z) - std::min(zB, z) <= (*it)->getPo() * 3)
	    {
	      ok = 0;
	      i = std::min(zB, z);
	      while (i <= std::max(zB, z))
		{
		  if (_map->isBlock(x, i) == true)
		    ok = 1;
		  i++;
		}
	      if (ok == 0)
		return true;
	    }
	}
      else if (zB == z)
	{
	  if (std::max(xB, x) - std::min(xB, x) <= (*it)->getPo() * 3)
	    {
	      ok = 0;
	      i = std::min(xB, x);
	      while (i <= std::max(xB, x))
		{
		  if (_map->isBlock(i, z) == true)
		    ok = 1;
		  i++;
		}
	      if (ok == 0)
		return true;
	    }
	}
      it++;
    }
  listFire = this->_map->getFire();
  itF = listFire.begin();
  while (itF != listFire.end())
    {
      xB = (int)(*itF)->get_x();
      zB = (int)(*itF)->get_z();
      if (xB == x && zB == z)
      	return true;
      itF++;
    }
  return false;
}

void	IaBomber::getList()
{
  std::string file;
  if (_map->getTypeMap() == NORMAL)
    file = "ia/ia.xml";
  else
    file = "ia/zombie.xml";
  TiXmlDocument	doc(file);
  bool CheckFile = doc.LoadFile();

  if (!CheckFile)
    std::cerr << "LOAD OF FILE IA NOT FOUND" << std::endl;
  TiXmlElement	*_ia;
  _ia = doc.FirstChildElement("ia");
  if (_ia == NULL)
    std::cout << "BALISE <ia> not found" << std::endl;
  TiXmlElement	*_action;
  _action = _ia->FirstChildElement("action");
  while (_action)
    {
      std::string name(_action->Attribute("name"));
      int condition = atoi(_action->Attribute("condition"));
      std::string action(_action->Attribute("action"));
      _IaX = new IaXml;
      _IaX->name = name;
      _IaX->condition = condition;
      _IaX->action = action;
      listXml.push_back(_IaX);
      _action = _action->NextSiblingElement("action");
    }
}

bool		IaBomber::update(gdl::Clock const &clock, gdl::Input &input)
{
  std::list<IaXml *>::iterator	it;
  int		elenczk;
  glm::vec2	target;

  (void)clock;
  (void)input;
  if (this->getLife() <= 0)
    return false;
  if (this->_map->getTypeMap() == NORMAL && this->_positionTo.x != -1)
    {
      target = getChemin(_positionTo.x, _positionTo.y);
      changeRot(target.x, target.y);
      this->move(glm::vec3(0, 0, -0.5));
      if (glm::distance2(_position, glm::vec3(_positionTo.x, 0, _positionTo.y)) < 1)
	_positionTo.x = -1;
    }
  it = listXml.begin();
  while (it != listXml.end())
    {
      elenczk = (this->*_mapName[(*it)->name])();
      if (elenczk >= 0 && elenczk <= (*it)->condition)
	{
	  if (((this->*_mapAction[(*it)->action])()) ==  true)
	    return true;
	}
      it++;
    }
  return true;
}
