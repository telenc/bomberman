//
// Map.hpp for Map in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:32:44 2014 telenc_r
// Last update Fri Apr  4 18:55:47 2014 Steven Martreux
//

#ifndef	_MAP_NIBBLER
#define	_MAP_NIBBLER

#include	<iostream>
#include	<vector>
#include	<list>
#include	"Tile.hpp"
#include	"Fruit.hpp"
#include	"CreateEvent.hpp"


class Snake;
class AeventNib;
class Map
{
public:
  Map(int, int, Game *);
  Tile	*getTile(int, int) const;
  int	getWidth() const;
  int	getHeight() const;
  int	isAlive() const;
  Snake	*getSnake() const;
  std::list<Fruit *>	getFruit() const;
  bool	asFruit(int, int) const;
  void	addFruit(char);
  void	checkFruit(int, int);
  void	checkSnake();
  void	checkEvent();
  void	addWall();
  void	clearRandWall();
  void	pop_special_fruit();
private:
  int	_width;
  int	_height;
  CreateEvent *eventManager;
  std::vector<std::vector<Tile *> > _map;
  std::list<Tile *>	_snake;
  std::list<Fruit *>	_fruit;
  std::list<Tile *>	_wallrand;
  Snake			*snake;
  int			_sizeSnake;
  int			_directionSnake;
  int			_is_alive;
  int			_popfruit;
  Game			*_game;
};

#endif /* _MAP_NIBBLER */
