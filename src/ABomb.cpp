//
// ABomb.cpp for Abomb in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:00:11 2014 Steven Martreux
// Last update Fri May 23 04:30:56 2014 Remi telenczak
//

#include	"ABomb.hpp"

ABomb::ABomb(Map *map, ModelList *model, EventManager *event, APlayer *player) :AObjectPhysic(map, model, event), _po(1), _time(10000), _damage(1), _player(player)
{
  this->_type = BOMB;
  this->_playerColl = false;
  this->_direction = 1;
  time(&this->_timeCreate);
}

bool	ABomb::getPlayerColl() const
{
  return this->_playerColl;
}

APlayer		*ABomb::getPlayer() const
{
  return this->_player;
}

void		ABomb::setPlayer(APlayer *player)
{
  this->_player = player;
}

void	ABomb::setPo(int po)
{
  this->_po = po;
}

int	ABomb::getPo(void) const
{
  return this->_po;
}

void	ABomb::setTime(int time)
{
  this->_time = time;
}

int	ABomb::getTime(void) const
{
  return this->_time;
}

void	ABomb::setDamage(int damage)
{
  this->_damage = damage;
}

int	ABomb::getDamage(void) const
{
  return this->_damage;
}

ABomb::~ABomb()
{

}
