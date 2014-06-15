//
// Game.hpp for Game in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:19:13 2014 Steven Martreux
// Last update Sun Jun 15 19:47:22 2014 Steven Martreux
//

#ifndef		_GAME_HPP_
#define		_GAME_HPP_

# include	"Menu.hpp"
# include	"MenuIG.hpp"
# include	"EventManager.hpp"
# include	"Graphics.hpp"
# include	"Loader.hpp"
# include	"Skybox.hpp"
# include	"GenereMap.hpp"
# include	"myException.hpp"

# include      	<stdio.h>
# include      	<stdlib.h>
# include      	<iostream>
# include      	<vlc/vlc.h>
# include	<fstream>

class		Game
{
public:
  Game();
  ~Game();
  void		playMenu();
  bool		update();
  void		draw();
  void		playMap();
  int		isFinish();
  void		eventKeyStart(void *data);
  void		eventKeySelect(void *data);
  void		intro_game();
private:
  GenereMap	*_gen;
  int		_display;
  EventManager	*eventManager;
  Menu		*menu;
  MenuIG	*menuIG;
  Loader	*load;
  Graphics	*engine;
  Controller	*joystick;
  Map		*map;
  Sound		*sound;
  ICallBack	*_callKeyStart;
  int		state;
  int		_runMap;
};

#endif		/* _GAME_HPP_ */
