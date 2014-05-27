//
// DefaultFire.hpp for Fire in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Fri May 23 03:58:43 2014 Remi telenczak
// Last update Tue May 27 03:00:32 2014 Remi telenczak
//

#ifndef		_DEFAULTFIRE
# define	_DEFAULTFIRE

# include	"AFire.hpp"

class DefaultFire : public AFire
{
public:
  DefaultFire(Map *, ModelList *, EventManager *, std::vector<APlayer *> *, gdl::Clock *);
  virtual ~DefaultFire();
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
};

#endif
