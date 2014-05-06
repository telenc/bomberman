//
// Game.hpp for Game in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:26:53 2014 telenc_r
// Last update Sun Apr  6 22:39:02 2014 dedicker remi
//

#ifndef	_GAME_NIBBLER
#define	_GAME_NIBBLER

#include	<string>
#include	<unistd.h>
#include	"Map.hpp"
#include	"ALibGraphic.hpp"
#include	"ParserXml.hpp"
//class ALibGraphic;
typedef ALibGraphic *(*constructor_graphic_t)(Game *);

class Game
{
public:
  Game(int, int, std::string);
  Map	*getMap() const;
  void	initLib();
  ALibGraphic *getClassLib() const;
  constructor_graphic_t	func_load;
  ALibGraphic	*classLib;
  int	getEnd() const;
  void	setEnd(int);
  int	getSpeed() const;
  void	setSpeed(int speed);
  void	resetSpeed();
  void	setScore(int);
  int	getScore() const;
  int	getScoreMulti();
  void	setScoreMulti(int);
  void	addScore(int);
  std::list<int> getScores() const;
  void		addFinalScore(int);
  void	resetScoreMulti();
  void	pop_special_fruit();
  void	launchGame();
  void	launchHardGame();
  int	getMenu() const;
  void	launchMenu();
private:
  int	_w;
  int	_h;
  Map	*_map;
  ParserXml	*_parser;
  std::string _path;
  int	_menu;
  int	_end;
  int	_speed;
  int	_currentSpeed;
  int	_score;
  int	_scoreMulti;
  int	_sauvScoreMulti;

};


#endif /* _GAME_NIBBLER */
