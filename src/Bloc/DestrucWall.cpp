//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Mon May 26 08:26:30 2014 Remi telenczak
//

#include	"DestrucWall.hpp"
#include	"ModelList.hpp"

DestrucWall::DestrucWall(Map *map, ModelList *model, EventManager *event) : ABloc(map, model, event), AObjectLife(3)
{
  this->_skin = model->getModel("cubeDest3");
  this->_height = 3;
  this->_width = 3;
}

bool DestrucWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_life >= 3 && this->_life > 0)
    this->_skin = _modelList->getModel("cubeDest3");
  else if (this->_life == 2)
    this->_skin = _modelList->getModel("cubeDest2");
  else
    this->_skin = _modelList->getModel("cubeDest1");
  (void)clock;
  (void)input;
  if (this->_life <= 0)
    return false;
  return true;
}

bool	DestrucWall::fireTouch()
{
  std::cout << "WASAAA" << std::endl;
  this->decLife();
  if (this->_life <= 0)
    return false;
  return true;
}
