//
// ABloc.cpp for ABLOCK in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:16:26 2014 Remi telenczak
// Last update Wed May 21 03:48:52 2014 Remi telenczak
//

#include	"ABloc.hpp"

ABloc::ABloc(Map *map, ModelList *model, EventManager *event) : AObjectPhysic(map, model, event)
{
  this->scale(glm::vec3(1.5, 1.5, 1.5));
  this->_type = BLOC;
}

ABloc::~ABloc()
{

}
