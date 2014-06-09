//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Mon Jun  9 16:29:26 2014 Steven Martreux
//

#include	<iostream>
#include	"Menu.hpp"
#include	"Skybox.hpp"
#include	"SettingsMenu.hpp"
#include	"MainMenu.hpp"
#include	"PlayMenu.hpp"
#include	"CallBack.hpp"

Menu::Menu(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock)
{
  _mainMenu = new MainMenu(mod, event);
  _settingsMenu = new SettingsMenu(mod, event);
  _playMenu = new PlayMenu(mod, event);
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
	currentMenu = 2;
      else if (_rotationOculus.y <= -45 && _rotationOculus.y >= -135)
	currentMenu = 1;
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

void	Menu::facePlayMenu()
{
  if (_rotationOculus.x <= 40 && _rotationOculus.x >= -40)
    {
      if (_rotationOculus.y >= -45 && _rotationOculus.y <= 45)
	std::cout << "|-- Image de presentation --|" << std::endl;
      //else if (_rotatiodescendenOculus.y >= 45 && _rotationOculus.y <= 135)
      //	std::cout << "|-- Image de Play --|" << std::endl;
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
  else if (this->currentMenu == 2)
    facePlayMenu();
}

void    Menu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  if (this->currentMenu == 0)
    this->currentMenu = _mainMenu->draw(shader, clock);
  else if (this->currentMenu == 1)
    this->currentMenu = _settingsMenu->draw(shader, clock);
  else if (this->currentMenu == 2)
    this->currentMenu = _playMenu->draw(shader, clock);
}

void	Menu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  this->_rotationOculus = cameraOculus;
  //  this->callFaceFunction();
  if (this->currentMenu == 0)
    _mainMenu->update(clock, input, cameraOculus);
  else if (this->currentMenu == 1)
    _settingsMenu->update(clock, input, cameraOculus);
  else if (this->currentMenu == 2)
  _playMenu->update(clock, input, cameraOculus);
}

void	Menu::setSkybox(Skybox *skybox)
{
  _mainMenu->setSkybox(skybox);
  _settingsMenu->setSkybox(skybox);
  _playMenu->setSkybox(skybox);
}
