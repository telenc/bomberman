//
// ABonus.cpp for Abomb in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:00:11 2014 Steven Martreux
// Last update Fri May 30 08:29:36 2014 Remi telenczak
//

#include	"ABonus.hpp"

ABonus::ABonus(Map *map, ModelList *model, EventManager *event, gdl::Clock *clock) :AObjectPhysic(map, model, event, clock)
{
  this->_type = BONUS;
  this->_height = 3;
  this->_width = 3;
  this->_depth = 3;
  this->_died = false;
}

void	ABonus::fireTouch()
{
  this->_died = true;
}

ABonus::~ABonus()
{

}