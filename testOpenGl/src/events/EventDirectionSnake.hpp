//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#ifndef	_DIRECTIONEVENTNIBB
#define _DIRECTIONEVENTNIBB

#include	"../AEventNib.hpp"

class EventDirectionSnake : public AEventNib
{
public:
  EventDirectionSnake(Game *, Fruit *);
  virtual ~EventDirectionSnake();
  bool update();
};

#endif
