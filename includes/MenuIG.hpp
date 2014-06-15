//
// MenuIGIG.hpp for MenuIGig in /home/mendez_t/local/cpp/cpp_bomberman/includes
// 
// Made by thomas mendez
// Login   <mendez_t@epitech.net>
// 
// Started on  Sun Jun 15 04:19:01 2014 thomas mendez
// Last update Sun Jun 15 18:40:22 2014 thomas mendez
//

#ifndef		_MENUIG_BOMBERMAN
# define	_MENUIG_BOMBERMAN

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
#include	"MenuBoxIG.hpp"
#include	"MenuWall.hpp"
# include	"MainMenuIG.hpp"
# include	"SaveMenu.hpp"
# include	"SettingsMenuIG.hpp"
# include	"CallBack.hpp"

class MenuIG
{
public:
  MenuIG(ModelList *mod, EventManager *event, gdl::Clock *);
  ~MenuIG();
  int	getFinish();
  void	setSkybox(Skybox *skybox);
  void	setBox(gdl::Model *model);
  void  draw(gdl::BasicShader &, gdl::Clock const &);
  void	update(gdl::Clock &clock, gdl::Input &input, glm::vec3 cameraOculus);
  void  faceSettingsMenuIG();
  void  faceMainMenuIG();
  void	setFinish(int finish);
  void  callFaceFunction();
  void	eventKeyA(void *data);
  void	eventKeyB(void *data);
  void	setBack(int back);
  int	getBack() const;
private:
  gdl::Model *_box;
  ModelList *_mod;
  EventManager *_event;
  MenuBoxIG *_boxmenu;
  MenuBoxIG *_boxmenu2;
  MenuBoxIG *_boxmenu3;
  Skybox *_skin;
  gdl::Clock *_clock;
  glm::vec3 _rotationOculus;
  MainMenuIG *_mainMenuIG;
  SettingsMenuIG *_settingsMenuIG;
  SaveMenu *_saveMenu;
  int	currentMenuIG;
  ICallBack *_callKeyA;
  ICallBack *_callKeyB;
  int		_finish;
  int		_sound;
  int		_sizemap;
  int		_numberia;
  int		_gomap;
  int		_back;
};

#endif
