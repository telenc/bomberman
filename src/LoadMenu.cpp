//
// LoadMenu.cpp for LoadMenu in /home/mendez_t/local/cpp/cpp_bomberman/src
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Wed Jun  4 12:24:31 2014 thomas mendez
// Last update Sun Jun 15 06:32:29 2014 dedicker remi
//

#include	<iostream>
#include	"LoadMenu.hpp"
#include	"Skybox.hpp"
#include	"CallBack.hpp"
#include	"LoadBox.hpp"

LoadMenu::LoadMenu(ModelList *mod, EventManager *event) : _mod(mod), _event(event)
{
  _boxmenu = new LoadBox(NULL, mod, event, NULL, 1);
  _boxmenu2 = new LoadBox(NULL, mod, event, NULL, 2);
  _boxmenu3 = new LoadBox(NULL, mod, event, NULL, 3);
  _boxmenu4 = new LoadBox(NULL, mod, event, NULL, 4);
  _callKeyA = new CallBack<LoadMenu>(this, &LoadMenu::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  std::cout << "LoadMenu create" << std::endl;
}

LoadMenu::~LoadMenu()
{
  std::cout << "LoadMenu Destroyed!" << std::endl;
  delete _callKeyA;
  delete _boxmenu;
}

void	LoadMenu::eventKeyA(void *data)
{
  std::cout << "A Press" << std::endl;
  (void)data;
}

int    LoadMenu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
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
  _boxmenu4->draw(shader,clock);
  //  _boxmenu2->draw(shader,clock);
  //_boxmenu3->draw(shader,clock);
  //_menu->draw(shader, clock);
  return 5;
}

void	LoadMenu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  _boxmenu->update(clock, input);
  _boxmenu2->update(clock, input);
  _boxmenu3->update(clock, input);
  _boxmenu4->update(clock, input);
  this->_rotationOculus = cameraOculus;
  /*  std::cout << this->_rotationOculus.x << std::endl;
      std::cout << this->_rotationOculus.y << std::endl;
      std::cout << this->_rotationOculus.z << std::endl;*/
  (void)clock;
  (void)input;
}

void	LoadMenu::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
