//
// MenuBox.cpp for MenuBox.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Sun Jun 15 17:50:31 2014 dedicker remi
//

#include	<iostream>
#include	"MenuBoxIG.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

MenuBoxIG::MenuBoxIG(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock, int i) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("box_menuig");
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
      callRotOcu = new CallBack<MenuBoxIG>(this, &MenuBoxIG::eventRotOcu);
    }
  else if (i == 2)
    callRotOcu = new CallBack<MenuBoxIG>(this, &MenuBoxIG::eventRotOcu2);    
  else
    callRotOcu = new CallBack<MenuBoxIG>(this, &MenuBoxIG::eventRotOcu3);
  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	MenuBoxIG::getRotation()
{
  return this->rot;
}

int		MenuBoxIG::getRotationy()
{
  return this->rot->y;
}

void	MenuBoxIG::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  newpos = this->posSauv;
  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  this->rot = (glm::vec3 *)data;
}

void	MenuBoxIG::eventRotOcu2(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 10, 0);
  this->_position = newpos;
  (void)rotation;
  this->rot = (glm::vec3 *)data;
}

void	MenuBoxIG::eventRotOcu3(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, -10, 0);
  this->_position = newpos;
  (void)rotation;
  this->rot = (glm::vec3 *)data;
}

bool MenuBoxIG::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_i == 1 && this->posSauv.z > -10)
    {
      this->posSauv.z -= 0.13;
    }
  (void)clock;
  (void)input;
  return true;
}

bool MenuBoxIG::fireTouch()
{
  return true;
}
