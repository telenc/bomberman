//
// DestrucWall.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Thu Jun  5 10:42:19 2014 Steven Martreux
//

#ifndef		_DESTRUCALL
# define	_DESTRUCALL

# include	"ABloc.hpp"
# include	"AObjectLife.hpp"

class DestrucWall : public ABloc, public AObjectLife
{
public:
  DestrucWall(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
};

#endif
