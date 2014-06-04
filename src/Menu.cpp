//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Tue Jun  3 16:38:07 2014 dedicker remi
//

#include	<iostream>
#include	"Menu.hpp"
#include	"Skybox.hpp"
#include	"MainMenu.hpp"

Menu::Menu(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock)
{
  _mainMenu = new MainMenu(mod, event);
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
  _mainMenu->draw(shader, clock);
}

void	Menu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  _mainMenu->update(clock, input, cameraOculus);
}

void	Menu::setSkybox(Skybox *skybox)
{
  _mainMenu->setSkybox(skybox);
}
