//
// DefaultWall.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Tue Jun  3 04:01:52 2014 Remi telenczak
//

#ifndef		_MENUBOXNUMBER
# define	_MENUBOXNUMBER

# include	"ABloc.hpp"

class MenuBoxNumber : public ABloc
{
public:
  MenuBoxNumber(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
  void		goDelete();
  void	setTargetRotation(float rot);
private:
  float	_targetRot;
  bool		_died;
  float		_ytarget;
  gdl::Model	*menu1;
  gdl::Model	*menu2;
  gdl::Model	*menu3;
  gdl::Model	*menu4;
};

#endif
