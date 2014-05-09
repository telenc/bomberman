//
// Tile.cpp for Tile in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:45:52 2014 telenc_r
// Last update Thu Apr  3 11:40:59 2014 Steven Martreux
//

#include	<iostream>
#include	"Tile.hpp"

Tile::Tile(int x, int y) : _x(x), _y(y)
{
}

void	Tile::setType(char c)
{
  this->_type = c;
  this->_typeString = c + ".png";
}

std::string	Tile::getTypeString() const
{
  return this->_typeString;
}

char	Tile::getType() const
{
  return this->_type;
}

int	Tile::getX() const
{
  return this->_x;
}

int	Tile::getY() const
{
  return this->_y;
}
