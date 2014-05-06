//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#include	"AEventNib.hpp"

AEventNib::AEventNib(Game *game, Fruit *fruit) : _game(game), _fruit(fruit), _is_alive(true)
{
  time(&this->_timer);
}

bool	AEventNib::isAlive()
{
  return this->_is_alive;
}

Game	*AEventNib::game() const
{
  return this->_game;
}
