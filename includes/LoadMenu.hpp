//
// LoadMenu.hpp for LoadMenu in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sat Jun 14 16:48:41 2014 thomas mendez
// Last update Sat Jun 14 17:55:42 2014 thomas mendez
//

#ifndef		_LOAD_MENU
# define	_LOAD_MENU

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
#include	"LoadBox.hpp"

class LoadMenu
{
public:
  LoadMenu(ModelList *mod, EventManager *event);
  ~LoadMenu();
  void	setSkybox(Skybox *skybox);
  void	setBox(gdl::Model *model);
  int  draw(gdl::BasicShader &, gdl::Clock const &);
  void	update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus);
  void	eventKeyA(void *data);
private:
  gdl::Model *_box;
  ModelList *_mod;
  EventManager *_event;
  LoadBox *_boxmenu;
  LoadBox *_boxmenu2;
  LoadBox *_boxmenu3;
  LoadBox *_boxmenu4;
  Skybox *_skin;
  glm::vec3 _rotationOculus;
  ICallBack *_callKeyA;
};

#endif
