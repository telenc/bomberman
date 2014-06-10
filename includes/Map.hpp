//
// map.hh for map.hh in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 15:53:47 2014 dedicker remi
// Last update Tue Jun 10 17:06:02 2014 Remi telenczak
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>
#include <list>
#include <algorithm>
#include "Skybox.hpp"
#include "AObjectPhysic.hpp"
#include	<BasicShader.hh>
#include	<Clock.hh>
#include	<Input.hh>
#include	"CameraBomber.hpp"
#include	"Texture.hh"

#include "drawtext.h"

class APlayer;
class Player;
class AObjectPhysic;
class Skybox;
class EventManager;
class Map
{
public:
  Map(int x, int y, EventManager *);
  ~Map();
  void	update(gdl::Clock, gdl::Input);
  void setMap(AObjectPhysic *bloc);
  int	getWidth() const;
  int	getHeight() const;
  bool	isPause();

  std::vector<APlayer*> getIa() const;
  std::vector<APlayer *>getPlayers() const;
  void	setPlayer(Player *);
  void	setSkybox(Skybox *);
  int	distanceObj(AObjectPhysic *);
  void	draw(gdl::BasicShader, gdl::Clock, CameraBomber *);
  std::vector<AObjectPhysic *> getObjectsPos(AObjectPhysic *);
  std::vector<APlayer *> getPlayers();
  Player *getPlayer() const;
  void	eventCallPause(void *);
  std::list<AObjectPhysic * > getObject() const;
private:
  std::list<AObjectPhysic * > _map;
  std::vector <APlayer *> _ia;
  std::vector<AObjectPhysic *> _objectToDelete;
  std::vector<AObjectPhysic *> _objectToPush;
  int		_width;
  int		_height;
  EventManager	*_event;
  Player *_player;
  ICallBack	*callPause;
  bool		_pause;
  Skybox	*_skybox;



  gdl::Texture texture;
  gdl::Geometry geometry;
};

#endif
