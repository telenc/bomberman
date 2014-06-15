//
// SettingsMenu.hpp for SettingsMenu in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Wed Jun  4 11:38:08 2014 thomas mendez
// Last update Sun Jun 15 19:42:01 2014 Steven Martreux
//

#ifndef		_SETTINGS_MENU
# define	_SETTINGS_MENU

#include        "OVR.h"
# include       "ModelList.hpp"
#include        <iostream>
#include        <string>
#include        <unistd.h>
#include        <SdlContext.hh>
#include        <cstdlib>
#include        <Game.hh>
#include        <Clock.hh>
#include        <Input.hh>
#include        <SdlContext.hh>
#include        <Geometry.hh>
#include        <Texture.hh>
#include        <BasicShader.hh>
#include        <Model.hh>
#include        <OpenGL.hh>
#include        <glm/glm.hpp>
#include        <glm/gtc/matrix_transform.hpp>
# include       "CameraBomber.hpp"
#include        "DefaultWall.hpp"
#include        "Map.hpp"
#include        "EventManager.hpp"
#include	"Skybox.hpp"
#include	"MenuBox.hpp"
#include	"MenuWall.hpp"
#include	"CallBack.hpp"
#include	"SettingBox.hpp"

class SettingsMenu
{
public:
  SettingsMenu(ModelList *mod, EventManager *event);
  ~SettingsMenu();
  void		setSkybox(Skybox *skybox);
  void		setBox(gdl::Model *model);
  int		draw(gdl::BasicShader &, gdl::Clock const &);
  void		update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus);
  void		eventKeyA(void *data);
private:
  gdl::Model	*_box;
  ModelList	*_mod;
  EventManager	*_event;
  SettingBox	*_boxmenu;
  Skybox	*_skin;
  glm::vec3	_rotationOculus;
  ICallBack	*_callKeyA;
};

#endif
