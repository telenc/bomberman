//
// ABomb.cpp for Abomb in /home/martre_s/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Wed May  7 16:00:11 2014 Steven Martreux
// Last update Wed May  7 16:18:33 2014 Steven Martreux
//

#include	"../includes/ABomb.hpp"

ABomb::ABomb()
{

}

void	Abomb::update(void)
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

void	ABomb::getDamage(int damage)
{
  this->_damage = damage;
}

int	Abomb::setDamage(void) const
{
  return this->_damage;
}

ABomb::~ABomb()
{

}
