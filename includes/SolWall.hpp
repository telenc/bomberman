//
// SolWall.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Tue May 27 03:10:54 2014 Remi telenczak
//

#ifndef		_SOLWALL
# define	_SOLWALL

# include	"ABloc.hpp"

class SolWall : public ABloc
{
public:
  SolWall(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
};

#endif
