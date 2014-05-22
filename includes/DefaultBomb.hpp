//
// DefaultBomb.hpp for DefaultBomb$ in /home/remi/cpp_bomberman/src
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May 21 01:37:38 2014 Remi telenczak
// Last update Wed May 21 01:51:00 2014 Remi telenczak
//

#ifndef		_DEFAULTBOMB
# define	_DEFAULTBOMB

# include	"ABomb.hpp"

class DefaultBomb : public ABomb
{
public:
  DefaultBomb(Map *, ModelList *, EventManager *, APlayer *);
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
  virtual void createDeflag();
};

#endif