//
// MenuWall.cpp for MenuWall.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
// 
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
// 
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Mon May 26 17:18:13 2014 dedicker remi
//

#include	"MenuWall.hpp"
#include	"ModelList.hpp"

MenuWall::MenuWall(Map *map, ModelList *model, EventManager *event) : ABloc(map, model, event)
{
  this->_skin = model->getModel("box_menu");
  this->_height = 3;
  this->_width = 3;
}

bool MenuWall::update(gdl::Clock const &clock, gdl::Input &input)
{
  //  this->_skin->setCurrentAnim(22);
  (void)clock;
  (void)input;
  return true;
}
