//
// DestrucWall.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Mon Jun  2 05:02:27 2014 Remi telenczak
//

#ifndef		_DESTRUCALL
# define	_DESTRUCALLo

# include	"ABloc.hpp"
# include	"AObjectLife.hpp"

class DestrucWall : public ABloc, AObjectLife
{
public:
  DestrucWall(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
private:
  std::string	currentModel;
  gdl::Model	*modelLife1;
  gdl::Model	*modelLife2;
  gdl::Model	*modelLife3;
};

#endif
