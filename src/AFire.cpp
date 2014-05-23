//
// AFire.cpp for AFire in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:51:01 2014 Remi telenczak
// Last update Fri May 23 07:08:17 2014 Remi telenczak
//

#include	"AFire.hpp"
#include	"Map.hpp"

AFire::AFire(Map *map, ModelList *model, EventManager *event) : AObjectPhysic(map, model, event), _damage(1)
{
  this->_type = FIRE;
  this->_time = 1000;
  time(&this->_timeCreate);
}

AFire::~AFire()
{

}

AObjectPhysic	*AFire::checkPositionCollision(TypeObject type)
{
  std::vector<AObjectPhysic *>	objects;
  std::vector<AObjectPhysic *>::iterator	it;
  objects = this->_map->getObjectsPos(this);
  it = objects.begin();

  while (it != objects.end())
    {
      if (this->collision(*it) == true)
	{
	  if (type == NONE)
	    return (*it);
	  else if ((*it)->getType() == type)
	    return (*it);
	  //this->_map->deleteObject(this);
	}
      it++;
    }
  return NULL;
}

void	AFire::setTime(int time)
{
  this->_time = time;
}

int	AFire::getTime(void) const
{
  return this->_time;
}

void	AFire::setDamage(int damage)
{
  this->_damage = damage;
}

int	AFire::getDamage(void) const
{
  return this->_damage;
}
