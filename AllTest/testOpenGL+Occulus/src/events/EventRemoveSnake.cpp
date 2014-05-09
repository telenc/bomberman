//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#include	"EventRemoveSnake.hpp"
#include	"../Map.hpp"
#include	"../Snake.hpp"
#include	"../Tile.hpp"

EventRemoveSnake::EventRemoveSnake(Game *game, Fruit *fruit) : AEventNib(game, fruit)
{
  Map	*map;

  map = game->getMap();
  map->getSnake()->removeSnake();
  this->_is_alive = false;
}

EventRemoveSnake::~EventRemoveSnake()
{

}

bool	EventRemoveSnake::update()
{
  return (false);
}
