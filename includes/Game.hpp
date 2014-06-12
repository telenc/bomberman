//
// Game.hpp for Game in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:19:13 2014 Steven Martreux
// Last update Wed Jun 11 15:50:32 2014 dedicker remi
//

#ifndef		_GAME_HPP_
#define		_GAME_HPP_

# include	"Menu.hpp"
# include	"EventManager.hpp"
# include	"Graphics.hpp"
# include	"Loader.hpp"
# include	"Skybox.hpp"

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
private:
  int		_display;
  EventManager	*eventManager;
  Menu		*menu;
  Loader	*load;
  Graphics	*engine;
  Controller	*joystick;
  Map		*map;
  Sound		*sound;
};

#endif		/* _GAME_HPP_ */
