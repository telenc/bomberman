//
// Controller.cpp for Controller in /home/martre_s/Epitech/cpp_bomberman/AllTest/testController
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Wed May 21 12:42:20 2014 Steven Martreux
// Last update Thu May 22 15:41:15 2014 Steven Martreux
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
  _right = 0;
  _left = 0;
  _up = 0;
  _down = 0;
  _rotateLeft = 0;
  _rotateRight = 0;
  _bomb = 0;
}

Controller::~Controller()
{
  SDL_JoystickClose(_joystick);
}

void	Controller::setRightLeft(int right, int left)
{
  _right = right;
  _left = left;
}

void	Controller::setRotate(int right, int left)
{
  _rotateLeft = left;
  _rotateRight = right;
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
  else
    this->setRightLeft(0, 0);
}

void	Controller::CheckAxeUpDown()
{
  if (SDL_JoystickGetAxis(_joystick, 1) < -4000)
    this->setUpDown(1, 0);
  else if (SDL_JoystickGetAxis(_joystick, 1) > 4000)
    this->setUpDown(0, 1);
  else
    this->setUpDown(0, 0);
}

void	Controller::CheckAxeRotate()
{
  if (SDL_JoystickGetAxis(_joystick, 3) < -4000)
    this->setRotate(0, 1);
  else if (SDL_JoystickGetAxis(_joystick, 3) > 4000)
    this->setRotate(1, 0);
  else
    this->setRotate(0, 0);
}

void	Controller::sendEvent()
{
  if (_right == 1)
    _eventManager->dispatchEvent("keyRight", NULL);
  else if (_left == 1)
    _eventManager->dispatchEvent("keyLeft", NULL);
  if (_down == 1)
    _eventManager->dispatchEvent("keyDown", NULL);
  else if (_up == 1)
    _eventManager->dispatchEvent("keyUp", NULL);
  if (_rotateLeft == 1)
    _eventManager->dispatchEvent("rotateLeft", NULL);
  else if (_rotateRight == 1)
    _eventManager->dispatchEvent("rotateRight", NULL);
  if (_bomb == 1)
    _eventManager->dispatchEvent("keyA", NULL);
}

void	Controller::update()
{
  SDL_JoystickUpdate();
  _bomb = 0;
  _right = 0;
  _left = 0;
  _up = 0;
  _down = 0;
  _rotateLeft = 0;
  _rotateRight = 0;
  if (SDL_JoystickGetAxis(_joystick, 0) < -4000 || SDL_JoystickGetAxis(_joystick, 0) > 4000)
    CheckAxeLeftRight();
  if (SDL_JoystickGetAxis(_joystick, 1) < -4000 || SDL_JoystickGetAxis(_joystick, 1) > 4000)
    CheckAxeUpDown();
  if (SDL_JoystickGetAxis(_joystick, 3) < -4000 || SDL_JoystickGetAxis(_joystick, 3) > 4000)
    CheckAxeRotate();
  if (SDL_JoystickGetButton(_joystick, 0) == 1)
    _bomb = 1;
  sendEvent();
}
