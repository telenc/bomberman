//
// AFire.hpp for AFIre in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:52:24 2014 Remi telenczak
// Last update Tue May 27 02:57:46 2014 Remi telenczak
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
  int i;
  int _damage;
  int	_time;
  std::vector<APlayer *>	*_playerTouched;
public:
  int	isInVec(APlayer *);
  AFire(Map *, ModelList *, EventManager *, std::vector<APlayer *> *, gdl::Clock *);
  virtual ~AFire();
  virtual bool update(gdl::Clock const &clock, gdl::Input &input) = 0;
  void setDamage(int damage);
  int getDamage(void) const;
  void setTime(int time);
  int getTime(void) const;
  void	checkPlayerColl();
};

#endif
