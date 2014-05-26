//
// Menu.hpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:19 2014 Remi telenczak
// Last update Mon May 26 17:21:43 2014 dedicker remi
//

#ifndef		_MENU_BOMBERMAN
# define	_MENU_BOMBERMAN

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

class Menu
{
public:
  Menu(ModelList *mod, EventManager *event);
  ~Menu();
  void	setSkybox(Skybox *skybox);
  void  draw(gdl::BasicShader &, gdl::Clock const &);
  void	update(gdl::Clock const &clock, gdl::Input const &input);
private:
  ModelList *_mod;
  EventManager *_event;
  Skybox *_skin;
};

#endif
