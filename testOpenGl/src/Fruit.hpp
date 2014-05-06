//
// Fruit.hpp for Nibbler in /home/martre_s/Epitech/Cpp/cpp_nibbler/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Tue Apr  1 16:12:21 2014 Steven Martreux
// Last update Tue Apr  1 05:09:41 2014 telenc_r
//

#ifndef		_FRUIT_HPP_
# define	_FRUIT_HPP_

#include	"Tile.hpp"

class		Fruit : public Tile
{
public:
  Fruit(int x, int y, char type);
  virtual ~Fruit() {};
private:
  int	_x;
  int	_y;
  char	_type;
};

#endif
