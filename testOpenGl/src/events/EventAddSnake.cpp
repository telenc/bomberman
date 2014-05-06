//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Sat Apr  5 16:32:01 2014 Steven Martreux
//

#include	"EventAddSnake.hpp"
#include	"../Map.hpp"
#include	"../Snake.hpp"
#include	"../Tile.hpp"

EventAddSnake::EventAddSnake(Game *game, Fruit *fruit) : AEventNib(game, fruit)
{
  Map	*map;

  map = game->getMap();
  map->getSnake()->addSnake();
  this->_is_alive = false;
}

EventAddSnake::~EventAddSnake()
{

}

bool	EventAddSnake::update()
{
  return (false);
}
