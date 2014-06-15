//
// SettingBoxIG.cpp for SettingsBoxIG in /home/mendez_t/local/cpp/cpp_bomberman/src/Bloc
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 04:34:50 2014 thomas mendez
// Last update Sun Jun 15 23:28:15 2014 dedicker remi
//

#include	<iostream>
#include	"SettingBoxIG.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

SettingBoxIG::SettingBoxIG(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock, int i) : ABloc(map, model, event, clock)
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
  callRotOcu = new CallBack<SettingBoxIG>(this, &SettingBoxIG::eventRotOcu);
  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	SettingBoxIG::getRotation()
{
  return this->rot;
}

int		SettingBoxIG::getRotationy()
{
  return this->rot->y;
}

void	SettingBoxIG::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  newpos = this->posSauv;
  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  this->rot = (glm::vec3 *)data;
}

bool SettingBoxIG::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_i == 1 && this->posSauv.z > -10)
    {
      this->posSauv.z -= 0.13;
    }
  (void)clock;
  (void)input;
  return true;
}

bool SettingBoxIG::fireTouch()
{
  return true;
}
