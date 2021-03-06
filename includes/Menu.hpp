//
// Menu.hpp for Menu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 07:24:19 2014 Remi telenczak
// Last update Sun Jun 15 20:59:46 2014 thomas mendez
//

#ifndef		_MENU_BOMBERMAN
# define	_MENU_BOMBERMAN

#include        "OVR.h"
# include       "ModelList.hpp"
#include        <iostream>
#include        <string>
#include        <unistd.h>
#include        <SdlContext.hh>
#include        <cstdlib>
#include        <Game.hh>
#include        <Clock.hh>
#include        <Input.hh>
#include        <SdlContext.hh>
#include        <Geometry.hh>
#include        <Texture.hh>
#include        <BasicShader.hh>
#include        <Model.hh>
#include        <OpenGL.hh>
#include        <glm/glm.hpp>
#include        <glm/gtc/matrix_transform.hpp>
# include       "CameraBomber.hpp"
#include        "DefaultWall.hpp"
#include        "Map.hpp"
#include        "EventManager.hpp"
#include	"Skybox.hpp"
#include	"MenuBox.hpp"
#include	"MenuWall.hpp"
# include	"MainMenu.hpp"
# include	"SettingsMenu.hpp"
# include	"PlayMenu.hpp"
# include	"LoadGame.hpp"
# include	"LoadMenu.hpp"
# include	"MenuNumber.hpp"
# include	"CreditsMenu.hpp"
# include	"CallBack.hpp"

class Menu
{
public:
  Menu(ModelList *mod, EventManager *event, gdl::Clock *);
  ~Menu();
  int	getFinish() const;
  void	setSkybox(Skybox *skybox);
  void	setBox(gdl::Model *model);
  void  draw(gdl::BasicShader &, gdl::Clock const &);
  void	update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus);
  void  faceSettingsMenu();
  void  faceMainMenu();
  void  facePlayMenu();
  void	faceSizeMap();
  void	faceNumberIa();
  void	faceLoadGame();
  int	getSizemap() const;
  int	getNumberIa() const;
  void	setGoMap(int gomap);
  int	getGoMap() const;
  void	setFinish(int finish);
  void  callFaceFunction();
  void	eventKeyA(void *data);
  void	eventKeyB(void *data);
  void	setCurrentMenu(int);
  int	getCurrentMenu() const;
  LoadGame *getLoadGame() const;
private:
  gdl::Model *_box;
  ModelList *_mod;
  EventManager *_event;
  MenuBox *_boxmenu;
  MenuBox *_boxmenu2;
  MenuBox *_boxmenu3;
  Skybox *_skin;
  gdl::Clock *_clock;
  MenuNumber	*_menuBox;
  glm::vec3 _rotationOculus;
  MainMenu *_mainMenu;
  SettingsMenu *_settingsMenu;
  CreditsMenu *_creditsMenu;
  PlayMenu *_playMenu;
  LoadMenu *_loadMenu;
  LoadGame *_loadGame;
  MenuNumber *_MenuNumberia;
  MenuNumber *_MenuNumbermap;
  int	currentMenu;
  ICallBack *_callKeyA;
  ICallBack *_callKeyB;
  int		_finish;
  int		_sound;
  int		_sizemap;
  int		_numberia;
  int		_gomap;
  bool		_isLoad;
};

#endif
