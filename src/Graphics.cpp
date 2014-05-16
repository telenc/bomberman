//
// Graphics.cpp for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:12:04 2014 thomas mendez
// Last update Fri May 16 05:21:55 2014 Remi telenczak
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
  if (_input.getKey(SDLK_e))
    this->_camera->changeStereo(1);
  if (_input.getKey(SDLK_r))
    this->_camera->changeStereo(2);
}

void		Graphics::drawDoubleStereo()
{
  gdl::Model *test = this->_modelList->getModel("cube1");
  gdl::Model *test2 = this->_modelList->getModel("cube4");
  gdl::Model *test3 = this->_modelList->getModel("cube3");
  gdl::Model *test4 = this->_modelList->getModel("cube4");
  gdl::Model *test5 = this->_modelList->getModel("bomb2");
  gdl::Model *test6 = this->_modelList->getModel("cube4");
  glm::mat4 tr(1);
  glm::mat4 trr(1);
  glViewport(0, 0, 1280/2, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);

  _shader.setUniform("view", this->_camera->getTransformationLeft());
  _shader.setUniform("projection", this->_camera->getPerspective());
  trr = glm::translate(trr, glm::vec3(0, -5, 0));
  trr = glm::scale(trr, glm::vec3(100, 1, 100));
  tr = glm::scale(tr, glm::vec3(4, 4, 4));
  tr = glm::translate(tr, glm::vec3(-25, 0, -25));
  test->draw(_shader, tr, 0);
  tr = glm::translate(tr, glm::vec3(2, 0, 0));
  test2->draw(_shader, tr, 0);
  tr = glm::translate(tr, glm::vec3(2, 0, 0));
  test3->draw(_shader, tr, 0);
  tr = glm::translate(tr, glm::vec3(2, 0, 0));
  test4->draw(_shader, tr, 0);
  tr = glm::translate(tr, glm::vec3(2, 0, 0));
  test4->draw(_shader, tr, 0);
  tr = glm::translate(tr, glm::vec3(2, 0, 0));
  test6->draw(_shader, trr, 0);
    tr = glm::translate(tr, glm::vec3(2, 0, 0));
  test2->draw(_shader, tr, 0);

  glViewport(1280/2, 0,1280/2, 800);
  glClearColor(255, 0, 0, 0);
  _shader.setUniform("view", this->_camera->getTransformationRight());
  glm::mat4 tr2(1);

  tr2 = glm::scale(tr2, glm::vec3(4, 4, 4));
  tr2 = glm::translate(tr2, glm::vec3(-25, 0, -25));
  test->draw(_shader, tr2, 0);
  tr2 = glm::translate(tr2, glm::vec3(2, 0, 0));
  test2->draw(_shader, tr2, 0);
  tr2 = glm::translate(tr2, glm::vec3(2, 0, 0));
  test3->draw(_shader, tr2, 0);
  tr2 = glm::translate(tr2, glm::vec3(2, 0, 0));
  test4->draw(_shader, tr2, 0);
  tr2 = glm::translate(tr2, glm::vec3(2, 0,0));
  test4->draw(_shader, tr2, 0);

}

void		Graphics::drawOneStereo()
{
      glViewport(0, 0, 1280, 800);
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      glClearColor(255, 0, 0, 0);

      _shader.setUniform("view", this->_camera->getTransformationLeft());
      _shader.setUniform("projection", this->_camera->getPerspective());
      gdl::Model *test2 = this->_modelList->getModel("cube2");
      glm::mat4 tr11(1);
      test2->draw(_shader, tr11, 0);
      tr11 = glm::translate(tr11, glm::vec3(10, 0, 0));
      tr11 = glm::scale(tr11, glm::vec3(4, 4, 4));
      test2->draw(_shader, tr11, 0);
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
