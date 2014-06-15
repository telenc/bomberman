//
// MenuIG.cpp for MenuIG in /home/mendez_t/local/cpp/cpp_bomberman/src
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 03:43:30 2014 thomas mendez
// Last update Sun Jun 15 03:45:03 2014 thomas mendez
//

#include	<iostream>
#include	"MenuIG.hpp"
#include	"Skybox.hpp"
#include	"SettingsMenuIG.hpp"
#include	"MainMenuIG.hpp"
#include	"PlayMenuIG.hpp"
#include	"MenuIGNumber.hpp"
#include	"CallBack.hpp"

MenuIG::MenuIG(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock), _finish(1), _sound(1), _gomap(0)
{
  std::cout << "Debut constructeur MEnu" << std::endl;
  _mainMenuIG = new MainMenuIG(mod, event);
  _loadMenuIG = new LoadMenuIG(mod, event);
  _settingsMenuIG = new SettingsMenuIG(mod, event);
  _creditsMenuIG = new CreditsMenuIG(mod, event);
  std::cout << "Debut IA" << std::endl;
  _MenuIGNumberia = new MenuIGNumber(mod, event, clock);
  std::cout << "Debut MAP" << std::endl;
  _MenuIGNumbermap = new MenuIGNumber(mod, event, clock);
  std::cout << "FIn" << std::endl;
  _playMenuIG = new PlayMenuIG(mod, event);
  currentMenuIG = 0;
  _callKeyA = new CallBack<MenuIG>(this, &MenuIG::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  _callKeyB = new CallBack<MenuIG>(this, &MenuIG::eventKeyB);
  event->listenEvent("keyB", _callKeyB);  
  std::cout << "Fin constructeur MEnu" << std::endl;
}

void	MenuIG::setFinish(int finish)
{
  this->_finish = finish;
}

void    MenuIG::eventKeyB(void *data)
{
  currentMenuIG = 0;
  switch (currentMenuIG)
    {
    case 3:
      currentMenuIG -= 1;
      break;
    case 4:
      currentMenuIG -= 1;
      break;
    default:
      currentMenuIG = 0;
      break;
    }
  (void)data;
}

void    MenuIG::eventKeyA(void *data)
{
  std::cout << "Avant  -> " << currentMenuIG << std::endl;
  if (currentMenuIG == 3)
    {
      _sizemap = _MenuIGNumbermap->getResult();
      std::cout << "Taille de la map = " << _sizemap << std::endl;
      //currentMenuIG++;
    }
  if (currentMenuIG == 6)
    {
      _numberia = _MenuIGNumberia->getResult();
      std::cout << "Number IA = " << _numberia << std::endl;
      // currentMenuIG++;
    }
  this->callFaceFunction();
  std::cout << "Apres = " << currentMenuIG<< std::endl;
  (void)data;
}

void	MenuIG::setGoMap(int gomap)
{
  _gomap = gomap;
}

int	MenuIG::getGoMap()
{
  return this->_gomap;
}

int	MenuIG::getFinish()
{
  return _finish;
}

MenuIG::~MenuIG()
{
  std::cout << "MenuIG Destroyed!" << std::endl;
}

void	MenuIG::faceMainMenuIG()
{
  if (_rotationOculus.x <= 40 && _rotationOculus.x >= -40)
    {
      if (_rotationOculus.y >= -45 && _rotationOculus.y <= 45)
	std::cout << "|-- Image de presentation --|b" << std::endl;
      else if (_rotationOculus.y >= 45 && _rotationOculus.y <= 135)
	currentMenuIG = 2;
      else if (_rotationOculus.y <= -45 && _rotationOculus.y >= -135)
	currentMenuIG = 1;
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
      currentMenuIG = 4;
    }
}

void	MenuIG::faceSettingsMenuIG()
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
	currentMenuIG = 0;
    }
  else
    currentMenuIG = 0;
}

void	MenuIG::faceSizeMap()
{
  _sizemap = _MenuIGNumbermap->getResult();
  std::cout << "Sizemap " << _sizemap << " ok currentMenuIG = " << currentMenuIG << std::endl;
  currentMenuIG = 6;
}

void	MenuIG::faceNumberIa()
{
  std::cout << "FACENUMBERIA" << std::endl;
  _numberia = _MenuIGNumberia->getResult();
  _gomap = 1;
}

void	MenuIG::callFaceFunction()
{
  if (this->currentMenuIG == 0)
    faceMainMenuIG();
  else if (this->currentMenuIG == 1)
    faceSettingsMenuIG();
}

void    MenuIG::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  if (this->currentMenuIG == 0)
    this->currentMenuIG = _mainMenuIG->draw(shader, clock);
  else if (this->currentMenuIG == 1)
    this->currentMenuIG = _settingsMenuIG->draw(shader, clock);
}

void	MenuIG::update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus)
{
  this->_rotationOculus = cameraOculus;
  if (this->currentMenuIG == 0)
    _mainMenuIG->update(clock, input, cameraOculus);
  else if (this->currentMenuIG == 1)
    _settingsMenuIG->update(clock, input, cameraOculus);
}

void	MenuIG::setSkybox(Skybox *skybox)
{
  _mainMenuIG->setSkybox(skybox);
  _settingsMenuIG->setSkybox(skybox);
}
