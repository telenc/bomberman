//
// SettingsMenu.cpp for SettingsMenu in /home/mendez_t/local/cpp/cpp_bomberman/src
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Wed Jun  4 12:24:31 2014 thomas mendez
// Last update Sun Jun 15 23:23:41 2014 dedicker remi
//

#include	<iostream>
#include	"SettingsMenu.hpp"
#include	"Skybox.hpp"
#include	"CallBack.hpp"
#include	"SettingBox.hpp"

SettingsMenu::SettingsMenu(ModelList *mod, EventManager *event) : _mod(mod), _event(event)
{
  _boxmenu = new SettingBox(NULL, mod, event, NULL, 1);
  _callKeyA = new CallBack<SettingsMenu>(this, &SettingsMenu::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  std::cout << "SettingsMenu create" << std::endl;
}

SettingsMenu::~SettingsMenu()
{
  std::cout << "SettingsMenu Destroyed!" << std::endl;
  delete _callKeyA;
  delete _boxmenu;
}

void	SettingsMenu::eventKeyA(void *data)
{
  std::cout << "A Press" << std::endl;
  (void)data;
}

int    SettingsMenu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  std::cout << "SettingsMenu draw 1" << std::endl;
  glm::mat4 t(1);
  int		roty;
  (void)roty;

  t = glm::translate(t, glm::vec3(0, 0, 0));
  t = glm::scale(t, glm::vec3(100, 100, 100));
  _skin->draw(shader, clock);
  _boxmenu->draw(shader,clock);
  std::cout << "SettingsMenu draw 2" << std::endl;
  return 1;
}

void	SettingsMenu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  std::cout << "SettingsMenu update 1" << std::endl;
  _boxmenu->update(clock, input);
  this->_rotationOculus = cameraOculus;
  (void)clock;
  (void)input;
  std::cout << "SettingsMenu update 2" << std::endl;
}

void	SettingsMenu::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
