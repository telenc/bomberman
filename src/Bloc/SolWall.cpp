//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Sun Jun 15 19:01:44 2014 Remi telenczak
//

#include	"SolWall.hpp"
#include	"ModelList.hpp"
#include	"Map.hpp"

SolWall::SolWall(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock)
{
  if (map->getTypeMap() == ZOMBIE)
    this->_skin = model->getModel("zombieFloor");
  else
    this->_skin = model->getModel("sol");
  this->_height = 3;
  this->_width = 3;
  this->_typePrecis = SOLWALL;
}

bool SolWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  return true;
}

bool SolWall::fireTouch()
{
  return true;
}
