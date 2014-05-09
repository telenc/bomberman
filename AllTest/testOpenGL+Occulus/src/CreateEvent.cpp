//
// Map.hpp for Map in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:32:44 2014 telenc_r
// Last update Fri Apr  4 17:49:14 2014 dedicker remi
//

#include	"CreateEvent.hpp"
#include	"AEventNib.hpp"
#include	"events/EventAddSnake.hpp"
#include	"events/EventAddMoreSnake.hpp"
#include	"events/EventSpeedSnake.hpp"
#include	"events/EventRemoveSnake.hpp"
#include	"events/EventDespeedSnake.hpp"
#include	"events/EventDirectionSnake.hpp"
#include	"events/EventScoreSnake.hpp"

CreateEvent::CreateEvent(Game *game) : _game(game)
{
  _map.insert(std::pair<char, AEventNib*(CreateEvent::*)(Fruit *)>('a', &CreateEvent::addEvent));
  _map.insert(std::pair<char, AEventNib*(CreateEvent::*)(Fruit *)>('r', &CreateEvent::removeEvent));
  _map.insert(std::pair<char, AEventNib*(CreateEvent::*)(Fruit *)>('s', &CreateEvent::speedEvent));
  _map.insert(std::pair<char, AEventNib*(CreateEvent::*)(Fruit *)>('d', &CreateEvent::despeedEvent));
  _map.insert(std::pair<char, AEventNib*(CreateEvent::*)(Fruit *)>('t', &CreateEvent::directionEvent));
  _map.insert(std::pair<char, AEventNib*(CreateEvent::*)(Fruit *)>('m', &CreateEvent::scoreEvent));
  _map.insert(std::pair<char, AEventNib*(CreateEvent::*)(Fruit *)>('p', &CreateEvent::addMoreEvent));
}

CreateEvent::~CreateEvent()
{
  std::map<char,AEventNib*(CreateEvent::*)(Fruit*) >::iterator it;

  for (it=_map.begin(); it!=_map.end(); ++it)
    _map.erase(it);
}

std::map<char , AEventNib*(CreateEvent::*)(Fruit*) > CreateEvent::getMapEvent()
{
  return (this->_map);
}

void		CreateEvent::newEvent(char t, Fruit *fruit)
{
  std::map<char , AEventNib*(CreateEvent::*)(Fruit*) >::iterator i;

  i = _map.find(t);
  if (i != _map.end())
    this->_events.push_back((this->*_map[t])(fruit));
}

AEventNib	*CreateEvent::addEvent(Fruit *fruit)
{
  this->_game->addScore(10);
  return (AEventNib *)(new EventAddSnake(this->_game, fruit));
}

AEventNib	*CreateEvent::addMoreEvent(Fruit *fruit)
{
  return (AEventNib *)(new EventAddMoreSnake(this->_game, fruit));
}

AEventNib	*CreateEvent::speedEvent(Fruit *fruit)
{
  this->_game->addScore(10);
  this->_events.push_back(this->addEvent(fruit));
  return (AEventNib *)(new EventSpeedSnake(this->_game, fruit));
}

AEventNib	*CreateEvent::removeEvent(Fruit *fruit)
{
  return (AEventNib *)(new EventRemoveSnake(this->_game, fruit));
}

AEventNib	*CreateEvent::despeedEvent(Fruit *fruit)
{
  this->_events.push_back(this->addEvent(fruit));
  return (AEventNib *)(new EventDespeedSnake(this->_game, fruit));
}

AEventNib	*CreateEvent::directionEvent(Fruit *fruit)
{
  this->_game->addScore(20);
  this->_events.push_back(this->addEvent(fruit));
  return (AEventNib *)(new EventDirectionSnake(this->_game, fruit));
}

AEventNib	*CreateEvent::scoreEvent(Fruit *fruit)
{
  this->_events.push_back(this->addEvent(fruit));
  return (AEventNib *)(new EventScoreSnake(this->_game, fruit));
}

void		CreateEvent::checkAlive()
{
  std::list<AEventNib *>::iterator i;

  i = _events.begin();
  while(i != _events.end())
    {
      if ((*i)->isAlive() == false)
	{
	  _events.erase(i);
	  i = _events.begin();
	}
      else
	++i;
    }
}

void		CreateEvent::updateEvents()
{
  std::list<AEventNib *>::iterator i;

  for(i = _events.begin(); i != _events.end(); ++i)
    {
      (*i)->update();
    }
  checkAlive();
}
