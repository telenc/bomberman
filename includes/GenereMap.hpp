//
// Random.hpp for Random.hpp in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 17:51:24 2014 dedicker remi
// Last update Sun Jun 15 19:35:24 2014 Steven Martreux
//

#ifndef		GENEREMAP_HPP_
# define	GENEREMAP_HPP_

#include	"Map.hpp"

class GenereMap
{
public:
  GenereMap(int width, int height, int ia, EventManager *, ModelList *, gdl::Clock *, TypeMap type);
  GenereMap(int width, int height, int ia, EventManager *, ModelList *, gdl::Clock *);
  ~GenereMap();
  Map		*getMap() const;
private:
  void		putInside();
  void		putPlayer();
  void		putWall();
  void		putIa();
  Map		*_map;
  int		_width;
  int		_height;
  int		_ia;
  int		_pos;
  TypeMap	_typeMap;
  EventManager	*_event;
  ModelList	*_model;
  gdl::Clock	*_clock;

};

#endif		/* GENEREMAP_HPP_ */
