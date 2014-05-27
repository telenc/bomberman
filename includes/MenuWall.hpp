//
// MenuWall.hpp for MenuWall.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Mon May 26 16:42:19 2014 dedicker remi
// Last update Tue May 27 03:11:19 2014 Remi telenczak
//

#ifndef		_MENUWALL
# define	_MENUWALL

# include	"ABloc.hpp"

class MenuWall : public ABloc
{
public:
  MenuWall(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
};

#endif
