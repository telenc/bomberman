//
// MenuBox.cpp for MenuBox.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Tue May 27 17:49:44 2014 dedicker remi
//

#include	<iostream>
#include	"MenuBox.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

MenuBox::MenuBox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("menu");
  this->_height = 10;
  this->_width = 10;
  this->set_z(0);
  this->set_y(0);
  this->set_x(0);
  callRotOcu = new CallBack<MenuBox>(this, &MenuBox::eventRotOcu);
  event->listenEvent("rotOcu", callRotOcu);
}

void	MenuBox::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  //data.z = 0;
  //  newpos = glm::rotate(newpos, data);
  newpos = glm::rotateY(newpos, rotation->y);
  newpos = glm::rotateX(newpos, rotation->x);
  //  newpos = glm::rotateZ(newpos, rotation->z);
  this->_position = newpos;
  std::cout << rotation->y << std::endl;
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
