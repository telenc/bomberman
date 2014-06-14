/*
// Ia.cpp for Ia in /home/telenc_r/cpp_bomberman
//
// Made by Remi telenczak
// Login   <telenc_r@epitech.net>
//
// Started on  Fri Jun 13 12:28:13 2014 Remi telenczak
// Last update Sat Jun 14 18:16:17 2014 Remi telenczak
*/

#include		"Ia.hpp"
#include	"EventManager.hpp"
#include	"DefaultBomb.hpp"
#include	"ABonus.hpp"

Ia::Ia(int x, int y, int z, Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : APlayer(x, y, z, map, model, event, clock)
{
  std::cout << "Ia created" << std::endl;
  this->set_x(x);
  this->set_z(z);
    this->set_roty(90);
  _mapName.insert(std::pair<std::string, int (Ia::*)()>("isInRisk", &Ia::isInRiskIa));
  _mapName.insert(std::pair<std::string, int (Ia::*)()>("enemyDistance", &Ia::enemyDistanceIa));
  _mapName.insert(std::pair<std::string, int (Ia::*)()>("wallDistance", &Ia::wallDistanceIa));
  _mapName.insert(std::pair<std::string, int (Ia::*)()>("bonusDistance", &Ia::bonusDistanceIa));
  _mapName.insert(std::pair<std::string, int (Ia::*)()>("enemyNear", &Ia::enemyNearIa));

  _mapAction.insert(std::pair<std::string, bool (Ia::*)()>("goSafe", &Ia::goSafeIa));
  _mapAction.insert(std::pair<std::string, bool (Ia::*)()>("poseBomb", &Ia::poseBombIa));
  _mapAction.insert(std::pair<std::string, bool (Ia::*)()>("goBonus", &Ia::goBonusIa));
  _mapAction.insert(std::pair<std::string, bool (Ia::*)()>("goWall", &Ia::goWallIa));
  _mapAction.insert(std::pair<std::string, bool (Ia::*)()>("goEnemyNear", &Ia::goEnemyNearIa));
  this->changeRot(0, 1);
}

Ia::~Ia()
{

}

int	Ia::isInRiskIa()
{
  if (this->isInRisk() == true)
    return 1;
  return 0;
}

int	Ia::enemyDistanceIa()
{
  APlayer	*result;

  result = this->minDistanceEnemy();
  if (result)
    return _map->distanceObj(result, this);
  return -1;
}

int	Ia::wallDistanceIa()
{
  AObjectPhysic	*result;

  result = this->minDistanceDestruc();
  if (result)
    return _map->distanceObj(result, this);
  return -1;
}

int	Ia::bonusDistanceIa()
{
  ABonus	*result;

  result = this->getBonus(1000);
  if (result)
    return _map->distanceObj(result, this);
  return -1;
}

int	Ia::enemyNearIa()
{
  APlayer	*result;

  result = this->minDistanceEnemy();
  if ( _map->distanceObj(result, this) < 30)
    return 1;
  return 0;
}

bool	Ia::goSafeIa()
{
  return true;
}

bool	Ia::poseBombIa()
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

bool	Ia::goBonusIa()
{
  return true;
}

bool	Ia::goWallIa()
{
  return true;
}

bool	Ia::goEnemyNearIa()
{
  return true;
}

void	Ia::changeRot(int x, int z)
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

bool	Ia::move(glm::vec3 direct)
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

glm::vec2	Ia::getPositionNoRisk()
{
  glm::vec2	position;
  int		x;
  int		y;
  int		sauvX;
  int		sauvY;
  int		decal;

  decal = 1;
  while (1)
    {
      sauvX = (this)->get_x() - ((int)this->get_x() % 3);
      sauvY = (this)->get_z() - ((int)this->get_z() % 3);
      x = (this)->get_x() - ((int)this->get_x() % 3);
      y = (this)->get_z() - ((int)this->get_z() % 3);
      x -= (decal * 3);
      if (x < 0 && sauvX + (decal * 3) > _map->getWidth())
	{
	  position.x = this->get_x();
	  position.y = this->get_y();
	}
      while (x < sauvX + (decal * 3))
	{

	  y = sauvY - (decal * 3);
	  while (y < sauvY + (decal * 3))
	    {
	      if (_map->isBlock(x, y) == false && isInRisk(x, y) == false)
		{
		  position.x = x;
		  position.y= y;
		  return position;
		}
	      y += 3;
	    }
	  x += 3;
	}
      decal++;
    }
}

APlayer	*Ia::minDistanceEnemy()
{
  std::list<Ia *>	listIa;
  std::list<Ia *>::iterator	it;
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
      resultPlayer = *it;
    }
  return resultPlayer;
}

AObjectPhysic	*Ia::minDistanceDestruc()
{
  std::vector<AObjectPhysic *>	list;
  std::vector<AObjectPhysic *>::iterator	it;
  int			result;
  AObjectPhysic		*resultBloc;

  resultBloc = NULL;
  result = -1;
  list = _map->getObjectsPrecisPos(this, 100, DESTRUCTWALL);
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

ABonus	*Ia::getBonus(int size)
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


bool	Ia::poseBomb()
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

bool	Ia::isInRisk(int x, int z)
{
  std::list<ABomb *>	list;
  std::list<ABomb *>::iterator	it;
  int xB;
  int zB;

  if (x == -1 || z == -1)
    {
      x = (int)this->get_x() - ((int)this->get_x() % 3);
      z = (int)this->get_z() - ((int)this->get_z() % 3);
    }
  list = this->_map->getBombs();
  it = list.begin();
  while (it != list.end())
    {
      xB = (int)(*it)->get_x();
      zB = (int)(*it)->get_z();
      if (xB == x)
	{
	  if (std::max(zB, z) - std::min(zB, z) < (*it)->getPo() * 3)
	    return true;
	}
      else if (zB == z)
	{
	  if (std::max(xB, x) - std::min(xB, x) < (*it)->getPo() * 3)
	    return true;
	}
      it++;
    }
  return false;
}

bool	Ia::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  return true;
}
