//
// ABloc.hpp for Block in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:15:05 2014 Remi telenczak
// Last update Mon May 26 07:14:13 2014 Remi telenczak
//

#ifndef		_ABLOCK_HPP
# define	_ABLOCK_HPP

# include	"AObjectPhysic.hpp"

class	ABloc : public AObjectPhysic
{
public:
  ABloc(Map *, ModelList *, EventManager *);
  virtual ~ABloc();
  virtual bool update(gdl::Clock const &clock, gdl::Input &input) = 0;
  virtual void fireTouch() = 0;
};

#endif
