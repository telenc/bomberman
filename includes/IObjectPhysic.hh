//
// IObjectPhysic.hh for bomberman in /home/choqua_m/blih/cpp_bomberman/src
//
// Made by Mathieu Choquart
// Login   <choqua_m@epitech.net>
//
// Started on  Wed May  7 15:47:44 2014 Mathieu Choquart
// Last update Sun Jun 15 19:36:25 2014 Steven Martreux
//

#ifndef			_IOBJECTPHYSIC_HH_
# define		_IOBJECTPHYSIC_HH_

# include		<string>
# include		<iostream>
# include		<Clock.hh>
# include		<Input.hh>

class	IObjectPhysic
{
public:
  virtual bool		collision(IObjectPhysic *) = 0;
  virtual void		display() = 0;
  virtual bool		update(gdl::Clock const &clock, gdl::Input &input) =0;
};

#endif			/* _IOBJECTPHYSIC_HH_ */
