//
// Graphics.hh for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:10:16 2014 thomas mendez
// Last update Wed May 14 08:01:20 2014 Remi telenczak
//

#ifndef		GRAPHICS_HH__BOMBER
#define		GRAPHICS_HH__BOMBER

#include	"OVR.h"
# include	"ModelList.hpp"
#include	<iostream>
#include	<string>
#include	<unistd.h>
#include	<SdlContext.hh>
#include	"AObjectPhysic.hpp"
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

class		Graphics
{
public:
  Graphics();
  ~Graphics();
bool		initialize();
void		setModelList(ModelList *model);
void		draw();
  bool		update();
protected:
  gdl::BasicShader	_shader;
  gdl::Texture		_texture;
  gdl::Clock		_clock;
  gdl::Input		_input;
  std::vector<AObjectPhysic*>	_objects;
  gdl::SdlContext	_context;
  gdl::Model		*test;
  ModelList *_modelList;
  CameraBomber	       *_camera;
};

#endif
