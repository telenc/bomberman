//
// Inventory.hpp for Inventory in /home/martre_s/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Fri May  9 14:29:28 2014 Steven Martreux
// Last update Wed May 14 15:36:55 2014 dedicker remi
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
};

#endif		/* _INVENTORY_HPP_ */
