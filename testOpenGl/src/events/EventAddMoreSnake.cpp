//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#include	"EventAddMoreSnake.hpp"
#include	<ctime>
#include	<stdlib.h>
#include	<cstdlib>
#include	"../Map.hpp"
#include	"../Snake.hpp"
#include	"../Tile.hpp"

EventAddMoreSnake::EventAddMoreSnake(Game *game, Fruit *fruit) : AEventNib(game, fruit)
{
  Map	*map;
  int	nbr;

  std::srand(std::time(0));
  nbr = std::rand() % 3 + 1;
  map = game->getMap();
  while (nbr > 0)
    {
      map->getSnake()->addSnake();
      this->_game->addScore(15);
      nbr--;
    }
  this->_is_alive = false;
}

EventAddMoreSnake::~EventAddMoreSnake()
{

}

bool	EventAddMoreSnake::update()
{
  return (false);
}
