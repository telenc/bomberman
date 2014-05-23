//
// DefaultFire.hpp for Fire in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:58:43 2014 Remi telenczak
// Last update Fri May 23 05:48:36 2014 Remi telenczak
//

#ifndef		_DEFAULTFIRE
# define	_DEFAULTFIRE

# include	"AFire.hpp"

class DefaultFire : public AFire
{
public:
  DefaultFire(Map *, ModelList *, EventManager *);

  virtual void update(gdl::Clock const &clock, gdl::Input &input);
};

#endif
