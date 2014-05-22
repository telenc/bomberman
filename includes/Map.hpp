//
// map.hh for map.hh in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 15:53:47 2014 dedicker remi
// Last update Thu May 22 07:33:08 2014 Remi telenczak
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>
#include "AObjectPhysic.hpp"
#include	<BasicShader.hh>
#include	<Clock.hh>
#include	<Input.hh>
class APlayer;
class Player;
class AObjectPhysic;
class Skybox;
class Map
{
public:
  Map(int x, int y);
  ~Map();
  void	update(gdl::Clock, gdl::Input);
  void setMap(int x, int y, AObjectPhysic *bloc);
  int	getWidth() const;
  int	getHeight() const;
  std::vector<APlayer*> getIa() const;
  std::vector<AObjectPhysic *> getMap() const;
  Player *getPlayer() const;
  void	setPlayer(Player *);
  void	setSkybox(Skybox *);
  void	draw(gdl::BasicShader, gdl::Clock);
  std::vector<AObjectPhysic *> getObjectsPos(AObjectPhysic *);
private:
  //std::vector< std::vector<AObjectPhysic *> > _map;
  std::vector<AObjectPhysic * > _map;
  std::vector <APlayer *> _ia;
  int		_width;
  int		_height;
  Player *_player;
  Skybox	*_skybox;
  //Graphics *_graphics;
  //EventManager *_event;
};

#endif
