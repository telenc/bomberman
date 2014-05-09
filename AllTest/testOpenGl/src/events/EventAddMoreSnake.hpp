//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#ifndef	_ADDMOREEVENTNIBB
#define _ADDMOREEVENTNIBB

#include	"../AEventNib.hpp"

class EventAddMoreSnake : public AEventNib
{
public:
  EventAddMoreSnake(Game *, Fruit *);
  virtual ~EventAddMoreSnake();
  bool update();
};

#endif
