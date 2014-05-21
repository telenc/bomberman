//
// ABomb.hpp for ABomb in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Wed May 21 03:42:46 2014 Remi telenczak
//

#ifndef		_ABOMB_HPP_
# define	_ABOMB_HPP_

#include "AObjectPhysic.hpp"

class		APlayer;
class		ABomb : public AObjectPhysic
{
protected:
  int _po;
  int	_time;
  int _damage;
  APlayer	*_player;
  bool		_playerColl;
  int		_direction;
public:
  ABomb(Map *, ModelList *, EventManager *, APlayer *player);
  ~ABomb();
  virtual void createDeflag() = 0;
  virtual void update(gdl::Clock const &clock, gdl::Input &input) = 0;
  APlayer	*getPlayer() const;
  void		setPlayer(APlayer *);
  void setPo(int po);
  int	getPo(void) const;
  void setDamage(int damage);
  int getDamage(void) const;
  void setTime(int time);
  int getTime(void) const;
  bool	getPlayerColl() const;
};

#endif		/* _ABOMB_HPP_ */
