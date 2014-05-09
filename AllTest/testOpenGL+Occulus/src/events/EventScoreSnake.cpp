//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#include	"EventScoreSnake.hpp"
#include	"../Map.hpp"
#include	"../Snake.hpp"
#include	"../Tile.hpp"

EventScoreSnake::EventScoreSnake(Game *game, Fruit *fruit) : AEventNib(game, fruit)
{
  if (game->getScoreMulti() == 1)
    game->setScoreMulti(2);
  else
    this->_is_alive = false;
}

EventScoreSnake::~EventScoreSnake()
{

}

bool	EventScoreSnake::update()
{
  time_t	currTimer;
  double	seconde;

  time(&currTimer);
  seconde = difftime(currTimer, this->_timer);
  if (seconde > 40)
    {
      this->game()->resetScoreMulti();
      this->_is_alive = false;
    }
  return (false);
}
