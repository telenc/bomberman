//
// SaveBox.hpp for SaveBox in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 18:30:28 2014 thomas mendez
// Last update Sun Jun 15 18:30:54 2014 thomas mendez
//

#ifndef		_SAVEBOX_HPP
# define	_SAVEBOX_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class SaveBox : public ABloc
{
public:
  SaveBox(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
  ICallBack *callRotOcu;
  ICallBack *callRotOcu2;
  ICallBack *callRotOcu3;
  ICallBack *callRotOcu4;
  void	eventRotOcu(void *data);
  void	eventRotOcu2(void *data);
  void	eventRotOcu3(void *data);
  void	eventRotOcu4(void *data);
  glm::vec3   *getRotation();
  int   getRotationy();
  /*  void	checkFacetteBoxMenu(glm::vec3 *rotation);
  void checkBoxExit(glm::vec3 *rotation);
  void	checkBoxCredit(glm::vec3 *rotation);*/
protected:
  int _i;
  glm::vec3 posSauv;
  glm::vec3 *rot;
};

#endif
