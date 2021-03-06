//
// ABomb.hpp for ABomb in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Sun Jun 15 19:39:04 2014 Steven Martreux
//

#ifndef		_ABOMB_HPP_
# define	_ABOMB_HPP_

# include	"AObjectPhysic.hpp"
# include	<time.h>

class		APlayer;
class		ABomb : public AObjectPhysic
{
protected:
  int		_po;
  int		_time;
  int		_damage;
  APlayer	*_player;
  bool		_playerColl;
  int		_direction;
  time_t	_timeCreate;
  bool		_died;
public:
  ABomb(Map *, ModelList *, EventManager *, APlayer *, gdl::Clock *);
  ~ABomb();
  void		explode();
  virtual void  createDeflag() = 0;
  virtual bool	update(gdl::Clock const &clock, gdl::Input &input) = 0;
  APlayer	*getPlayer() const;
  void		setPlayer(APlayer *);
  void		setPo(int po);
  int		getPo(void) const;
  void		setDamage(int damage);
  int		getDamage(void) const;
  void		setTime(int time);
  int		getTime(void) const;
  bool		getPlayerColl() const;
  bool		getDied() const;
  void		setPlayerColl(bool);
  void		setDied(bool);
};

#endif		/* _ABOMB_HPP_ */
