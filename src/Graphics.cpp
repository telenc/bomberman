//
// Graphics.cpp for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:12:04 2014 thomas mendez
// Last update Thu May 15 05:47:37 2014 Remi telenczak
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

  if (!_context.start(1280, 800, "My bomberman!"))
    return false;
  glMatrixMode(GL_PROJECTION);
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return false;

  _shader.bind();
  this->_camera = new CameraBomber(&_shader);

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
  if (_input.getKey(SDLK_UP))
    this->_camera->translate(0, 0, -1);
  if (_input.getKey(SDLK_DOWN))
    this->_camera->translate(0, 0, 1);
  if (_input.getKey(SDLK_LEFT))
    this->_camera->translate(-1, 0, 0);
  if (_input.getKey(SDLK_RIGHT))
    this->_camera->translate(1, 0, 0);
  if (_input.getKey(SDLK_a))
    this->_camera->changeRot(0.01);
  if (_input.getKey(SDLK_z))
    this->_camera->changeRot(-0.01);





  _shader.bind();

  glScissor(0, 0, 680, 800);
  glViewport(0, 0, 680, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);

  _shader.setUniform("view", this->_camera->getTransformationLeft());
  _shader.setUniform("projection", this->_camera->getTest());

  gdl::Model *test = this->_modelList->getModel("wall");
  glm::mat4 tr(1);
  test->draw(_shader, tr, 0);
  tr = glm::translate(tr, glm::vec3(10, 0, 0));
  test->draw(_shader, tr, 0);

  glScissor(640, 0, 720, 700);
  glViewport(560, 0,720, 800);
  glClearColor(255, 0, 0, 0);
  _shader.setUniform("view", this->_camera->getTransformationRight());
  glm::mat4 tr2(1);
  test->draw(_shader, tr2, 0);
  tr2 = glm::translate(tr2, glm::vec3(10, 0, 0));
  test->draw(_shader, tr2, 0);

  _context.flush();
}
