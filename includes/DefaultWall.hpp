//
// DefaultWall.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
<<<<<<< HEAD
// Last update Mon May 26 08:27:47 2014 Remi telenczak
=======
// Last update Mon May 26 17:04:11 2014 dedicker remi
>>>>>>> 86fd066f3cca2a094e91194976398fe97236bc1e
//

#ifndef		_DEFAULTWALL
# define	_DEFAULTWALL

# include	"ABloc.hpp"

class DefaultWall : public ABloc
{
public:
  DefaultWall(Map *, ModelList *, EventManager *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
};

#endif
