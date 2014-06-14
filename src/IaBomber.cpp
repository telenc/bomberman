/*
// Ia.cpp for Ia in /home/telenc_r/cpp_bomberman
//
// Made by Remi telenczak
// Login   <telenc_r@epitech.net>
//
// Started on  Fri Jun 13 12:28:13 2014 Remi telenczak
<<<<<<< HEAD
// Last update Sun Jun 15 01:36:54 2014 Remi telenczak
=======
// Last update Sat Jun 14 22:46:18 2014 Steven Martreux
>>>>>>> 544762e450695e0c4ec2a6538d654c8ff41a9e16
*/

#include	"IaBomber.hpp"
#include	"EventManager.hpp"
#include	"DefaultBomb.hpp"
#include	"ABonus.hpp"
#include	"AFire.hpp"

IaBomber::IaBomber(int x, int y, int z, Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : APlayer(x, y, z, map, model, event, clock)
{
  std::cout << "Ia created" << std::endl;
  this->getList();
  this->set_x(x);
  this->set_z(z);
  this->set_roty(90);

  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("isInRisk", &IaBomber::isInRiskIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("enemyDistance", &IaBomber::enemyDistanceIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("wallDistance", &IaBomber::wallDistanceIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("bonusDistance", &IaBomber::bonusDistanceIa));
  _mapName.insert(std::pair<std::string, int (IaBomber::*)()>("enemyNear", &IaBomber::enemyNearIa));

  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goSafe", &IaBomber::goSafeIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("poseBomb", &IaBomber::poseBombIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goBonus", &IaBomber::goBonusIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goWall", &IaBomber::goWallIa));
  _mapAction.insert(std::pair<std::string, bool (IaBomber::*)()>("goEnemyNear", &IaBomber::goEnemyNearIa));
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
  //std::cout << "Return -1" << std::endl;
  return -1;
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
    {
      std::cout << "Go wall !!!" << std::endl;
    return _map->distanceObj(result, this);
    }
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

bool	IaBomber::goSafeIa()
{
  glm::vec2	target;

  target = getPositionNoRisk();
  changeRot(target.x, target.y);
  this->_positionTo.x = target.x;
  this->_positionTo.y = target.y;
  this->move(glm::vec3(0, 0, -0.5));
  return true;
}

bool	IaBomber::poseBombIa()
{
  DefaultBomb	*bomb;
  int		x;
  int		z;
  glm::vec3 t;

  if (this->_nbrBomb <= 0)
    return false;
  if (this->checkPositionCollision(BOMB) != NULL)
    return false;
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
  t.x = x;
  t.y  = 0;
  t.z = z;
  _event->dispatchEvent("bombDrop", &(t));
  this->_map->setBomb(bomb);
  return true;
}

bool	IaBomber::goBonusIa()
{
  ABonus	*result;

  result = this->getBonus(100);
  changeRot(result->get_x(), result->get_z());
  this->_positionTo.x = result->get_x();
  this->_positionTo.y = result->get_z();
  this->move(glm::vec3(0, 0, -0.5));
  return true;
}

bool	IaBomber::goWallIa()
{
  AObjectPhysic	*result;

  result = this->minDistanceDestruc();
  changeRot(result->get_x(), result->get_z());
  this->_positionTo.x = result->get_x();
  this->_positionTo.y = result->get_z();
  this->move(glm::vec3(0, 0, -0.5));
  return true;
}

bool	IaBomber::goEnemyNearIa()
{
   APlayer	*result;

  result = this->minDistanceEnemy();
  if (result)
    {
      changeRot(result->get_x(), result->get_z());
      this->_positionTo.x = result->get_x();
      this->_positionTo.y = result->get_z();
      this->move(glm::vec3(0, 0, -0.5));
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

  if (x == 0 && z == 0)
    return;
  or1 = glm::orientedAngle(glm::normalize(A), glm::normalize(B), glm::vec3(0, 1, 0));
  this->set_roty(-1 * (or1 + 90));
}

bool	IaBomber::move(glm::vec3 direct)
{
  glm::vec3	posSauv;
  glm::vec3	positionTrans;

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

glm::vec2	IaBomber::getPositionNoRisk()
{
  glm::vec2	position;
  int		x;
  int		y;
  int		sauvX;
  int		sauvY;
  int		decal;
  int		end;

  end = 0;
  decal = 1;
  //std::cout << "On est en risk" << std::endl;
  while (1)
    {
      sauvX = (this)->get_x() - ((int)this->get_x() % 3);
      //if (sauvX + 1.5 < this->get_x())
      //	sauvX += 3;
      sauvY = (this)->get_z() - ((int)this->get_z() % 3);
      //if (sauvY += 1.5 < this->get_z())
      //	sauvY += 3;
      x = sauvX;
      y = sauvY;
      x -= (decal * 3);
      if (x < 0 && sauvX + (decal * 3) > _map->getWidth() * 3)
	{
	  position.x = this->get_x();
	  position.y = this->get_y();
	}
      while (x < sauvX + (decal * 3))
	{
	  y = sauvY - (decal * 3);
	  while (y < sauvY + (decal * 3))
	    {
	      //std::cout << "On check " << x << "/" << y << std::endl;
	      if (x > 0 && y > 0 && x < _map->getWidth() * 3 && y < _map->getHeight() * 3 &&  _map->isBlock(x, y) == false && isInRisk(x, y) == false)
		{
		  if (end == 1)
		    {
		      if (std::max((int)this->get_x(), (int)x) - std::min((int)this->get_x(),(int) x) + std::max((int)this->get_y(),(int) y) - std::min((int)this->get_y(),(int) y) < std::max((int)position.x, (int)this->get_x()) - std::min((int)position.x, (int)this->get_x()) + std::max((int)position.y, (int)this->get_y()) - std::min((int)position.y,(int) this->get_y()))
			{
			  position.x = x;
			  position.y = y;
			}

		    }
		  else
		    {
		      position.x = x;
		      position.y= y;
		    }
		  end = 1;

		}
	      y += 3;
	    }
	  x += 3;
	}
      if (end == 1)
	{
	  //std::cout << "Return " << x << "/" << y << std::endl;
	  //std::cout << "this " << this->get_x() << "/" << this->get_y() << std::endl;
	  return position;
	}
      decal++;
    }
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
	      result = _map->distanceObj(*it, this);
	      resultBloc = *it;
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

  if (this->_nbrBomb <= 0)
    return false;
  if (this->checkPositionCollision(BOMB) != NULL)
    return false;
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
  glm::vec3 t;
  t.x = x;
  t.y  = 0;
  t.z = z;
  _event->dispatchEvent("bombDrop", &(t));
  this->_map->setBomb(bomb);
  return true;
}

bool	IaBomber::isInRisk(int x, int z)
{
  std::list<AFire *>	listFire;
  std::list<AFire *>::iterator	itF;
  std::list<ABomb *>	list;
  std::list<ABomb *>::iterator	it;
  int xB;
  int zB;

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
      if (xB == x)
	{
	  if (std::max(zB, z) - std::min(zB, z) <= (*it)->getPo() * 3)
	    return true;
	}
      else if (zB == z)
	{
	  if (std::max(xB, x) - std::min(xB, x) <= (*it)->getPo() * 3)
	    return true;
	}
      it++;
    }
  listFire = this->_map->getFire();
  itF = listFire.begin();
  while (itF != listFire.end())
    {
      xB = (int)(*itF)->get_x();
      zB = (int)(*itF)->get_z();
      std::cout << xB << "/" << zB << "   " << x << "//" << z << std::endl;
      if (xB == x)
	return true;
      else if (zB == z)
	return true;
      itF++;
    }
  return false;
}

void	IaBomber::getList()
{
  TiXmlDocument	doc("ia.xml");
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

  (void)clock;
  (void)input;
  if (this->_positionTo.x != -1)
    {
      //std::cout << _positionTo.x << "//////" << _positionTo.y << std::endl;
      changeRot(_positionTo.x, _positionTo.y);
      this->move(glm::vec3(0, 0, -0.5));
      if (glm::distance2(_position, glm::vec3(_positionTo.x, 0, _positionTo.y)) < 5)
	_positionTo.x = -1;
    }
  //if (this->_life <= 0)
  //  std::cout << "Ia mort " << std::endl;
  it = listXml.begin();
  while (it != listXml.end())
    {
      elenczk = (this->*_mapName[(*it)->name])();
      if (elenczk >= 0 && elenczk <= (*it)->condition)
	{
	  std::cout << (*it)->name << std::endl;
	  //std::cout << "Elezenc " << elenczk << "   " << (*it)->condition<< std::endl;
	  if (((this->*_mapAction[(*it)->action])()) ==  true)
	      return true;
	}
      it++;
    }
  return true;
}
