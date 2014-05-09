//
// Tile.hpp for tile in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
// 
// Made by telenc_r
// Login   <remi@epitech.net>
// 
// Started on  Sat Mar 15 07:46:03 2014 telenc_r
// Last update Wed Apr  2 19:17:07 2014 Steven Martreux
//

#ifndef	_TILE_NIBBLER
#define	_TILE_NIBBLER

#include	<string>

class Tile
{
public:
  Tile(int x, int y);
  void	setType(char c);
  std::string	getTypeString() const;
  char		getType() const;
  int		getX() const;
  int		getY() const;
protected:
  std::string	_typeString;
  char		_type;
  int		_x;
  int	       _y;
};

#endif
