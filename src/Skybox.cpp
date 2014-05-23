//
// Skybox.cpp for Skybox in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 07:25:49 2014 Remi telenczak
// Last update Fri May 23 07:49:49 2014 Remi telenczak
//

#include	"Skybox.hpp"
#include	"ModelList.hpp"

Skybox::Skybox(Map *map, ModelList *model, EventManager *event) : AObjectPhysic(map, model, event)
{
  callPlayerMove = new CallBack<Skybox>(this, &Skybox::eventPlayerMove);
  event->listenEvent("playerMove", callPlayerMove);
  this->scale(glm::vec3(200, 200, 200));
  this->translate(glm::vec3(0, 50, 0));
  this->_skin = model->getModel("skybox");
}

void	Skybox::eventPlayerMove(void *data)
{
  (void)data;
  glm::vec3 *test;

  test = (glm::vec3 *)data;
  (void)test;
  //this->translate(glm::vec3(1 * test->x, 0, 1 * test->z));
}

Skybox::~Skybox()
{

}

bool	Skybox::update(gdl::Clock const &clock, gdl::Input &input)
{
  this->rotate(glm::vec3(0, 1, 0), 0.5);
  (void)clock;
  (void)input;
  return true;
}
