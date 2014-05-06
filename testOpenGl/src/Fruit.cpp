//
// Fruit.cpp for Nibbler in /home/martre_s/Epitech/Cpp/cpp_nibbler/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Tue Apr  1 16:13:07 2014 Steven Martreux
// Last update Wed Apr  2 18:09:25 2014 Steven Martreux
//

#include	"Fruit.hpp"

Fruit::Fruit(int x, int y, char type) : Tile(x, y)
{
  this->_x = x;
  this->_y = y;
  this->_type = type;
  setType(type);
}

