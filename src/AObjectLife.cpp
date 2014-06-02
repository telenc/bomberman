//
// ALife.cpp for aLife in /home/remi/cpp_bomberman/includes
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 08:25:08 2014 Remi telenczak
// Last update Fri May 30 14:55:08 2014 Steven Martreux
//

#include	"AObjectLife.hpp"

AObjectLife::AObjectLife(int life) : _life(life)
{

}

AObjectLife::~AObjectLife()
{

}

void	AObjectLife::decLife()
{
  this->_life--;
}

void	AObjectLife::incLife()
{
  this->_life++;
}

int	AObjectLife::getLife() const
{
  return (this->_life);
}

void	AObjectLife::setLife(int life)
{
  _life = life;
}
