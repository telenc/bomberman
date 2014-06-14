//
// Menu.cpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:00 2014 Remi telenczak
// Last update Sat Jun 14 17:11:33 2014 thomas mendez
// Last update Fri Jun 13 15:51:35 2014 thomas mendez
//

#include	<iostream>
#include	"Menu.hpp"
#include	"Skybox.hpp"
#include	"SettingsMenu.hpp"
#include	"MainMenu.hpp"
#include	"PlayMenu.hpp"
#include	"MenuNumber.hpp"
#include	"CallBack.hpp"

Menu::Menu(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock), _finish(1), _sound(1), _gomap(0)
{
  std::cout << "Debut constructeur MEnu" << std::endl;
  _mainMenu = new MainMenu(mod, event);
  _loadMenu = new LoadMenu(mod, event);
  _settingsMenu = new SettingsMenu(mod, event);
  _creditsMenu = new CreditsMenu(mod, event);
  _MenuNumber = new MenuNumber(mod, event, clock);
  _playMenu = new PlayMenu(mod, event);
  currentMenu = 0;
  _callKeyA = new CallBack<Menu>(this, &Menu::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  _callKeyB = new CallBack<Menu>(this, &Menu::eventKeyB);
  event->listenEvent("keyB", _callKeyB);  
  std::cout << "Fin constructeur MEnu" << std::endl;
}

void	Menu::setFinish(int finish)
{
  this->_finish = finish;
}

void    Menu::eventKeyB(void *data)
{
  currentMenu = 0;
  switch (currentMenu)
    {
    case 3:
      currentMenu -= 1;
      break;
    case 4:
      currentMenu -= 1;
      break;
    default:
      currentMenu = 0;
      break;
    }
  (void)data;
}

void    Menu::eventKeyA(void *data)
{
  std::cout << "A MENU" << std::endl;
  this->callFaceFunction();
  (void)data;
  if (currentMenu == 3)
    {
      _sizemap = _MenuNumber->getResult();
      std::cout << "Taille de la map = " << _sizemap << std::endl;
      //currentMenu++;
    }
  if (currentMenu == 4)
    {
      _numberia = _MenuNumber->getResult();
      std::cout << "Number IA = " << _numberia << std::endl;
      // currentMenu++;
    }
}

int	Menu::getGoMap()
{
  return this->_gomap;
}

int	Menu::getFinish()
{
  return _finish;
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
	std::cout << "|-- Image de presentation --|b" << std::endl;
      else if (_rotationOculus.y >= 45 && _rotationOculus.y <= 135)
	currentMenu = 2;
      else if (_rotationOculus.y <= -45 && _rotationOculus.y >= -135)
	currentMenu = 1;
      else if (_rotationOculus.y >= 135 || _rotationOculus.y <= -135)
	std::cout << "|-- Image de Derriere --|b" << std::endl;
    }
  else if (_rotationOculus.y >= -15)
    {
      if (_rotationOculus.x >= 60 && _rotationOculus.x <= 90)
	_finish = 0;
    }
  if (_rotationOculus.x <= -50 && _rotationOculus.x >= -90)
    {
      std::cout << "|-- Image de Credit! --|" << std::endl; 
      currentMenu = 4;
    }
}

void	Menu::faceSettingsMenu()
{
  if (_rotationOculus.x <= 40 && _rotationOculus.x >= -40)
    {
      if (_rotationOculus.y >= -45 && _rotationOculus.y <= 45)
	std::cout << "|- - Image de presentation - -|" << std::endl;
      else if (_rotationOculus.y >= 45 && _rotationOculus.y <= 135)
	this->_event->dispatchEvent("soundon", NULL);
      else if (_rotationOculus.y <= -45 && _rotationOculus.y >= -135)
	this->_event->dispatchEvent("soundoff", NULL);
      else if (_rotationOculus.y >= 135 || _rotationOculus.y <= -135)
	std::cout << "|- - Image de Derriere - -|" << std::endl;
      else
	currentMenu = 0;
    }
  else
    currentMenu = 0;
}

void	Menu::facePlayMenu()
{
  if (_rotationOculus.x <= 40 && _rotationOculus.x >= -40)
    {
      if (_rotationOculus.y >= -45 && _rotationOculus.y <= 45)
	{
	  std::cout << "L|-- Play Game --|" << std::endl;
	  currentMenu = 3;
	}
      else if (_rotationOculus.y >= 45 && _rotationOculus.y <= 135)
	{
	  std::cout << "L|-- Load Game --|" << std::endl;
	}
      else if (_rotationOculus.y <= -45 && _rotationOculus.y >= -135)
	{
	  currentMenu = 5;
	  std::cout << "L|-- Load Game --|" << std::endl;
	}
      else if (_rotationOculus.y >= 135 || _rotationOculus.y <= -135)
	std::cout << "L|-- Image de Derriere --|" << std::endl;
    }
  else
    currentMenu = 0;
}

void	Menu::faceSizeMap()
{
  _sizemap = _MenuNumber->getResult();
  currentMenu++;
}

void	Menu::faceNumberIa()
{
  _numberia = _MenuNumber->getResult();
  _gomap = 1;
}

void	Menu::callFaceFunction()
{
  if (this->currentMenu == 0)
    faceMainMenu();
  else if (this->currentMenu == 1)
    faceSettingsMenu();
  else if (this->currentMenu == 2)
    facePlayMenu();
  else if (this->currentMenu == 3)
    faceSizeMap();
  else if (this->currentMenu == 4)
    faceNumberIa();
}

int	Menu::getSizemap()
{
  return this->_sizemap;
}

int	Menu::getNumberIa()
{
  return this->_numberia;
}

void    Menu::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  if (this->currentMenu == 0)
    this->currentMenu = _mainMenu->draw(shader, clock);
  else if (this->currentMenu == 1)
    this->currentMenu = _settingsMenu->draw(shader, clock);
  else if (this->currentMenu == 2)
    this->currentMenu = _playMenu->draw(shader, clock);
  else if (this->currentMenu == 3)
    this->currentMenu = _MenuNumber->draw(shader, clock);
  else if (this->currentMenu == 4)
    this->currentMenu = _creditsMenu->draw(shader, clock);
  else if (this->currentMenu == 5)
    this->currentMenu = _loadMenu->draw(shader, clock);
}

void	Menu::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  this->_rotationOculus = cameraOculus;
  if (this->currentMenu == 0)
    _mainMenu->update(clock, input, cameraOculus);
  else if (this->currentMenu == 1)
    _settingsMenu->update(clock, input, cameraOculus);
  else if (this->currentMenu == 2)
    _playMenu->update(clock, input, cameraOculus);
  else if (this->currentMenu == 3)
    _MenuNumber->update(clock, input);
  else if (this->currentMenu == 4)
    _creditsMenu->update(clock, input, cameraOculus);
  else if (this->currentMenu == 5)
    _loadMenu->update(clock, input, cameraOculus);
}

void	Menu::setSkybox(Skybox *skybox)
{
  _mainMenu->setSkybox(skybox);
  _settingsMenu->setSkybox(skybox);
  _playMenu->setSkybox(skybox);
  _MenuNumber->setSkybox(skybox);
  _creditsMenu->setSkybox(skybox);
  _loadMenu->setSkybox(skybox);
}
