//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Tue May 27 15:55:28 2014 dedicker remi
//

#include	<iostream>
#include	"Menu.hpp"
#include	"Skybox.hpp"

Menu::Menu(ModelList *mod, EventManager *event) : _mod(mod), _event(event)
{
  _boxmenu = ;
    _menuwall = ;
}

Menu::~Menu()
{
  std::cout << "Menu Destroyed!" << std::endl;
}

void    Menu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  glm::mat4 t(1);
  t = glm::translate(t, glm::vec3(0, 0, 0));
  t = glm::scale(t, glm::vec3(100, 100, 100));
  _skin->draw(shader, clock);
  _menu->draw(shader, clock);
}

void	Menu::update(gdl::Clock const &clock, gdl::Input const &input)
{
  (void)clock;
  (void)input;
}

void	Menu::setSkybox(Skybox *skybox, Skybox *menu)
{
  this->_skin = skybox;
  this->_menu = menu;
  menu->set_x(50);
  menu->set_y(50);
  menu->set_z(50);
  menu->setSkin(_mod->getModel("menu"));
  skybox->setSkin(_mod->getModel("box_menu"));
}
