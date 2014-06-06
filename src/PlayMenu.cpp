//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Fri Jun  6 15:19:15 2014 thomas mendez
//

#include	<iostream>
#include	"PlayMenu.hpp"
#include	"Skybox.hpp"
#include	"CallBack.hpp"
#include	"PlayBox.hpp"

PlayMenu::PlayMenu(ModelList *mod, EventManager *event) : _mod(mod), _event(event)
{
  _boxmenu = new PlayBox(NULL, mod, event, NULL, 1);
  _callKeyA = new CallBack<PlayMenu>(this, &PlayMenu::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  _A = 0;
}

PlayMenu::~PlayMenu()
{
  std::cout << "PlayMenu Destroyed!" << std::endl;
  //delete _callKeyA;
  delete _boxmenu;
}

void	PlayMenu::eventKeyA(void *data)
{
  (void)data;
}

int    PlayMenu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  glm::mat4 t(1);
  int		roty;
  (void)roty;
  roty = _boxmenu->getRotationy();

  t = glm::translate(t, glm::vec3(0, 0, 0));
  t = glm::scale(t, glm::vec3(100, 100, 100));
  _skin->draw(shader, clock);
  //  _menuwall->draw(shader, clock);
  _boxmenu->draw(shader,clock);
  //_menu->draw(shader, clock);
  //  if (this->_A == 1)
  //return this->_A;
  return 2;
}

void	PlayMenu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  _boxmenu->update(clock, input);
  this->_rotationOculus = cameraOculus;
  /*  std::cout << this->_rotationOculus.x << std::endl;
  std::cout << this->_rotationOculus.y << std::endl;
  std::cout << this->_rotationOculus.z << std::endl;*/
  (void)clock;
  (void)input;
}

void	PlayMenu::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
