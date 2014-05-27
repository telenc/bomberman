//
// MenuBox.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Tue May 27 15:51:17 2014 dedicker remi
//

#ifndef		_MENUBOX_HPP
# define	_MENUBOX_HPP

# include	"ABloc.hpp"

class MenuBox : public ABloc
{
public:
  MenuBox(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
};

#endif
