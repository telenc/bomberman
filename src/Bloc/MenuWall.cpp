//
// MenuWall.cpp for MenuWall.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Tue May 27 15:46:26 2014 dedicker remi
//

#include	"MenuWall.hpp"
#include	"ModelList.hpp"

MenuWall::MenuWall(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("box_menu");
  this->_height = 3;
  this->_width = 3;
}

bool MenuWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  return true;
}
