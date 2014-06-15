//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Sun Jun 15 19:06:02 2014 Remi telenczak
//

#include	"DefaultWall.hpp"
#include	"ModelList.hpp"

DefaultWall::DefaultWall(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("cube6");
  this->_height = 3;
  this->_width = 3;
  this->_typePrecis = DEFAULTWALL;
}

bool DefaultWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  return true;
}

bool DefaultWall::fireTouch()
{
  return true;
}
