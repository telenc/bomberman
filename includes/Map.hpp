//
// map.hh for map.hh in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 15:53:47 2014 dedicker remi
// Last update Sun Jun 15 19:13:31 2014 Steven Martreux
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
#include	<time.h>

class	ABloc;
class	ABomb;
class APlayer;
class	ABonus;
class Player;
class AObjectPhysic;
class Skybox;
class	AFire;
class	IaBomber;
class EventManager;

enum TypeMap
  {
    NORMAL,
    ZOMBIE
  };

class Map
{
public:
  Map(int x, int y, EventManager *);
  Map(int x, int y, EventManager *, TypeMap type);
  ~Map();
  void	update(gdl::Clock, gdl::Input);
  void	updateBomb(gdl::Clock, gdl::Input);
  void	updateBonus(gdl::Clock, gdl::Input);
  void	updateFire(gdl::Clock, gdl::Input);
  void	updateBloc(gdl::Clock, gdl::Input);
  void	updateIa(gdl::Clock, gdl::Input);
  void	updateZombie(gdl::Clock, gdl::Input);

  void	draw(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	drawSol(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	drawBomb(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	drawFire(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	drawBloc(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	drawBonus(gdl::BasicShader, gdl::Clock, CameraBomber *);
  void	drawIa(gdl::BasicShader, gdl::Clock, CameraBomber *);

  int	getWidth() const;
  int	getHeight() const;
  bool	isPause();
  TypeMap	getTypeMap() const;
  int	distanceObj(AObjectPhysic *);
  int	distanceObj(AObjectPhysic *, AObjectPhysic *);
  void	eventCallPause(void *);
  void eventCallSelect(void *data);
  void  setSelect(bool);
  bool  getSelect() const;

  void	setPlayer(Player *);
  void	setSkybox(Skybox *);
  void	setBomb(ABomb *);
  void	setBonus(ABonus *);
  void	setFire(AFire *);
  void	setBloc(ABloc *);
  void	setBlock(ABloc *bloc);
  void	setIa(IaBomber *);
  void	setSol(ABloc *);

  std::vector<AObjectPhysic *> getObjectsList(AObjectPhysic *, int dist, std::list<AObjectPhysic *>);
  std::vector<AObjectPhysic *> getObjectsPos(AObjectPhysic *, int dist = 30, TypeObject type = NONE);
  std::vector<AObjectPhysic *> getObjectsPrecisPos(AObjectPhysic *, int dist = 30, TypeObjectPrecis type = NONEPRECIS);

  std::list<ABomb *>		getBombs() const;
  std::list<IaBomber*>			getIa() const;
  std::vector<APlayer *>	getPlayers() const;
  std::vector<APlayer *>	getPlayers();
  Player			*getPlayer() const;
  std::list<AObjectPhysic *>	getAllObject();
  std::list<AFire *>		getFire() const;
  std::list<ABloc *>		getBloc() const;
  std::list<ABonus *>		getBonus() const;
  std::list<AObjectPhysic * >	getObject();
  std::list<ABloc *>		getSol() const;

  bool	isBlock(int x, int z, bool bomb = false);
  bool	isFire(int x, int z);
  bool	isFinish();
  bool	hasPlayer(int x, int y, bool autour);
private:
  std::list<ABloc * > _blocs;
  std::list<ABomb * > _bombs;
  std::list<ABonus * > _bonus;
  std::list<ABloc * > _sol;
  std::list<AFire * > _fire;
  std::list <IaBomber *> _ia;
  std::vector<AObjectPhysic *> _objectToDelete;
  std::vector<AObjectPhysic *> _objectToPush;
  int		_width;
  int		_height;
  EventManager	*_event;
  Player *_player;
  ICallBack	*callPause;
  ICallBack	*callSelect;
  bool		_pause;
  bool		_select;
  Skybox	*_skybox;
  TypeMap	_typeMap;
  int		vague;
  int		nbrZombie;
  bool		vagueFini;
  time_t	_timeVague;
  int xZomb;
  int yZomb;
  int	nbrZomb;
};

#endif
