//
// SettingBox.hpp for wall in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:28:07 2014 Remi telenczak
// Last update Wed Jun  4 17:35:15 2014 dedicker remi
//

#ifndef		_SETTINGBOX_HPP
# define	_SETTINGBOX_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class SettingBox : public ABloc
{
public:
  SettingBox(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  virtual bool fireTouch();
  ICallBack *callRotOcu;
  void	eventRotOcu(void *data);
  /*void	eventRotOcu2(void *data);
  void	eventRotOcu3(void *data);*/
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