//
// ABomb.cpp for Abomb in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:00:11 2014 Steven Martreux
// Last update Sun Jun 15 19:29:27 2014 Remi telenczak
//

#include	"ABomb.hpp"

ABomb::ABomb(Map *map, ModelList *model, EventManager *event, APlayer *player, gdl::Clock *clock) : AObjectPhysic(map, model, event, clock), _po(1), _time(10000), _damage(1), _player(player), _died(false)
{
  this->_type = BOMB;
  this->_playerColl = false;
  this->_direction = 1;
  time(&this->_timeCreate);
}

bool		ABomb::getDied() const
{
  return _died;
}

void		ABomb::setDied(bool died)
{
  _died = died;
}

bool		ABomb::getPlayerColl() const
{
  return this->_playerColl;
}

void		ABomb::setPlayerColl(bool player)
{
  _playerColl = player;
}

APlayer		*ABomb::getPlayer() const
{
  return this->_player;
}

void		ABomb::setPlayer(APlayer *player)
{
  this->_player = player;
}

void		ABomb::setPo(int po)
{
  this->_po = po;
}

int		ABomb::getPo(void) const
{
  return this->_po;
}

void		ABomb::setTime(int time)
{
  this->_time = time;
}

int		ABomb::getTime(void) const
{
  return this->_time;
}

void		ABomb::setDamage(int damage)
{
  this->_damage = damage;
}

void		ABomb::explode()
{
  if (this->_died == false)
    {
      this->createDeflag();
      this->_died = true;
    }
}

int		ABomb::getDamage(void) const
{
  return this->_damage;
}

ABomb::~ABomb()
{

}
