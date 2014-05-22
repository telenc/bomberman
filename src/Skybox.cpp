//
// Skybox.cpp for Skybox in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 07:25:49 2014 Remi telenczak
// Last update Thu May 22 07:37:45 2014 Remi telenczak
//

#include	"Skybox.hpp"
#include	"ModelList.hpp"

Skybox::Skybox(Map *map, ModelList *model, EventManager *event) : AObjectPhysic(map, model, event)
{
  this->scale(glm::vec3(100, 100, 100));
  this->_skin = model->getModel("skybox");
}

Skybox::~Skybox()
{

}

void	Skybox::update(gdl::Clock const &clock, gdl::Input &input)
{
  this->rotate(glm::vec3(0, 1, 0), 0.5);
  (void)clock;
  (void)input;
}
