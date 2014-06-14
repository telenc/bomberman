//
// LoadBox.cpp for LoadBox.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:41:50 2014 dedicker remi
// Last update Sun Jun 15 01:31:13 2014 thomas mendez
//

#include	<iostream>
#include <fstream>
#include	"LoadBox.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

LoadBox::LoadBox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock, int i) : ABloc(map, model, event, clock)
{
  //  this->_skin = model->getModel("box_vide");
  this->_height = 10;
  this->_width = 10;
  this->set_z(-10);
  this->set_y(0);
  this->set_x(0);
  this->_i = i;
  if (i == 1)
    {
      std::ifstream fichier("sauv/sauv1.txt", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      this->_position.z = -1;
      this->posSauv.z = -4.5;
      callRotOcu = new CallBack<LoadBox>(this, &LoadBox::eventRotOcu);
    }
  else if (i == 2)
    {
      std::ifstream fichier("sauv/sauv2.txt", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      callRotOcu = new CallBack<LoadBox>(this, &LoadBox::eventRotOcu2);
    }
  else if (i == 3)
    {
      std::ifstream fichier("sauv/sauv3.txt", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      callRotOcu = new CallBack<LoadBox>(this, &LoadBox::eventRotOcu3);
    }
  else if (i == 4)
    {
      std::ifstream fichier("sauv/sauv4.txt", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      callRotOcu = new CallBack<LoadBox>(this, &LoadBox::eventRotOcu4);
    }
  event->listenEvent("rotOcu", callRotOcu);
  //  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	LoadBox::getRotation()
{
  return this->rot;
}

int		LoadBox::getRotationy()
{
  return this->rot->y;
}

/*void	LoadBox::checkBoxExit(glm::vec3 *rotation)
{
  if (rotation->y >= -15)
    if (rotation->x >= 60 && rotation->x <= 90)
      std::cout << "|-- Image de Exit! --|" << std::endl; 
}

void	LoadBox::checkBoxCredit(glm::vec3 *rotation)
{
  if (rotation->y >= -20)
    if (rotation->x <= -50 && rotation->x >= -90)
      std::cout << "|-- Image de Credit! --|" << std::endl;
}

void	LoadBox::checkFacetteBoxMenu(glm::vec3 *rotation)
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
    }*/


void	LoadBox::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  //newpos = this->posSauv;
  //  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  //this->rot = (glm::vec3 *)data;
  (void)rotation;
  //  checkFacetteBoxMenu(rotation);
}

void	LoadBox::eventRotOcu2(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, 10);
  //newpos = this->posSauv;
  //  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  //this->rot = (glm::vec3 *)data;
  (void)rotation;
  //  checkFacetteBoxMenu(rotation);
}

void	LoadBox::eventRotOcu3(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(10, 0, 0);
  //newpos = this->posSauv;
  //  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  //this->rot = (glm::vec3 *)data;
  (void)rotation;
  //  checkFacetteBoxMenu(rotation);
}

void	LoadBox::eventRotOcu4(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(-10, 0, 0);
  //newpos = this->posSauv;
  //  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  //this->rot = (glm::vec3 *)data;
  (void)rotation;
  //  checkFacetteBoxMenu(rotation);
}

bool LoadBox::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_i == 1 && this->posSauv.z > -10)
    {
      this->posSauv.z -= 0.13;
    }
  (void)clock;
  (void)input;
  return true;
}

bool LoadBox::fireTouch()
{
  return true;
}
