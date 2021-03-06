//
// Graphics.cpp for Graphics in /home/mendez_t/local/cpp/cpp_bomberman/AllTest/testGdl+OCCULUS
//
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
//
// Started on  Tue May 13 15:12:04 2014 thomas mendez
// Last update Sun Jun 15 23:21:23 2014 dedicker remi
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
#include	"Map.hpp"
#include	"GL/glut.h"
#include	"Player.hpp"
#include	"Menu.hpp"
#include	"MenuIG.hpp"


Graphics::Graphics(EventManager *event) : _event(event)
{
  _clock = new gdl::Clock;
}

Graphics::~Graphics()
{

}

CameraBomber	*Graphics::getCamera() const
{
  return _camera;
}

void		Graphics::setModelList(ModelList *mod)
{
  this->_modelList = mod;
  this->sky = mod->getModel("box");
}

gdl::Clock *Graphics::getClock() const
{
  return this->_clock;
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
  this->_camera = new CameraBomber(&_shader, _event, this->_clock);
  _shader.bind();
  return true;
}

bool		Graphics::update(Map *map)
{
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  if (_input.getKey(SDLK_a))
      this->_camera->rot -= 0.1;
  if (map->isFinish())
    return false;
  if (_input.getKey(SDLK_z))
      this->_camera->rot += 0.1;
  _context.updateClock(*_clock);
  _context.updateInputs(_input);
  map->update(*_clock, _input);
  return true;
}

void		Graphics::inputUpdate()
{
  if (_input.getKey(SDLK_UP))
    this->_event->dispatchEvent("keyUp", NULL);
  if (_input.getKey(SDLK_w))
    this->_event->dispatchEvent("pause", NULL);
  if (_input.getKey(SDLK_DOWN))
    this->_event->dispatchEvent("keyDown", NULL);
  if (_input.getKey(SDLK_LEFT))
    this->_event->dispatchEvent("keyLeft", NULL);
  if (_input.getKey(SDLK_RIGHT))
    this->_event->dispatchEvent("keyRight", NULL);
  if (_input.getKey(SDLK_q))
    this->_event->dispatchEvent("rotateLeft", NULL);
  if (_input.getKey(SDLK_d))
    this->_event->dispatchEvent("rotateRight", NULL);
  if (_input.getKey(SDLK_SPACE))
    this->_event->dispatchEvent("keyA", NULL);
  if (_input.getKey(SDLK_m))
    this->_camera->translate(0, 1.0, 0);
  if (_input.getKey(SDLK_p))
    this->_camera->translate(0, -1.0, 0);
  if (_input.getKey(SDLK_e))
    this->_camera->changeStereo(1);
  if (_input.getKey(SDLK_r))
    this->_camera->changeStereo(2);
  if (_input.getKey(SDLK_i))
    this->_camera->changeStereoo(-1);
  if (_input.getKey(SDLK_o))
    this->_camera->changeStereoo(1);
  if (_input.getKey(SDLK_j))
    this->_camera->changeStereooo(-1);
  if (_input.getKey(SDLK_k))
    this->_camera->changeStereooo(1);
}

void		Graphics::drawDoubleStereo(Map *map)
{
  glm::vec3	rotationOc;

  glViewport(0, 0, 1280/2, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);
  rotationOc = this->_camera->getRotation();
  _event->dispatchEvent("occulusRotate", &rotationOc);
  _shader.setUniform("view", this->_camera->getTransformationLeft());
  _shader.setUniform("projection", this->_camera->getPerspective());
  map->draw(_shader, *_clock, _camera);
  glViewport(1280/2, 0,1280/2, 800);
  glClearColor(255, 0, 0, 0);
  _shader.setUniform("view", this->_camera->getTransformationRight());
  map->draw(_shader, *_clock, _camera);
}

void		Graphics::drawOneStereo(Map *map)
{
  glViewport(0, 0, 1280, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);
  map->draw(_shader, *_clock, this->_camera);
  _shader.setUniform("projection", this->_camera->getPerspective());
  _shader.setUniform("view", this->_camera->getTransformation());
}

void		Graphics::draw(Map *map)
{
  _shader.bind();
  usleep(2000);
  if (this->_camera->getStereo() == 2)
    drawDoubleStereo(map);
  else
    drawOneStereo(map);
  _context.flush();
}

void            Graphics::draw(Menu *menu)
{
  _shader.bind();
  if (this->_camera->getStereo() == 2)
    drawDoubleStereo(menu);
  else
    drawOneStereo(menu);
  _context.flush();
}

void            Graphics::drawOneStereo(Menu *menu)
{
  glViewport(0, 0, 1280, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 0, 0);
  menu->draw(_shader, *_clock);
  _shader.setUniform("projection", this->_camera->getPerspective());
  _shader.setUniform("view", this->_camera->getTransformation());
}

bool	Graphics::update(Menu *menu)
{
  glm::vec3 rotationOculus;

  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(*_clock);
  _context.updateInputs(_input);
  rotationOculus = _camera->getRotation();
  menu->update(*_clock, _input, rotationOculus);
  this->inputUpdate();
  _event->dispatchEvent("rotOcu", &rotationOculus);
  return true;
}


void            Graphics::draw(MenuIG *menu)
{
  _shader.bind();
  if (this->_camera->getStereo() == 2)
    drawDoubleStereo(menu);
  else
    drawOneStereo(menu);
  _context.flush();
}

void            Graphics::drawOneStereo(MenuIG *menu)
{
  glViewport(0, 0, 1280, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 0, 0);
  menu->draw(_shader, *_clock);
  _shader.setUniform("projection", this->_camera->getPerspective());
  _shader.setUniform("view", this->_camera->getTransformation());
}

bool	Graphics::update(MenuIG *menu, Map *map)
{
  glm::vec3 rotationOculus;

  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return false;
  _context.updateClock(*_clock);
  _context.updateInputs(_input);
  rotationOculus = _camera->getRotation();
  menu->update(*_clock, _input, rotationOculus, map);
  this->inputUpdate();
  _event->dispatchEvent("rotOcu", &rotationOculus);
  return true;
}

void		Graphics::drawDoubleStereo(MenuIG *menu)
{
  glm::vec3	rotOculus;

  this->_camera->setPosition(0,  0, 0);
  glViewport(0, 0, 1280/2, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);
  rotOculus = this->_camera->getRotation();
  _event->dispatchEvent("occulusRotate", &rotOculus);
  _shader.setUniform("view", this->_camera->getTransformationLeft());
  _shader.setUniform("projection", this->_camera->getPerspective());
  menu->draw(_shader, *_clock);
  glViewport(1280/2, 0,1280/2, 800);
  glClearColor(255, 0, 0, 0);
  _shader.setUniform("view", this->_camera->getTransformationRight());
  menu->draw(_shader, *_clock);
}

void		Graphics::drawDoubleStereo(Menu *menu)
{
  glm::vec3	rotOculus;

  this->_camera->setPosition(0,  0, 0);
  glViewport(0, 0, 1280/2, 800);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glClearColor(255, 0, 0, 0);
  rotOculus = this->_camera->getRotation();
  _event->dispatchEvent("occulusRotate", &rotOculus);
  _shader.setUniform("view", this->_camera->getTransformationLeft());
  _shader.setUniform("projection", this->_camera->getPerspective());
  menu->draw(_shader, *_clock);
  glViewport(1280/2, 0,1280/2, 800);
  glClearColor(255, 0, 0, 0);
  _shader.setUniform("view", this->_camera->getTransformationRight());
  menu->draw(_shader, *_clock);
}
