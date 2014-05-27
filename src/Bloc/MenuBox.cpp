//
// MenuBox.cpp for MenuBox.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Tue May 27 16:24:35 2014 dedicker remi
//

#include	"MenuBox.hpp"
#include	"ModelList.hpp"

MenuBox::MenuBox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("menu");
  this->_height = 3;
  this->_width = 3;
  this->set_z(-10);
  this->set_y(0);
  this->set_x(5);
}

bool MenuBox::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  return true;
}

bool MenuBox::fireTouch()
{
  return true;
}
