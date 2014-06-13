//
// CreditsMenu.cpp for CreditsMenu in /home/mendez_t/local/cpp/cpp_bomberman/src
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Fri Jun 13 15:08:46 2014 thomas mendez
// Last update Fri Jun 13 16:17:29 2014 thomas mendez
//

#include	<iostream>
#include	"CreditsMenu.hpp"
#include	"Skybox.hpp"
#include	"CallBack.hpp"
#include	"CreditsBox.hpp"

CreditsMenu::CreditsMenu(ModelList *mod, EventManager *event) : _mod(mod), _event(event)
{
  _boxmenu = new CreditsBox(NULL, mod, event, NULL, 1);
  _boxmenu2 = new CreditsBox(NULL, mod, event, NULL, 2);
  _boxmenu3 = new CreditsBox(NULL, mod, event, NULL, 3);
  _callKeyA = new CallBack<CreditsMenu>(this, &CreditsMenu::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  std::cout << "CreditsMenu create" << std::endl;
}

CreditsMenu::~CreditsMenu()
{
  std::cout << "CreditsMenu Destroyed!" << std::endl;
  delete _callKeyA;
  delete _boxmenu;
}

void	CreditsMenu::eventKeyA(void *data)
{
  std::cout << "A Press" << std::endl;
  (void)data;
}

int    CreditsMenu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  std::cout << "CreditsMenu draw 1" << std::endl;
  glm::mat4 t(1);
  int		roty;
  (void)roty;

  //  roty = _boxmenu->getRotationy();
  t = glm::translate(t, glm::vec3(0, 0, 0));
  t = glm::scale(t, glm::vec3(100, 100, 100));
  _skin->draw(shader, clock);
  //  _menuwall->draw(shader, clock);
  _boxmenu->draw(shader,clock);
  _boxmenu2->draw(shader,clock);
  _boxmenu3->draw(shader,clock);
  //_menu->draw(shader, clock);
  std::cout << "CreditsMenu draw 2" << std::endl;
  return 4;
}

void	CreditsMenu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  std::cout << "CreditsMenu update 1" << std::endl;
  _boxmenu->update(clock, input);
  this->_rotationOculus = cameraOculus;
  /*  std::cout << this->_rotationOculus.x << std::endl;
      std::cout << this->_rotationOculus.y << std::endl;
      std::cout << this->_rotationOculus.z << std::endl;*/
  (void)clock;
  (void)input;
  std::cout << "CreditsMenu update 2" << std::endl;
}

void	CreditsMenu::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
