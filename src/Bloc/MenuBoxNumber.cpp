//
// defaultWall.cpp for dede in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:26:53 2014 Remi telenczak
// Last update Tue Jun 10 16:55:05 2014 thomas mendez
//

#include	"MenuBoxNumber.hpp"
#include	"ModelList.hpp"

MenuBoxNumber::MenuBoxNumber(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : ABloc(map, model, event, clock)
{
  this->_skin = model->getModel("menu1");
  this->_height = 3;
  this->_died = false;
  this->_width = 3;
  this->_ytarget = 0;
  this->_position.z = -25;
  this->menu1 = model->getModel("menu1");
  this->menu2 = model->getModel("menu2");
  this->menu3 = model->getModel("menu3");
  this->menu4 = model->getModel("menu4");
}

void	MenuBoxNumber::goDelete()
{
  this->_ytarget = -20;
}

bool MenuBoxNumber::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_died == true || this->get_y() <=  -18)
    {
      return false;
    }
  //std::cout << this->get_y() << std::endl;;
  if (this->_ytarget != this->get_y())
    {
      this->translate(glm::vec3(0, (this->_ytarget - this->get_y()) / 10, 0));
    }
  else
    {
      this->set_y(0);
    }
  if (this->_targetRot < this->get_rotx())
    {
      this->rotate(glm::vec3(1, 0, 0), -3);
    }
  else if (this->_targetRot > this->get_rotx())
    {
      this->rotate(glm::vec3(1, 0, 0), 3);
    }
    (void)clock;
  (void)input;
  //this->_skin->setCurrentAnim(22);
  (void)clock;
  (void)input;
  return true;
}

void	MenuBoxNumber::setTargetRotation(float rot)
{
  if (rot >= 0 && rot <= 320)
    this->_skin = menu1;
  else if (rot > 320 && rot <= 585)
    {
      rot += 90;
      this->_skin = menu2;
    }
  else if (rot >585 && rot <= 855)
    {
      rot+= 180;
      this->_skin = menu3;
    }
  else
    this->_skin = menu4;
  this->_targetRot = rot;
}

bool MenuBoxNumber::fireTouch()
{
  return true;
}
