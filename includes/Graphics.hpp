//
// Graphics.hh for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:10:16 2014 thomas mendez
// Last update Tue May 13 08:44:10 2014 Remi telenczak
//

#ifndef		GRAPHICS_HH__
#define		GRAPHICS_HH__

#include	"OVR.h"
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

class		Graphics
{
public:
  Graphics();
  ~Graphics();
  bool		initialize();
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
};

#endif
