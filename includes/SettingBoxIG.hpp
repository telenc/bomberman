//
// SettingBoxIG.hpp for SettingBoxIG in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 04:37:45 2014 thomas mendez
// Last update Sun Jun 15 19:38:31 2014 Steven Martreux
//

#ifndef		_SETTINGBOXIG_HPP
# define	_SETTINGBOXIG_HPP

# include	"ABloc.hpp"
# include	"CallBack.hpp"

class SettingBoxIG : public ABloc
{
public:
  SettingBoxIG(Map *, ModelList *, EventManager *, gdl::Clock *, int i);
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
