//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Fri May 16 05:05:03 2014 Remi telenczak
//

#include	"DefaultWall.hpp"
#include	"ModelList.hpp"

DefaultWall::DefaultWall(Map *map, ModelList *model, EventManager *event) : ABloc(map, model, event)
{
  this->_skin = model->getModel("cube1");
  this->_height = 2;
  this->_width = 2;
}

void DefaultWall::update(gdl::Clock const &clock, gdl::Input &input)
{

}
