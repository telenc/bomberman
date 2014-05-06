//
// Snake.hpp for snale in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Mon Mar 17 10:20:30 2014 telenc_r
// Last update Mon Mar 17 10:54:58 2014 telenc_r
//

#ifndef	_SNAKE_NIBBLER
#define	_SNAKE_NIBBLER

#include	<list>
//#include	"Map.hpp"
//
//#include	"Map.hpp"

class Map;
class Tile;

class Snake
{
public:
  Snake(Map *);
  std::list<Tile *> getSnake() const;
  void	move();
  bool	inSnake() const;
  int	getDirectionFruit();
  int	getDirection() const;
  void	changeDirectionLeft();
  void	changeDirectionRight();
  void	changeDirectionFruit();
  int	getSizeSnake() const;
  void	setSizeSnake(int);
  bool	checkInSnake(int, int) const;
  bool	asSnake(int, int) const;
  void	addSnake();
  void	removeSnake();
private:
  void	checkAddSnake(int, int, Tile *);
  std::list<Tile *> _snake;
  Map	*_map;
  int	_size;
  int	_direction;
  int	_directionFruit;
};

#endif
