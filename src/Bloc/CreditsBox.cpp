//
// CreditsBox.cpp for CreditsBox in /home/mendez_t/local/cpp/cpp_bomberman/src/Bloc
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Fri Jun 13 15:14:48 2014 thomas mendez
// Last update Fri Jun 13 16:57:15 2014 thomas mendez
//

#include	<iostream>
#include	"CreditsBox.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

CreditsBox::CreditsBox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock, int i) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("box_credits");
  this->_height = 10;
  this->_width = 10;
  this->set_z(-10);
  this->set_y(0);
  this->set_x(0);
  this->_i = i;
  this->_position.z = -1;
  this->posSauv.z = -4.5;
  if (i == 1)
    {
      this->_position.z = -1;
      this->posSauv.z = -4.5;
  callRotOcu = new CallBack<CreditsBox>(this, &CreditsBox::eventRotOcu);
    }
  else if (i == 2)
  callRotOcu = new CallBack<CreditsBox>(this, &CreditsBox::eventRotOcu2);
  else
  callRotOcu = new CallBack<CreditsBox>(this, &CreditsBox::eventRotOcu3);
  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	CreditsBox::getRotation()
{
  return this->rot;
}

int		CreditsBox::getRotationy()
{
  return this->rot->y;
}

void	CreditsBox::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  newpos = this->posSauv;
  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  this->rot = (glm::vec3 *)data;
}

void	CreditsBox::eventRotOcu2(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 10, 0);
  this->_position = newpos;
  (void)rotation;
  this->rot = (glm::vec3 *)data;
}

void	CreditsBox::eventRotOcu3(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, -10, 0);
  this->_position = newpos;
  (void)rotation;
  this->rot = (glm::vec3 *)data;
}

bool CreditsBox::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_i == 1 && this->posSauv.z > -10)
    {
      this->posSauv.z -= 0.13;
    }
  (void)clock;
  (void)input;
  return true;
}

bool CreditsBox::fireTouch()
{
  return true;
}
