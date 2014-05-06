//
// Map.hpp for Map in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:32:44 2014 telenc_r
// Last update Fri Apr  4 17:26:07 2014 dedicker remi
//

#ifndef	_CREATEEVENT
#define	_CREATEEVENT

//#include	"AEventNib.hpp"

#include	"Fruit.hpp"
#include	<list>
#include	<map>

class Game;
class AEventNib;

//typedef (AEventNib*)(*funct)(Game*, Fruit*);

//class Fruit;
class	CreateEvent
{
public:
  CreateEvent(Game *game);
  virtual ~CreateEvent();
  void	updateEvents();
  std::map<char , AEventNib*(CreateEvent::*)(Fruit*) > getMapEvent();
  void		newEvent(char t, Fruit *);
private:
  AEventNib	*addEvent(Fruit *);
  AEventNib	*addMoreEvent(Fruit *);
  AEventNib	*speedEvent(Fruit *);
  AEventNib	*despeedEvent(Fruit *);
  AEventNib	*removeEvent(Fruit *);
  AEventNib	*directionEvent(Fruit *);
  AEventNib	*scoreEvent(Fruit *);
  std::map<char , AEventNib*(CreateEvent::*)(Fruit*) > _map;
  void		checkAlive();
  Game	*_game;
  std::list<AEventNib *>	_events;
};

#endif
