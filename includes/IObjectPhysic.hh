//
// IObjectPhysic.hh for bomberman in /home/choqua_m/blih/cpp_bomberman/src
//
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
//
// Started on  Wed May  7 15:47:44 2014 Mathieu Choquart
// Last update Fri May 23 07:48:23 2014 Remi telenczak
//

#ifndef			_IOBJECTPHYSIC_HH_
# define		_IOBJECTPHYSIC_HH_

# include		<string>
# include		<iostream>
#include	<Clock.hh>
#include	<Input.hh>
class	IObjectPhysic
{
public:
  virtual bool	collision(IObjectPhysic *) = 0;
  virtual void	display() = 0;
  virtual bool	update(gdl::Clock const &clock, gdl::Input &input) =0;
};

#endif
