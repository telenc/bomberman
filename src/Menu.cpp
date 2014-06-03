//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
<<<<<<< HEAD
// Last update Tue Jun  3 07:24:58 2014 Remi telenczak
=======
// Last update Mon Jun  2 18:35:11 2014 thomas mendez
>>>>>>> f8c3636b7bbd7447af40c21fcd82e71635a0e91c
//

#include	<iostream>
#include	"Menu.hpp"
#include	"Skybox.hpp"

Menu::Menu(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock)
{
  //_menuBox = new MenuNumber(mod, event, clock);
  _boxmenu = new MenuBox(NULL, mod, event, NULL, 1);
  _boxmenu2 = new MenuBox(NULL, mod, event, NULL, 2);
  _boxmenu3 = new MenuBox(NULL, mod, event, NULL, 3);
  //_menuwall = new MenuWall(NULL, mod, event, NULL);
}

Menu::~Menu()
{
  std::cout << "Menu Destroyed!" << std::endl;
}

void    Menu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  glm::mat4 t(1);
  int		roty;

  roty = _boxmenu->getRotationy();
  std::cout << "dans la classe menu : " << roty << std::endl;
  t = glm::translate(t, glm::vec3(0, 0, 0));
  t = glm::scale(t, glm::vec3(100, 100, 100));

  //  _menuwall->draw(shader, clock);
  _boxmenu->draw(shader,clock);
  _boxmenu2->draw(shader,clock);
  _boxmenu3->draw(shader,clock);
  //_menu->draw(shader, clock);

  _skin->draw(shader, clock);
  //_menuBox->draw(shader, clock);
}

void	Menu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  _boxmenu->update(clock, input);
  _boxmenu2->update(clock, input);
  this->_rotationOculus = cameraOculus;
  std::cout << this->_rotationOculus.x << std::endl;
  std::cout << this->_rotationOculus.y << std::endl;
  std::cout << this->_rotationOculus.z << std::endl;
  (void)clock;
  (void)input;
  //_menuBox->update(clock, input);
}

void	Menu::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
  skybox->setSkin(_mod->getModel("box_menu"));
}
