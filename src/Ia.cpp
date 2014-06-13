//
// Ia.cpp for Ia in /home/telenc_r/cpp_bomberman
//
// Made by Remi telenczak
// Login   <telenc_r@epitech.net>
//
// Started on  Fri Jun 13 12:28:13 2014 Remi telenczak
// Last update Fri Jun 13 14:01:19 2014 Remi telenczak
//

#include		"Ia.hpp"
#include	"EventManager.hpp"


Ia::Ia(int x, int y, int z, Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : APlayer(x, y, z, map, model, event, clock)
{
  std::cout << "Ia created" << std::endl;
  this->set_x(x);
  this->set_z(z);
}

Ia::~Ia()
{

}

bool	Ia::update(gdl::Clock const &clock, gdl::Input &input)
{
  (void)clock;
  (void)input;
  return true;
}
