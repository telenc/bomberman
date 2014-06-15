//
// SettingBoxIG.cpp for SettingsBoxIG in /home/mendez_t/local/cpp/cpp_bomberman/src/Bloc
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 04:34:50 2014 thomas mendez
// Last update Sun Jun 15 04:37:06 2014 thomas mendez
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
  //  event->listenEvent("rotOcu", callRotOcu);
}

glm::vec3*	SettingBoxIG::getRotation()
{
  return this->rot;
}

int		SettingBoxIG::getRotationy()
{
  return this->rot->y;
}

/*void	SettingBoxIG::checkBoxExit(glm::vec3 *rotation)
{
  if (rotation->y >= -15)
    if (rotation->x >= 60 && rotation->x <= 90)
      std::cout << "|-- Image de Exit! --|" << std::endl; 
}

void	SettingBoxIG::checkBoxCredit(glm::vec3 *rotation)
{
  if (rotation->y >= -20)
    if (rotation->x <= -50 && rotation->x >= -90)
      std::cout << "|-- Image de Credit! --|" << std::endl;
}

void	SettingBoxIG::checkFacetteBoxMenu(glm::vec3 *rotation)
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


void	SettingBoxIG::eventRotOcu(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 0, -10);
  newpos = this->posSauv;
  newpos = glm::rotateY(newpos, rotation->y);
  this->_position = newpos;
  this->rot = (glm::vec3 *)data;
  //  checkFacetteBoxMenu(rotation);
}
/*
void	SettingBoxIG::eventRotOcu2(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, 10, 0);
  this->_position = newpos;
  this->set_roty(rotation->z);
  this->rot = (glm::vec3 *)data;
  checkBoxExit(rotation);
  std::cout << "Rotation y " << rotation->y << " Rotation x :" << rotation->x << "Rotation z:" << rotation->z << std::endl;
}

void	SettingBoxIG::eventRotOcu3(void *data)
{
  glm::vec3 *rotation;
  rotation = (glm::vec3 *)data;
  glm::vec3 newpos(0, -10, 0);
  this->_position = newpos;
  this->set_roty(rotation->z);
  this->rot = (glm::vec3 *)data;
  checkBoxCredit(rotation);
}
*/
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
