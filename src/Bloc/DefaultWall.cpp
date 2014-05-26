//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
<<<<<<< HEAD
// Last update Mon May 26 08:26:48 2014 Remi telenczak
=======
// Last update Mon May 26 16:43:12 2014 dedicker remi
>>>>>>> 86fd066f3cca2a094e91194976398fe97236bc1e
//

#include	"DefaultWall.hpp"
#include	"ModelList.hpp"

DefaultWall::DefaultWall(Map *map, ModelList *model, EventManager *event) : ABloc(map, model, event)
{
  this->_skin = model->getModel("cube6");
  this->_height = 3;
  this->_width = 3;
}

bool DefaultWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  //  this->_skin->setCurrentAnim(22);
  (void)clock;
  (void)input;
  return true;
}

bool DefaultWall::fireTouch()
{
  return true;
}
