//
// SaveBox.cpp for SaveBox in /home/mendez_t/local/cpp/cpp_bomberman/src/Bloc
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 18:34:23 2014 thomas mendez
// Last update Sun Jun 15 21:09:44 2014 thomas mendez
//

#include	<iostream>
#include	<fstream>
#include	"SaveBox.hpp"
#include	"ModelList.hpp"
#include	"EventManager.hpp"

SaveBox::SaveBox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock, int i) : ABloc(map, model, event, clock)
{
  this->_height = 10;
  this->_width = 10;
  this->set_z(-10);
  this->set_y(0);
  this->set_x(0);
  this->_i = i;
  if (i == 1)
    {
      std::ifstream fichier("sauv/save1.xml", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      this->_position.z = -1;
      this->posSauv.z = -4.5;
      callRotOcu = new CallBack<SaveBox>(this, &SaveBox::eventRotOcu);
    }
  else if (i == 2)
    {
      std::ifstream fichier("sauv/save2.xml", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      callRotOcu = new CallBack<SaveBox>(this, &SaveBox::eventRotOcu2);
    }
  else if (i == 3)
    {
      std::ifstream fichier("sauv/save3.xml", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      callRotOcu = new CallBack<SaveBox>(this, &SaveBox::eventRotOcu3);
    }
  else if (i == 4)
    {
      std::ifstream fichier("sauv/save4.xml", std::ios::in);
      if (fichier)
      	this->_skin = model->getModel("box_sauv");
      else
      	this->_skin = model->getModel("box_vide");
      callRotOcu = new CallBack<SaveBox>(this, &SaveBox::eventRotOcu4);
    }
  event->listenEvent("rotOcu", callRotOcu);
  //  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	SaveBox::getRotation()
{
  return this->rot;
}

int		SaveBox::getRotationy()
{
  return this->rot->y;
}

/*void	SaveBox::checkBoxExit(glm::vec3 *rotation)
{
  if (rotation->y >= -15)
    if (rotation->x >= 60 && rotation->x <= 90)
      std::cout << "|-- Image de Exit! --|" << std::endl; 
}

void	SaveBox::checkBoxCredit(glm::vec3 *rotation)
{
  if (rotation->y >= -20)
    if (rotation->x <= -50 && rotation->x >= -90)
      std::cout << "|-- Image de Credit! --|" << std::endl;
}

void	SaveBox::checkFacetteBoxMenu(glm::vec3 *rotation)
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


void	SaveBox::eventRotOcu(void *data)
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

void	SaveBox::eventRotOcu2(void *data)
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

void	SaveBox::eventRotOcu3(void *data)
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

void	SaveBox::eventRotOcu4(void *data)
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

bool SaveBox::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (this->_i == 1 && this->posSauv.z > -10)
    {
      this->posSauv.z -= 0.13;
    }
  (void)clock;
  (void)input;
  return true;
}

bool SaveBox::fireTouch()
{
  return true;
}
