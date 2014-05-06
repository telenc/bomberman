//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#include	"EventSpeedSnake.hpp"
#include	"../Map.hpp"
#include	"../Snake.hpp"
#include	"../Tile.hpp"

EventSpeedSnake::EventSpeedSnake(Game *game, Fruit *fruit) : AEventNib(game, fruit)
{
  game->setSpeed(50000);
}

EventSpeedSnake::~EventSpeedSnake()
{

}

bool	EventSpeedSnake::update()
{
  time_t	currTimer;
  double	seconde;

  time(&currTimer);
  seconde = difftime(currTimer, this->_timer);
  if (seconde > 15)
    {
      std::cout << "On reset speed " << std::endl;
      this->game()->resetSpeed();
      this->_is_alive = false;
    }
  return (false);
}
