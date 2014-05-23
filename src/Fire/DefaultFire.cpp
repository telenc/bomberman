//
// DefaultFire.cpp for DefautlFire in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 04:00:03 2014 Remi telenczak
// Last update Fri May 23 05:49:12 2014 Remi telenczak
//

#include	"DefaultFire.hpp"
#include	"ModelList.hpp"
#include	"Map.hpp"

DefaultFire::DefaultFire(Map *map, ModelList *model, EventManager *event) : AFire(map, model, event)
{
  this->_skin = _modelList->getModel("fire");
  this->scale(glm::vec3(0.5, 0.5, 0.5));
  //this->_skin->createSubAnim(0, "start", 0, 15);
  this->_skin->createSubAnim(0, "while", 15, 15);
  //this->_skin->createSubAnim(2, "end", 22, 31);
  this->_skin->setCurrentSubAnim("while", false);
}

void	DefaultFire::update(gdl::Clock const &clock, gdl::Input &input)
{
  time_t currTime;

  time(&currTime);
  if (difftime(currTime, this->_timeCreate) * 1000 >= this->_time)
    {
      this->_map->deleteObject(this);
    }



  (void)clock;
  (void)input;
}
