//
// Random.hpp for Random.hpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 17:51:24 2014 dedicker remi
// Last update Tue May 20 09:09:21 2014 Remi telenczak
//

#ifndef GENEREMAP_HPP_
# define GENEREMAP_HPP_

#include	"Map.hpp"

class GenereMap
{
public:
  GenereMap(int width, int height, int ia, EventManager *, ModelList *);
  ~GenereMap();
  //  void display();
  Map	*getMap() const;
private:
  void putInside();
  //void	putCorner();
  void putPlayer();
  void putWall();
  void putIa();
  Map	*_map;
  int	_width;
  int	_height;
  int	_ia;
  int	_pos;
  EventManager *_event;
  ModelList *_model;
};

#endif
