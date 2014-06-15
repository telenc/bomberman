//
// LoadGame.hpp for LoadGame in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon May 12 13:51:56 2014 Steven Martreux
// Last update Sun Jun 15 19:48:10 2014 Steven Martreux
//

#ifndef		_LOAD_GAME_HPP
#define		_LOAD_GAME_HPP

#include	<tinyxml.h>
#include	<string>
#include	<iostream>
#include	<map>
#include	<vector>
#include	<fstream>

#include	"myException.hpp"
#include	"DefaultWall.hpp"
#include	"DestrucWall.hpp"
#include	"Map.hpp"
#include	"PoBonus.hpp"
#include	"BombBonus.hpp"
#include	"Player.hpp"
#include	"DefaultBomb.hpp"
#include	"DefaultFire.hpp"
#include	"SolWall.hpp"
#include	"IaBomber.hpp"

class		LoadGame
{
public:
  LoadGame(const std::string & file, EventManager *, ModelList *, gdl::Clock *);
  ~LoadGame();
  void		getMapSize();
  bool		getLoad() const;
  void		getObjMap();
  Map		*getMap() const;
  AObjectPhysic *CreateDefaultWall(TiXmlElement *);
  AObjectPhysic	*CreateDestrucWall(TiXmlElement *);
  AObjectPhysic	*CreateDefaultBomb(TiXmlElement *);
  AObjectPhysic *CreateBonusPo(TiXmlElement *);
  AObjectPhysic *CreateBonusBomb(TiXmlElement *);
  AObjectPhysic	*CreateDefaultFire(TiXmlElement *);
  AObjectPhysic	*CreateSol(TiXmlElement *);
  std::vector<APlayer *> *getVectorPlayer(TiXmlElement *);
  APlayer	*GetPlayerBomb(int);
  void		 getPlayer();
  bool		ChangeMd5();
  bool		checkFile();
  IaBomber	*getIa(int, int, int);
  void		getIas();
private:
  std::string	_file;
  bool		_loadOkay;
  TiXmlElement	*_bomberman;
  TiXmlElement	*_map_size;
  TiXmlElement	*_player;
  TiXmlElement	*_ia;
  TiXmlElement	*_map;
  Map		*_mapGame;
  EventManager	*_event;
  ModelList	*_model;
  gdl::Clock	*_clock;
  std::map<std::string,  AObjectPhysic*(LoadGame::*)(TiXmlElement *) > _mapObject;
};

#endif		/* _LOAD_GAME_HPP */
