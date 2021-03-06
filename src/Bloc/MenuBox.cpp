//
// MenuBox.cpp for MenuBox.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Fri Jun 13 16:59:19 2014 thomas mendez
//

#include	<iostream>
#include	"MenuBox.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

MenuBox::MenuBox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock, int i) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("menu");
  this->_height = 10;
  this->_width = 10;
  this->set_z(0);
  this->set_y(0);
  this->set_x(0);
  this->_i = i;
  if (i == 1)
    {
      this->_position.z = -1;
      this->posSauv.z = -4.5;
      callRotOcu = new CallBack<MenuBox>(this, &MenuBox::eventRotOcu);
    }
  else if (i == 2)
    callRotOcu = new CallBack<MenuBox>(this, &MenuBox::eventRotOcu2);    
  else
    callRotOcu = new CallBack<MenuBox>(this, &MenuBox::eventRotOcu3);
  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	MenuBox::getRotation()
{
  return this->rot;
}

int		MenuBox::getRotationy()
{
  return this->rot->y;
}

void	MenuBox::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  newpos = this->posSauv;
  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  this->rot = (glm::vec3 *)data;
}

void	MenuBox::eventRotOcu2(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 10, 0);
  this->_position = newpos;
  (void)rotation;
  this->rot = (glm::vec3 *)data;
}

void	MenuBox::eventRotOcu3(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, -10, 0);
  this->_position = newpos;
  (void)rotation;
  this->rot = (glm::vec3 *)data;
}

bool MenuBox::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_i == 1 && this->posSauv.z > -10)
    {
      this->posSauv.z -= 0.13;
    }
  (void)clock;
  (void)input;
  return true;
}

bool MenuBox::fireTouch()
{
  return true;
}
