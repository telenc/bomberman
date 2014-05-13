//
// ALife.cpp for aLife in /home/remi/cpp_bomberman/includes
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 08:25:08 2014 Remi telenczak
// Last update Tue May 13 08:26:46 2014 Remi telenczak
//

#include	"AObjectLife.hpp"

AObjectLife::AObjectLife(int life) : _life(life);
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

int	AObjectLife::getLife()
{
  return (this->_life);
}
