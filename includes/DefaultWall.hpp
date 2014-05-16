//
// DefaultWall.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Fri May 16 07:27:39 2014 Remi telenczak
//

#ifndef		_DEFAULTWALL
# define	_DEFAULTWALL

# include	"ABloc.hpp"

class DefaultWall : public ABloc
{
public:
  DefaultWall(Map *, ModelList *, EventManager *);
  virtual void update(gdl::Clock const &clock, gdl::Input &input);
};

#endif
