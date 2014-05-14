//
// Graphics.cpp for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:12:04 2014 thomas mendez
// Last update Wed May 14 06:44:08 2014 Remi telenczak
//


#include	"OVR.h"
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
#include	"Graphics.hpp"
#include "GL/glut.h"

Graphics::Graphics()
{

}

Graphics::~Graphics()
{

}

void		Graphics::setModelList(ModelList *mod)
{
  this->_modelList = mod;
}

bool		Graphics::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;

  if (!_context.start(1110, 800, "My bomberman!"))
    return false;
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;
  projection = glm::perspective(60.0f, 1280.0f / 800.0f, 0.5f, 200.0f);
  transformation = glm::lookAt(glm::vec3(0, 10, -30), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
  _shader.bind();
  _shader.setUniform("view", transformation);
  _shader.setUniform("projection", projection);
std::cout << "coucdededeou" << std::endl;
//glutInit(0, 0);
  return true;
}
bool		Graphics::update()
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  return true;
}

void		Graphics::draw()
{
  _shader.bind();
  glScissor(0, 0, 680, 800);
  glViewport(0, 0, 680, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);

gdl::Model *test = this->_modelList->getModel("marvin");
glm::mat4 tr(1);
tr = glm::scale(tr, glm::vec3(0.1, 0.1, 0.1));
    test->draw(_shader, tr, 0);


  glScissor(640, 0, 720, 700);
  glViewport(560, 0,720, 800);

  glClearColor(255, 0, 0, 0);
    test->draw(_shader, tr, 0);

  _context.flush();
}
