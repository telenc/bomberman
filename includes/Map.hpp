//
// map.hh for map.hh in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 15:53:47 2014 dedicker remi
// Last update Tue May 20 09:34:08 2014 Remi telenczak
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>
#include "AObjectPhysic.hpp"
#include	<BasicShader.hh>
#include	<Clock.hh>
class APlayer;
class Player;
class AObjectPhysic;
class Map
{
public:
  Map(int x, int y);
  ~Map();
  void	update();
  void setMap(int x, int y, AObjectPhysic *bloc);
  AObjectPhysic *getObject(int , int) const;
  int	getWidth() const;
  int	getHeight() const;
  std::vector<APlayer*> getIa() const;
  std::vector< std::vector<AObjectPhysic *> > getMap() const;
  Player *getPlayer() const;
  void	setPlayer(Player *);
  void	draw(gdl::BasicShader, gdl::Clock);
  std::vector<AObjectPhysic *> getObjectsPos(AObjectPhysic *);
private:
  std::vector< std::vector<AObjectPhysic *> > _map;
  std::vector<AObjectPhysic * > _map2;
  std::vector <APlayer *> _ia;
  int		_width;
  int		_height;
  Player *_player;
  //Graphics *_graphics;
  //EventManager *_event;
};

#endif
