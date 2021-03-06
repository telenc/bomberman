//
// MenuBox.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Sun Jun 15 19:37:47 2014 Steven Martreux
//

#ifndef		_MENUBOX_HPP
# define	_MENUBOX_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class MenuBox : public ABloc
{
public:
  MenuBox(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
  virtual bool	update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool	fireTouch();
  ICallBack	*callRotOcu;
  void		eventRotOcu(void *data);
  void		eventRotOcu2(void *data);
  void		eventRotOcu3(void *data);
  glm::vec3	*getRotation();
  int		getRotationy();
protected:
  int		_i;
  glm::vec3	posSauv;
  glm::vec3	*rot;
};

#endif
