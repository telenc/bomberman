//
// MenuBoxIG.hpp for MenuBoxIG in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 04:27:10 2014 thomas mendez
// Last update Sun Jun 15 04:27:35 2014 thomas mendez
//

#ifndef		_MENUBOXIG_HPP
# define	_MENUBOXIG_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class MenuBoxIG : public ABloc
{
public:
  MenuBoxIG(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
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
