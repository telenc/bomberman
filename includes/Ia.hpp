//
// Ia.hpp for Ia in /home/telenc_r/cpp_bomberman
//
// Made by Remi telenczak
// Login   <telenc_r@epitech.net>
//
// Started on  Fri Jun 13 12:28:24 2014 Remi telenczak
// Last update Fri Jun 13 12:51:49 2014 Remi telenczak
//

#ifndef		_IABOMBER
# define	_IABOMBER

# include	"APlayer.hpp"
# include	"Input.hh"

class Ia : public APlayer
{
public:
  Ia(int x, int y, int z, Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  ~Ia();
};

#endif