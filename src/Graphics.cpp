//
// Graphics.cpp for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:12:04 2014 thomas mendez
// Last update Fri May 16 07:39:19 2014 Remi telenczak
//


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
  this->test = new DefaultWall(NULL, mod, NULL);
  this->test2 = new DefaultWall(NULL, mod, NULL);
}

bool		Graphics::initialize()
{
  glm::mat4 projection;
  glm::mat4 transformation;

  if (!_context.start(1280, 800, "My bomberman!"))
    return false;
  glMatrixMode(GL_PROJECTION);
  glEnable(GL_DEPTH_TEST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
 glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
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
  this->inputUpdate();
  return true;
}

void		Graphics::inputUpdate()
{
  if (_input.getKey(SDLK_UP))
    this->test2->translate(glm::vec3(0, 0, -0.01));
  if (_input.getKey(SDLK_DOWN))
    this->test2->translate(glm::vec3(0, 0, 0.01));
  if (_input.getKey(SDLK_LEFT))
    this->test2->translate(glm::vec3(-0.01, 0, 0));
  if (_input.getKey(SDLK_RIGHT))
    this->test2->translate(glm::vec3(0.01, 0, 0));
  if (_input.getKey(SDLK_a))
    this->_camera->changeRot(0.01);
  if (_input.getKey(SDLK_z))
    this->_camera->changeRot(-0.01);
  if (_input.getKey(SDLK_e))
    this->_camera->changeStereo(1);
  if (_input.getKey(SDLK_r))
    this->_camera->changeStereo(2);
}

void		Graphics::drawDoubleStereo()
{
  glViewport(0, 0, 1280/2, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);

  _shader.setUniform("view", this->_camera->getTransformationLeft());
  _shader.setUniform("projection", this->_camera->getPerspective());



  glViewport(1280/2, 0,1280/2, 800);
  glClearColor(255, 0, 0, 0);
  _shader.setUniform("view", this->_camera->getTransformationRight());

}

void		Graphics::drawOneStereo()
{
      glViewport(0, 0, 1280, 800);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(255, 0, 0, 0);

      _shader.setUniform("view", this->_camera->getTransformationLeft());
      _shader.setUniform("projection", this->_camera->getPerspective());
      this->test->draw(_shader, _clock);
      this->test2->draw(_shader, _clock);
      std::cout << test->collision(test2) << std::endl;
}

void		Graphics::draw()
{
  _shader.bind();

  if (this->_camera->getStereo() == 2)
    drawDoubleStereo();
  else
    drawOneStereo();
  _context.flush();
}
