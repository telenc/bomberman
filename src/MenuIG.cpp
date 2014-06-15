//
// MenuIG.cpp for MenuIG in /home/mendez_t/local/cpp/cpp_bomberman/src
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 03:43:30 2014 thomas mendez
// Last update Sun Jun 15 17:42:07 2014 thomas mendez
//

#include	<iostream>
#include	"MenuIG.hpp"
#include	"Skybox.hpp"
#include	"SettingsMenuIG.hpp"
#include	"MainMenuIG.hpp"
#include	"CallBack.hpp"

MenuIG::MenuIG(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock), _finish(1), _sound(1)
{
  std::cout << "Debut constructeur MEnu" << std::endl;
  _mainMenuIG = new MainMenuIG(mod, event);
  _settingsMenuIG = new SettingsMenuIG(mod, event);
  currentMenuIG = 0;
  _callKeyA = new CallBack<MenuIG>(this, &MenuIG::eventKeyA);
  event->listenEvent("keyA", _callKeyA);
  _callKeyB = new CallBack<MenuIG>(this, &MenuIG::eventKeyB);
  event->listenEvent("keyB", _callKeyB);  
  std::cout << "Fin constructeur MEnu" << std::endl;
  _back = 0;
}

void	MenuIG::setFinish(int finish)
{
  this->_finish = finish;
}

void    MenuIG::eventKeyB(void *data)
{
  (void)data;
  _back = 1;
}

void    MenuIG::setBack(int back)
{
  _back = back;
}

int    MenuIG::getBack() const
{
  return _back;
}

void    MenuIG::eventKeyA(void *data)
{
  this->callFaceFunction();
  (void)data;
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
