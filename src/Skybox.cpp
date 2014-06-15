//
// Skybox.cpp for Skybox in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 07:25:49 2014 Remi telenczak
// Last update Sun Jun 15 19:15:32 2014 Remi telenczak
//

#include	"Skybox.hpp"
#include	"ModelList.hpp"

Skybox::Skybox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : AObjectPhysic(map, model, event, clock)
{
  this->scale(glm::vec3(200, 200, 200));
  this->translate(glm::vec3(0, 50, 0));
  this->_skin = model->getModel("skybox");
}

Skybox::~Skybox()
{

}

bool	Skybox::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  return true;
}
