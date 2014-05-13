//
// LoadGame.hpp for LoadGame in /home/martre_s/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Mon May 12 13:51:56 2014 Steven Martreux
// Last update Tue May 13 16:57:28 2014 Steven Martreux
//

#ifndef		_LOAD_GAME_HPP
#define		_LOAD_GAME_HPP

#include	<tinyxml.h>
#include	<string>
#include	<iostream>

class		LoadGame
{
public:
  LoadGame(const std::string & file);
  ~LoadGame();
  void getMapSize();
  bool getLoad() const;
  void getObjMap();
private:
  std::string _file;
  bool	      _loadOkay;
  TiXmlElement *_bomberman;
  TiXmlElement *_map_size;
  TiXmlElement *_map;
};

#endif		/* _LOAD_GAME_HPP */
