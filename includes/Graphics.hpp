//
// Graphics.hh for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:10:16 2014 thomas mendez
// Last update Sun Jun 15 20:55:03 2014 thomas mendez
//

#ifndef		GRAPHICS_HH__BOMBER
#define		GRAPHICS_HH__BOMBER

#include	"OVR.h"
# include	"ModelList.hpp"
#include	<iostream>
#include	<string>
#include	<unistd.h>
#include	<SdlContext.hh>
#include	<cstdlib>
#include	<Game.hh>
#include	<Clock.hh>
#include	<Input.hh>
#include	<SdlContext.hh>
#include	<Geometry.hh>
#include	<Texture.hh>
#include	<BasicShader.hh>
#include	<Model.hh>
#include	<OpenGL.hh>
#include	<glm/glm.hpp>
#include	<glm/gtc/matrix_transform.hpp>
# include	"CameraBomber.hpp"
#include	"DefaultWall.hpp"
#include	"Map.hpp"
#include	"EventManager.hpp"

class Player;
class Menu;
class MenuIG;

class AObjectPhysic;
class		Graphics
{
public:
  Graphics(EventManager *);
  ~Graphics();
  bool			initialize();
  void			setModelList(ModelList *model);
  void			draw(Map *);
  bool			update(Map *);
  bool			update(Menu *);
  void			inputUpdate();
  void			drawDoubleStereo(Map *map);
  void			drawDoubleStereo(Menu *menu);
  void			drawOneStereo(Map *map);
  void			drawOneStereo(Menu *menu);
  void			draw(Menu *);
  void			drawDoubleStereo(MenuIG *menu);
  void			drawOneStereo(MenuIG *map);
  void			draw(MenuIG *);
  bool			update(MenuIG *, Map *);
  CameraBomber		*getCamera() const;
  gdl::Clock		*getClock() const;
protected:
  gdl::BasicShader	_shader;
  gdl::Texture		_texture;
  gdl::Clock		*_clock;
  gdl::Input		_input;
  std::vector<AObjectPhysic*>	_objects;
  gdl::SdlContext	_context;
  ModelList		*_modelList;
  CameraBomber		*_camera;
  EventManager		*_event;
  gdl::Model		*sky;
};

#endif
