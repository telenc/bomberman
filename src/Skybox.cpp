//
// Skybox.cpp for Skybox in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 22 07:25:49 2014 Remi telenczak
// Last update Sun Jun 15 20:33:17 2014 Remi telenczak
//

#include	"Skybox.hpp"
#include	"ModelList.hpp"
#include	<sstream>

Skybox::Skybox(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : AObjectPhysic(map, model, event, clock)
{
  int			nbr;
  std::stringstream	out;
  std::string		s;

  out << "skybox";
  nbr = rand() % 5 + 1;
  if (nbr >= 1 && nbr <= 6)
    out << nbr;
  else
    out << "1";
  s = out.str();
  this->scale(glm::vec3(200, 200, 200));
  this->translate(glm::vec3(0, 50, 0));
  this->_skin = model->getModel(s);
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
