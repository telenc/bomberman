//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Mon May 26 16:41:00 2014 dedicker remi
//

#include	<iostream>
#include	"Menu.hpp"
#include	"Skybox.hpp"

Menu::Menu()
{

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
  
}

void	Menu::update(gdl::Clock const &clock, gdl::Input const &input)
{
  (void)clock;
  (void)input;
}

void	Menu::setSkybox(Skybox *skybox)
{
  this->_skin = skybox;
}
