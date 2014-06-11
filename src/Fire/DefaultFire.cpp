//
// DefaultFire.cpp for DefautlFire in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 04:00:03 2014 Remi telenczak
// Last update Wed Jun 11 15:14:12 2014 Remi telenczak
//

#include	"DefaultFire.hpp"
#include	"ModelList.hpp"
#include	"Map.hpp"
#include	"ABomb.hpp"
#include	"ABonus.hpp"

DefaultFire::DefaultFire(Map *map, ModelList *model, EventManager *event, std::vector<APlayer *> *playerTouched, gdl::Clock *clock, int idBomb) : AFire(map, model, event, playerTouched, clock, idBomb)
{
  this->_skin = _modelList->getModel("fire");
  this->scale(glm::vec3(0.5, 0.5, 0.5));
  this->_skin->createSubAnim(0, "while", 15, 15);
  this->_skin->setCurrentSubAnim("while", false);
  this->_typePrecis = FIREPRECIS;
}

DefaultFire::~DefaultFire()
{
  std::cout << "ON DELETE FIRE" << std::endl;
}

bool	DefaultFire::update(gdl::Clock const &clock, gdl::Input &input)
{
  time_t currTime;
  ABomb *bomb;
  ABonus *bonus;

  time(&currTime);
  this->checkPlayerColl();
  if ((bomb = (ABomb *)this->checkPositionCollision(BOMB)) != NULL)
    bomb->explode();
  if ((bonus = (ABonus *)this->checkPositionCollision(BONUS)) != NULL)
    bonus->fireTouch();
  this->_time -= (clock.getElapsed() * 1000);
  if (0 >= this->_time)
    return false;
  return true;
  (void)clock;
  (void)input;
}
