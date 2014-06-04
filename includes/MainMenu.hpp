//
// MainMenu.hpp for MainMenu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:19 2014 Remi telenczak
// Last update Tue Jun  3 17:47:59 2014 dedicker remi
//

#ifndef		_MAIN_MENU
# define	_MAIN_MENU

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

class MainMenu
{
public:
  MainMenu(ModelList *mod, EventManager *event);
  ~MainMenu();
  void	setSkybox(Skybox *skybox);
  void	setBox(gdl::Model *model);
  void  draw(gdl::BasicShader &, gdl::Clock const &);
  void	update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus);
  void	eventKeyA(void *data);
private:
  gdl::Model *_box;
  ModelList *_mod;
  EventManager *_event;
  MenuBox *_boxmenu;
  MenuBox *_boxmenu2;
  MenuBox *_boxmenu3;
  Skybox *_skin;
  glm::vec3 _rotationOculus;
  ICallBack *_callKeyA;
};

#endif
