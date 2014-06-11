//
// AFire.hpp for AFIre in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:52:24 2014 Remi telenczak
// Last update Tue Jun 10 16:29:34 2014 Steven Martreux
//

#ifndef		_AFIRE_BOMB
# define	_AFIRE_BOMB

# include	<vector>
# include	"AObjectPhysic.hpp"
# include	<time.h>

class APlayer;
class AFire : public AObjectPhysic
{
protected:
  time_t	_timeCreate;
  int		_damage;
  int		_time;
  std::vector<APlayer *>	*_playerTouched;
  int		_bombId;
public:
  int		isInVec(APlayer *);
  AFire(Map *, ModelList *, EventManager *, std::vector<APlayer *> *, gdl::Clock *, int);
  virtual	~AFire();
  virtual bool	update(gdl::Clock const &clock, gdl::Input &input) = 0;
  void		setDamage(int damage);
  int		getDamage(void) const;
  void		setTime(int time);
  int		getTime(void) const;
  int		getBombId() const;
  void		setBombId(int);
  void		checkPlayerColl();
  std::vector<APlayer *> *getPlayerTouched() const;
  void	setPlayerTouched(std::vector<APlayer *> *playerTouched);
};

#endif
