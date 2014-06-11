//
// MenuBox.cpp for MenuBox.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Wed Jun 11 15:42:47 2014 dedicker remi
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
/*
void	MenuBox::checkBoxExit(glm::vec3 *rotation)
{
  if (rotation->y >= -15)
    if (rotation->x >= 60 && rotation->x <= 90)
      std::cout << "|-- Image de Exit! --|" << std::endl; 
}

void	MenuBox::checkBoxCredit(glm::vec3 *rotation)
{
  if (rotation->y >= -20)
    if (rotation->x <= -50 && rotation->x >= -90)
      std::cout << "|-- Image de Credit! --|" << std::endl;
}

void	MenuBox::checkFacetteBoxMenu(glm::vec3 *rotation)
{
  if (rotation->x <= 20 && rotation->x >= -20)
    {
      if (rotation->y >= -40 && rotation->y <= 50)
	std::cout << "|-- Image de presentation --|" << std::endl;
      else if (rotation->y >= 50 && rotation->y <= 120)
	std::cout << "|-- Image de Play --|" << std::endl;
      else if (rotation->y <= -41 && rotation->y >= -129)
	std::cout << "|-- Image de setting --|" << std::endl;
      else if (rotation->y >= 120 || rotation->y <= -130)
	std::cout << "|-- Image de Derriere --|" << std::endl;
      else
	std::cout << "|-- Dans le vide --|" << std::endl;
    }
}
*/

void	MenuBox::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  newpos = this->posSauv;
  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  this->rot = (glm::vec3 *)data;
  //checkFacetteBoxMenu(rotation);
}

void	MenuBox::eventRotOcu2(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 10, 0);
  this->_position = newpos;
  this->set_roty(rotation->z);
  this->rot = (glm::vec3 *)data;
  //checkBoxExit(rotation);
  //std::cout << "Rotation y " << rotation->y << " Rotation x :" << rotation->x << "Rotation z:" << rotation->z << std::endl;
}

void	MenuBox::eventRotOcu3(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, -10, 0);
  this->_position = newpos;
  this->set_roty(rotation->z);
  this->rot = (glm::vec3 *)data;
  //checkBoxCredit(rotation);
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
