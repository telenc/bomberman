//
// AFire.hpp for AFIre in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:52:24 2014 Remi telenczak
// Last update Mon May 26 04:59:19 2014 Remi telenczak
//

#ifndef		_AFIRE_BOMB
# define	_AFIRE_BOMB

# include	"AObjectPhysic.hpp"
# include	<time.h>

class AFire : public AObjectPhysic
{
protected:
  time_t	_timeCreate;
  int i;
  int _damage;
  int	_time;
public:
  AFire(Map *, ModelList *, EventManager *);
  virtual ~AFire();
  virtual bool update(gdl::Clock const &clock, gdl::Input &input) = 0;
  AObjectPhysic *checkPositionCollision(TypeObject);
  void setDamage(int damage);
  int getDamage(void) const;
  void setTime(int time);
  int getTime(void) const;
  void	checkPlayerColl();
};

#endif
