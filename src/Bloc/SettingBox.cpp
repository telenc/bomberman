//
// SettingBox.cpp for SettingBox.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Sun Jun 15 23:27:40 2014 dedicker remi
//

#include	<iostream>
#include	"SettingBox.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

SettingBox::SettingBox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock, int i) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("box_setting");
  this->_height = 10;
  this->_width = 10;
  this->set_z(-10);
  this->set_y(0);
  this->set_x(0);
  this->_i = i;
  this->_position.z = -1;
  this->posSauv.z = -4.5;
  callRotOcu = new CallBack<SettingBox>(this, &SettingBox::eventRotOcu);
  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	SettingBox::getRotation()
{
  return this->rot;
}

int		SettingBox::getRotationy()
{
  return this->rot->y;
}

void	SettingBox::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  newpos = this->posSauv;
  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  this->rot = (glm::vec3 *)data;

}

bool SettingBox::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_i == 1 && this->posSauv.z > -10)
    {
      this->posSauv.z -= 0.13;
    }
  (void)clock;
  (void)input;
  return true;
}

bool SettingBox::fireTouch()
{
  return true;
}
