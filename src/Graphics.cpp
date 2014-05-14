//
// Graphics.cpp for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:12:04 2014 thomas mendez
// Last update Wed May 14 03:37:24 2014 Remi telenczak
//


#include	"OVR.h"
#include	<iostream>
#include	<string>
#include	<unistd.h>
#include	<SdlContext.hh>
//#include	"AObject.hpp"
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
//#include	"Cube.hpp"
#include	"Graphics.hpp"

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

bool		Graphics::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;

  if (!_context.start(1110, 800, "My bomberman!"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER) // le fragment shader se
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER) // le vertex
      || !_shader.build()) // il faut ensuite compiler son shader
    return false;
  projection = glm::perspective(60.0f, 1280.0f / 800.0f, 0.5f, 200.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);

  return true;
}
bool		Graphics::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;

  _context.updateClock(_clock);
  _context.updateInputs(_input);

  //for (size_t i = 0; i < _objects.size(); ++i)
  //  _objects[i]->update(_clock, _input);
  return true;
}

void		Graphics::draw()
{
  glm::mat4 transformation;
  glm::mat4 tr(1);
  glm::vec3 _rotation(90, 180, 90);

  tr = glm::rotate(tr, _rotation.y, glm::vec3(0, 1, 0));
  tr = glm::scale(tr, glm::vec3(0.01, 0.01, 0.01));
  glScissor(0, 0, 680, 800);
  glViewport(0, 0, 680, 800);
  glClearColor(255, 0, 0, 0);

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();

  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);
  _shader.setUniform("view", transformation);
  //
  glScissor(640, 0, 720, 700);
  glViewport(560, 0,720, 800);
  glScissor(640, 0, 720, 700);
  glViewport(560, 0,720, 800);
  _shader.setUniform("view", transformation);
  //glTranslatef(0, -1, 0);
  glClearColor(255, 0, 0, 0);
  //


  for (size_t i = 0; i < _objects.size(); ++i)
    _objects[i]->draw(_shader, _clock);


  _context.flush();
}
