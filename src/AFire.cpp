//
// AFire.cpp for AFire in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:51:01 2014 Remi telenczak
// Last update Sat Jun 14 23:32:19 2014 Remi telenczak
//

#include	"AFire.hpp"
#include	"Map.hpp"
#include	"APlayer.hpp"

AFire::AFire(Map *map, ModelList *model, EventManager *event, std::vector<APlayer *> *playerTouched, gdl::Clock *clock, int bombId) : AObjectPhysic(map, model, event, clock), _damage(1), _bombId(bombId)
{
  this->_type = FIRE;
  this->_time = 2000;
  time(&this->_timeCreate);
  this->_playerTouched = playerTouched;
}

AFire::~AFire()
{

}

int	AFire::getBombId() const
{
  return _bombId;
}

void	AFire::setBombId(int bombId)
{
  _bombId = bombId;
}

std::vector<APlayer *> *AFire::getPlayerTouched() const
{
  return _playerTouched;
}

void	AFire::setPlayerTouched(std::vector<APlayer *> *playerTouched)
{
  _playerTouched = playerTouched;
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
	      std::cout << "Player touched" << std::endl;
	    }
	}
      it++;
    }
}
