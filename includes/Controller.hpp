//
// Controller.hpp for Controller in /home/martre_s/Epitech/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Wed May 21 12:52:03 2014 Steven Martreux
// Last update Sun Jun 15 07:30:05 2014 Steven Martreux
//

#ifndef		_CONTROLLER_HPP_
#define		_CONTROLLER_HPP_

# include	<iostream>
# include	<string>
# include	<SDL/SDL.h>

# include	"SDL_joystick.h"
# include	"EventManager.hpp"
# include	"myException.hpp"

class		Controller
{
public:
  Controller(EventManager *);
  ~Controller();
  void	update();
  void	CheckAxeUpDown();
  void	CheckAxeRotate();
  void	CheckAxeLeftRight();
  void	setUpDown(int, int);
  void	setRightLeft(int, int);
  void	sendEvent();
  void	sendEventMove();
  void	sendEventMenu();
  void	initVar();
  void	varUpdate();
private:
  EventManager	*_eventManager;
  int		_right;
  int		_left;
  int		_up;
  int		_down;
  SDL_Joystick	*_joystick;
  int		_bomb;
  int		_back;
  int		_upMenu;
  int		_downMenu;
  int		_start;
  int		_stop;
  int		_select;
};

#endif		/* _CONTROLLER_HPP_ */
