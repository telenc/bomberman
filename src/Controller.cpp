//
// Controller.cpp for Controller in /home/martre_s/Epitech/cpp_bomberman/AllTest/testController
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May 21 12:42:20 2014 Steven Martreux
// Last update Sat Jun 14 17:46:07 2014 Steven Martreux
//

#include	"Controller.hpp"

Controller::Controller(EventManager *event) : _eventManager(event)
{
  _joystick = NULL;
  SDL_Init(SDL_INIT_JOYSTICK);
  _joystick = SDL_JoystickOpen(0);
  SDL_JoystickEventState(SDL_ENABLE);
  if (_joystick == NULL)
    std::cout << "FAILLLLLL" << std::endl;
  if  (SDL_JoystickNumButtons(_joystick) == 0)
    {
      std::cout << "QUITTE" << std::endl;
      //THROW A FAIRE
    }
  this->initVar();
}

Controller::~Controller()
{
  SDL_JoystickClose(_joystick);
}

void	Controller::initVar()
{
  _right = 0;
  _left = 0;
  _up = 0;
  _down = 0;
  _bomb = 0;
  _upMenu = 0;
  _downMenu = 0;
  _start = 0;
  _back = 0;
  _stop = 0;
}

void	Controller::setRightLeft(int right, int left)
{
  _right = right;
  _left = left;
}

void	Controller::setUpDown(int up, int down)
{
  _up = up;
  _down = down;
}

void	Controller::CheckAxeLeftRight()
{
  if (SDL_JoystickGetAxis(_joystick, 0) < -4000)
    this->setRightLeft(0, 1);
  else if (SDL_JoystickGetAxis(_joystick, 0) > 4000)
    this->setRightLeft(1, 0);
}

void	Controller::CheckAxeUpDown()
{
  if (SDL_JoystickGetAxis(_joystick, 1) < -4000)
    this->setUpDown(1, 0);
  else if (SDL_JoystickGetAxis(_joystick, 1) > 4000)
    this->setUpDown(0, 1);
}

void	Controller::sendEventMenu()
{
  if (_upMenu == 2)
    {
      _eventManager->dispatchEvent("keyUpMenu", NULL);
      _upMenu = 0;
    }
  else if (_downMenu == 2)
    {
      _downMenu = 0;
      _eventManager->dispatchEvent("keyDownMenu", NULL);
    }
}

void	Controller::sendEventMove()
{
  if (_right == 1)
    {
      _eventManager->dispatchEvent("keyRight", NULL);
      _stop = 2;
    }
  else if (_left == 1)
    {
      _eventManager->dispatchEvent("keyLeft", NULL);
      _stop = 2;
    }
  if (_down == 1)
    {
      _eventManager->dispatchEvent("keyDown", NULL);
      _stop = 2;
    }
  else if (_up == 1)
    {
      _eventManager->dispatchEvent("keyUp", NULL);
      _stop = 2;
    }
  if (_right == 0 && _up == 0 && _down == 0 && _left == 0 && _stop != 0)
    _stop = 1;
}

void	Controller::sendEvent()
{
  this->sendEventMenu();
  this->sendEventMove();
  if (_bomb == 2)
    {
      _bomb = 0;
      _eventManager->dispatchEvent("keyA", NULL);
    }
  else if (_back == 2)
    {
      _back = 0;
      _eventManager->dispatchEvent("keyB", NULL);
    }
  if (_start == 2)
    {
      _start = 0;
      _eventManager->dispatchEvent("pause", NULL);
    }
  if (_stop == 1)
    {
      _eventManager->dispatchEvent("stopanim", NULL);
      _stop = 0;
    }
}

void	Controller::varUpdate()
{
  _right = 0;
  _left = 0;
  _up = 0;
  _down = 0;
}

void	Controller::update()
{
  SDL_JoystickUpdate();
  varUpdate();
  if (SDL_JoystickGetAxis(_joystick, 0) < -4000 || SDL_JoystickGetAxis(_joystick, 0) > 4000)
    CheckAxeLeftRight();
  else if (SDL_JoystickGetAxis(_joystick, 1) < -4000 || SDL_JoystickGetAxis(_joystick, 1) > 4000)
    CheckAxeUpDown();
  if (SDL_JoystickGetButton(_joystick, 0) == 1)
    _bomb = 1;
  else if (SDL_JoystickGetButton(_joystick, 0) != 1 && _bomb == 1)
    _bomb = 2;
  if (SDL_JoystickGetButton(_joystick, 1) == 1)
    _back = 1;
  else if (SDL_JoystickGetButton(_joystick, 1) != 1 && _back == 1)
    _back = 2;
  if (SDL_JoystickGetHat(_joystick, 0) == SDL_HAT_UP)
    _upMenu = 1;
  else if (SDL_JoystickGetHat(_joystick, 0) == SDL_HAT_DOWN)
    _downMenu = 1;
  if (SDL_JoystickGetHat(_joystick, 0) != SDL_HAT_UP && _upMenu == 1)
    _upMenu = 2;
  else if (SDL_JoystickGetHat(_joystick, 0) != SDL_HAT_DOWN && _downMenu == 1)
    _downMenu = 2;
  if (SDL_JoystickGetButton(_joystick, 7) == 1)
    _start = 1;
  if (_start == 1 && SDL_JoystickGetButton(_joystick, 7) != 1)
    _start = 2;
  sendEvent();
}
