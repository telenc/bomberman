//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Sat Apr  5 16:32:02 2014 Steven Martreux
//

#ifndef	_EVENTNIB
#define	_EVENTNIB

#include	"Game.hpp"
#include	"Fruit.hpp"
#include	"time.h"

class AEventNib
{
public:
  AEventNib(Game *, Fruit * );
  virtual ~AEventNib() {};
  virtual bool update() = 0;
  Game	*game() const;
  bool	isAlive();
protected:
  Game *_game;
  Fruit *_fruit;
  bool	_is_alive;
  time_t	_timer;
};

#endif
