//
// AFire.cpp for AFire in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:51:01 2014 Remi telenczak
// Last update Mon May 26 07:07:31 2014 Remi telenczak
//

#include	"AFire.hpp"
#include	"Map.hpp"
#include	"APlayer.hpp"

AFire::AFire(Map *map, ModelList *model, EventManager *event, std::vector<APlayer *> *playerTouched) : AObjectPhysic(map, model, event), _damage(1)
{
  this->_type = FIRE;
  this->_time = 2000;
  time(&this->_timeCreate);
  this->_playerTouched = playerTouched;
}

AFire::~AFire()
{

}

void	AFire::setTime(int time)
{
  this->_time = time;
}

int	AFire::getTime(void) const
{
  return this->_time;
}

void	AFire::setDamage(int damage)
{
  this->_damage = damage;
}

int	AFire::getDamage(void) const
{
  return this->_damage;
}

int	AFire::isInVec(APlayer *player)
{
  std::vector<APlayer *>::iterator it;

  it = _playerTouched->begin();
  while (it != _playerTouched->end())
    {
      if(*it == player)
	return 1;
      it++;
    }
  return 0;
}

void	AFire::checkPlayerColl()
{
  std::vector<APlayer *>	players;
  std::vector<APlayer *>::iterator it;

  players = this->_map->getPlayers();
  it = players.begin();
  while (it != players.end())
    {
      if (this->collision(*it) == true)
	{
	  if (isInVec(*it) == 0)
	    {
	      this->_playerTouched->push_back(*it);
	      (*it)->decLife();
	    }
	}
      it++;
    }
}
