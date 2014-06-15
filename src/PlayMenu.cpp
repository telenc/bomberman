//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Sun Jun 15 23:24:27 2014 dedicker remi
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
  _boxmenu->draw(shader,clock);
  return 2;
}

void	PlayMenu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  _boxmenu->update(clock, input);
  this->_rotationOculus = cameraOculus;
  (void)clock;
  (void)input;
}

void	PlayMenu::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
