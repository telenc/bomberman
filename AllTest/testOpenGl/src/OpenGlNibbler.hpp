//
// OpenGlNibbler.hpp for Opennibler in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:16:27 2014 telenc_r
// Last update Tue May  6 05:35:52 2014 Remi telenczak
//

#ifndef	_OPENGL_NIBBLER
#define	_OPENGL_NIBBLER

#include	<vector>
#include	"ALibGraphic.hpp"
#include	<GL/freeglut.h>
#include	<string>
#include	<stdio.h>
#include	<cstdlib>
#include	<ctime>
#include	<sstream>
#include	<map>
#include	<list>

typedef struct s_color t_color;

struct s_color
{
  int	r;
  int	g;
  int	b;
};

class OpenGlNibbler : public ALibGraphic
{
public:
  OpenGlNibbler(Game *);
  virtual	~OpenGlNibbler();
  void		refresh();
  void		zoomCam();
  void		dezoomCam();
  void		changeDisplay();

private:
  void		refreshDied();
  void		view();
  void		settingColor(int, int);
  void		createEyes(int, int) ;
  void		createCube(double, double, double) const;
  void		createSphere(double, double, double) const;
  void		createCylinder(double, double, double, double) const;
  void		createPlan() const;
  void		createFruit();
  void		createSnake();
  void		createScore() const;
  void		writeText(int, int, const char *) const;
  void		refreshGame();
  void		refreshGame2();
  void		refreshMenu();
  t_color	createTColor(int, int, int);
  void		createMapColor();
  void		menuFruit();
  void		menuSnakeRight();
  void		menuSnakeLeft();
  void		setRgb(int, int, int);

private:
  std::map<char, t_color>	_colorFruit;
  Game				*_game;
  int				_display;
  int				_zoom;
  int				_directionMenu;
  int				_xMenu;
  int				_yMenu;
  int				rgb[3];
};

#endif
