//
// ABomb.cpp for Abomb in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:00:11 2014 Steven Martreux
// Last update Thu May 15 08:59:05 2014 Remi telenczak
//

#include	"ABomb.hpp"

ABomb::ABomb(Map *map, ModelList *model, EventManager *event) :AObjectPhysic(map, model, event)
{

}

void	ABomb::update(void)
{

}

void	ABomb::setPo(int po)
{
  this->_po = po;
}

int	ABomb::getPo(void) const
{
  return this->_po;
}

void	ABomb::setTime(int time)
{
  this->_time = time;
}

int	ABomb::getTime(void) const
{
  return this->_time;
}

void	ABomb::setDamage(int damage)
{
  this->_damage = damage;
}

int	ABomb::getDamage(void) const
{
  return this->_damage;
}

ABomb::~ABomb()
{

}
