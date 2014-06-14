//
// SaveGame.hpp for SaveGame in /home/martre_s/workspace/cpp_bomberman
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Mon Jun  2 15:02:25 2014 Steven Martreux
// Last update Sat Jun 14 22:28:07 2014 Steven Martreux
//

#ifndef		_SAVEGAME_HPP_
#define		_SAVEGAME_HPP_

#include	<tinyxml.h>
#include	<iostream>
#include	<fstream>
#include	<string>

#include	"AObjectPhysic.hpp"
#include	"DefaultWall.hpp"
#include	"DestrucWall.hpp"
#include	"DefaultBomb.hpp"
#include	"DefaultFire.hpp"
#include	"BombBonus.hpp"
#include	"PoBonus.hpp"
#include	"Player.hpp"
#include	"SolWall.hpp"

class		Map;
class		SaveGame
{
public:
  SaveGame(Map *, const std::string &);
  ~SaveGame();
  void		SaveMapSize();
  void		setObjMap();
  std::string	ConstCharByInt(int) const;
  std::string	ConstCharByFloat(float) const;
  std::string	ConstCharByDouble(double) const;
  void		SaveDefaultWall(AObjectPhysic *);
  void		SaveDestructWall(AObjectPhysic *);
  void		SaveDefaultBomb(AObjectPhysic *);
  void		SavePlayer();
  void		SaveBonusPo(AObjectPhysic *);
  void		SaveBonusBomb(AObjectPhysic *);
  void		SavePlayerInFire(AFire *);
  void		SaveDefaultFire(AObjectPhysic *);
  void		ChangeMd5();
  void		SaveSol();
private:
  TiXmlDocument _file;
  TiXmlElement	*_mapSize;
  TiXmlElement	*_bomberman;
  TiXmlElement	*_obj;
  Map		*_map;
  std::string	_fileName;
  std::map<TypeObjectPrecis, void(SaveGame::*)(AObjectPhysic *) > _mapObject;
};


#endif		/* _SAVEGAME_HPP_ */
