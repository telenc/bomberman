//
// ABloc.cpp for ABLOCK in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:16:26 2014 Remi telenczak
// Last update Tue May 27 02:56:29 2014 Remi telenczak
//

#include	"ABloc.hpp"

ABloc::ABloc(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) : AObjectPhysic(map, model, event, clock)
{
  this->scale(glm::vec3(1.5, 1.5, 1.5));
  this->_type = BLOC;
}

ABloc::~ABloc()
{

}
