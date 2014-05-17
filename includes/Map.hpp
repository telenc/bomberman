//
// map.hh for map.hh in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 15:53:47 2014 dedicker remi
// Last update Thu May 15 17:43:54 2014 dedicker remi
//

#ifndef MAP_HPP_
# define MAP_HPP_

#include <vector>
#include "AObjectPhysic.hpp"

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
  std::vector<Player*> getIa() const;
  std::vector< std::vector<AObjectPhysic *> > getMap() const;
  Player *getPlayer() const;
private:
  std::vector< std::vector<AObjectPhysic *> > _map;
  std::vector <Player *> _ia;
  int		_height;
  int		_width;
  Player *_player;
  //Graphics *_graphics;
  //EventManager *_event;
};

#endif
