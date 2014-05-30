//
// LoadGame.hpp for LoadGame in /home/martre_s/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Mon May 12 13:51:56 2014 Steven Martreux
// Last update Fri May 30 15:12:58 2014 Steven Martreux
//

#ifndef		_LOAD_GAME_HPP
#define		_LOAD_GAME_HPP

#include	<tinyxml.h>
#include	<string>
#include	<iostream>
#include	"Map.hpp"
#include	<map>
#include	"DefaultWall.hpp"
#include	"DestrucWall.hpp"

class		LoadGame
{
public:
  LoadGame(const std::string & file, EventManager *, ModelList *, gdl::Clock *);
  ~LoadGame();
  void getMapSize();
  bool getLoad() const;
  void getObjMap();
  Map *getMap() const;
  AObjectPhysic *CreateDefaultWall(TiXmlElement *);
  AObjectPhysic	*CreateDestrucWall(TiXmlElement *);
  AObjectPhysic	*CreateDefaultBomb(TiXmlElement *);
private:
  std::string _file;
  bool	      _loadOkay;
  TiXmlElement *_bomberman;
  TiXmlElement *_map_size;
  TiXmlElement *_map;
  Map	       *_mapGame;
  EventManager	*_event;
  ModelList	*_model;
  gdl::Clock	*_clock;
  std::map<std::string,  AObjectPhysic*(LoadGame::*)(TiXmlElement *) > _mapObject;
};

#endif		/* _LOAD_GAME_HPP */
