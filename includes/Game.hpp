//
// Game.hpp for Game in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:19:13 2014 Steven Martreux
// Last update Sun Jun 15 06:02:43 2014 thomas mendez
// Last update Sun Jun 15 05:51:50 2014 Steven Martreux
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
};

#endif		/* _GAME_HPP_ */
