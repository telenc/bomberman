//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Thu Jun  5 16:38:15 2014 dedicker remi
//

#include	<iostream>
#include	"Menu.hpp"
#include	"Skybox.hpp"
#include	"SettingsMenu.hpp"
#include	"MainMenu.hpp"
#include	"CallBack.hpp"

Menu::Menu(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock)
{
  _mainMenu = new MainMenu(mod, event);
  _settingsMenu = new SettingsMenu(mod, event);
  currentMenu = 0;
  _callKeyA = new CallBack<Menu>(this, &Menu::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
}

void    Menu::eventKeyA(void *data)
{
  std::cout << "A MENU" << std::endl;
  this->callFaceFunction();
  (void)data;
}


Menu::~Menu()
{
  std::cout << "Menu Destroyed!" << std::endl;
}

void	Menu::faceMainMenu()
{
  if (_rotationOculus.x <= 40 && _rotationOculus.x >= -40)
    {
      if (_rotationOculus.y >= -45 && _rotationOculus.y <= 45)
	std::cout << "|-- Image de presentation --|" << std::endl;
      else if (_rotationOculus.y >= 45 && _rotationOculus.y <= 135)
	std::cout << "|-- Image de Play --|" << std::endl;
      else if (_rotationOculus.y <= -45 && _rotationOculus.y >= -135)
	currentMenu = 1;
      //std::cout << "|-- Image de Settings --|" << std::endl;
      else if (_rotationOculus.y >= 135 || _rotationOculus.y <= -135)
	std::cout << "|-- Image de Derriere --|" << std::endl;
      else
	std::cout << "|-- Dans le vide --|" << std::endl;
    }
}

void	Menu::faceSettingsMenu()
{
  if (_rotationOculus.x <= 40 && _rotationOculus.x >= -40)
    {
      if (_rotationOculus.y >= -45 && _rotationOculus.y <= 45)
	std::cout << "|-- Image de presentation --|" << std::endl;
      else if (_rotationOculus.y >= 45 && _rotationOculus.y <= 135)
	std::cout << "|-- Image de Play --|" << std::endl;
      else if (_rotationOculus.y <= -45 && _rotationOculus.y >= -135)
	std::cout << "|-- Image de setting --|" << std::endl;
      else if (_rotationOculus.y >= 135 || _rotationOculus.y <= -135)
	std::cout << "|-- Image de Derriere --|" << std::endl;
      else
	std::cout << "|-- Dans le vide --|" << std::endl;
    }
}

void	Menu::callFaceFunction()
{
  if (this->currentMenu == 0)
    faceMainMenu();
  else if (this->currentMenu == 1)
    faceSettingsMenu();
}

void    Menu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  if (this->currentMenu == 0)
    this->currentMenu = _mainMenu->draw(shader, clock);
  else if (this->currentMenu == 1)
    this->currentMenu = _settingsMenu->draw(shader, clock);
}

void	Menu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  this->_rotationOculus = cameraOculus;
  //  this->callFaceFunction();
  if (this->currentMenu == 0)
    _mainMenu->update(clock, input, cameraOculus);
  else if (this->currentMenu == 1)
    _settingsMenu->update(clock, input, cameraOculus);
}

void	Menu::setSkybox(Skybox *skybox)
{
  _mainMenu->setSkybox(skybox);
  _settingsMenu->setSkybox(skybox);
}
