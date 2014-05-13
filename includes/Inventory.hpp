//
// Inventory.hpp for Inventory in /home/martre_s/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Fri May  9 14:29:28 2014 Steven Martreux
// Last update Tue May 13 16:47:49 2014 Steven Martreux
//

#ifndef		_INVENTORY_HPP_
#define		_INVENTORY_HPP_

#include	<iostream>
#include	<list>

class		Inventory
{
public:
  Inventory();
  ~Inventory();
  int	getNbrBomb(void) const;
  void	setNbrBomb(int);
private:
  int	_MaxBomb;
}

#endif		/* _INVENTORY_HPP_ */
