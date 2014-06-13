//
// CreditsBox.hpp for CreditsBox in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Fri Jun 13 15:21:19 2014 thomas mendez
// Last update Fri Jun 13 16:51:07 2014 thomas mendez
//

#ifndef		_CREDITSBOX_HPP
# define	_CREDITSBOX_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class CreditsBox : public ABloc
{
public:
  CreditsBox(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
  ICallBack *callRotOcu;
  void	eventRotOcu(void *data);
  void	eventRotOcu2(void *data);
  void	eventRotOcu3(void *data);
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
