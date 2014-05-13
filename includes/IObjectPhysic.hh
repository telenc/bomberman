//
// IObjectPhysic.hh for bomberman in /home/choqua_m/blih/cpp_bomberman/src
//
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
//
// Started on  Wed May  7 15:47:44 2014 Mathieu Choquart
// Last update Tue May 13 08:43:31 2014 Remi telenczak
//

#ifndef			_IOBJECTPHYSIC_HH_
# define		_IOBJECTPHYSIC_HH_

# include		<string>
# include		<iostream>

class	IObjectPhysic
{
public:
  virtual bool	collision(IObjectPhysic *);
  virtual void	display();
  virtual void	update();
};

#endif
