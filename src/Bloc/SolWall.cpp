//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Tue May 27 03:10:46 2014 Remi telenczak
//

#include	"SolWall.hpp"
#include	"ModelList.hpp"

SolWall::SolWall(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("sol");
  this->_height = 3;
  this->_width = 3;
  std::cout << "WALL " << std::endl;
}

bool SolWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  //  this->_skin->setCurrentAnim(22);
  (void)clock;
  (void)input;
  return true;
}

bool SolWall::fireTouch()
{
  return true;
}
