//
// PlayBox.hpp for playBox in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Fri Jun  6 15:10:50 2014 thomas mendez
// Last update Sun Jun 15 19:03:32 2014 Steven Martreux
//

#ifndef		_PLAYBOX_HPP
# define	_PLAYBOX_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class PlayBox : public ABloc
{
public:
  PlayBox(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
  ICallBack *callRotOcu;
  void	eventRotOcu(void *data);
  glm::vec3   *getRotation();
  int   getRotationy();
protected:
  int _i;
  glm::vec3 posSauv;
  glm::vec3 *rot;
};

#endif
