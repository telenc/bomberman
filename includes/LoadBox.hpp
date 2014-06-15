//
// LoadBox.hpp for LoadMenu in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sat Jun 14 16:52:25 2014 thomas mendez
// Last update Sun Jun 15 19:40:49 2014 Steven Martreux
//

#ifndef		_LOADBOX_HPP
# define	_LOADBOX_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class LoadBox : public ABloc
{
public:
  LoadBox(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
  ICallBack	*callRotOcu;
  ICallBack	*callRotOcu2;
  ICallBack	*callRotOcu3;
  ICallBack	*callRotOcu4;
  void		eventRotOcu(void *data);
  void		eventRotOcu2(void *data);
  void		eventRotOcu3(void *data);
  void		eventRotOcu4(void *data);
  glm::vec3	*getRotation();
  int		getRotationy();
protected:
  int		_i;
  glm::vec3	posSauv;
  glm::vec3	*rot;
};

#endif
