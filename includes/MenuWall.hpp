//
// MenuWall.hpp for MenuWall.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman
// 
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
// 
// Started on  Mon May 26 16:42:19 2014 dedicker remi
// Last update Mon May 26 16:44:18 2014 dedicker remi
//

#ifndef		_MENUWALL
# define	_MENUWALL

# include	"ABloc.hpp"

class MenuWall : public ABloc
{
public:
  MenuWall(Map *, ModelList *, EventManager *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
};

#endif
