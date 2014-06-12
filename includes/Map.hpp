//
// map.hh for map.hh in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 15:53:47 2014 dedicker remi
// Last update Thu Jun 12 13:01:46 2014 Remi telenczak
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
#include	"Geometry.hh"
#include "drawtext.h"


class	ABloc;
class	ABomb;
class APlayer;
class	ABonus;
class Player;
class AObjectPhysic;
class Skybox;
class	AFire;
class EventManager;
class Map
{
public:
  Map(int x, int y, EventManager *);
  ~Map();
  void	update(gdl::Clock, gdl::Input);
  void setBlock(ABloc *bloc);
  int	getWidth() const;
  int	getHeight() const;
  bool	isPause();
  void	updateBomb(gdl::Clock, gdl::Input);
  std::list<ABomb *>	getBombs() const;
  std::vector<APlayer*> getIa() const;
  std::vector<APlayer *>getPlayers() const;
  void	setPlayer(Player *);
  void	setSkybox(Skybox *);
  int	distanceObj(AObjectPhysic *);
  void	draw(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	drawBomb(gdl::BasicShader, gdl::Clock, CameraBomber *);
  std::vector<AObjectPhysic *> getObjectsPos(AObjectPhysic *);
  std::vector<APlayer *> getPlayers();
  Player *getPlayer() const;
  void	eventCallPause(void *);
  std::list<AObjectPhysic * > getObject();
  void	setBomb(ABomb *);
  void	drawBonus(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	updateBonus(gdl::Clock, gdl::Input);
  void	setBonus(ABonus *);
  std::list<ABonus *> getBonus() const;
  void	drawFire(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	updateFire(gdl::Clock, gdl::Input);
void	drawBloc(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	updateBloc(gdl::Clock, gdl::Input);
  void	setFire(AFire *);
void	setBloc(ABloc *);
  std::list<AObjectPhysic *> getAllObject();
  std::list<AFire *> getFire() const;
  std::list<ABloc *> getBloc() const;
  bool isBlock(int x, int z);
private:
  std::list<ABloc * > _blocs;
  std::list<ABomb * > _bombs;
  std::list<ABonus * > _bonus;
  std::list<AFire * > _fire;
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



};

#endif
