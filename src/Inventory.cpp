//
// Inventory.cpp for Inventory in /home/martre_s/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Fri May  9 14:28:56 2014 Steven Martreux
// Last update Tue May 13 16:47:50 2014 Steven Martreux
//

#include	"Inventory.hpp"

Inventory::Inventory()
{

}

int		Inventory::getNbrBomb(void) const
{
  return this->_MaxBomb;
}

void		Inventory::setNbrBomb(int MaxBomb)
{
  this->_MaxBomb = MaxBomb;
}

Inventory::~Inventory()
{

}

