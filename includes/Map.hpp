//
// map.hh for map.hh in /home/dedick_r/Bomberman
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Wed May  7 15:53:47 2014 dedicker remi
<<<<<<< HEAD
// Last update Mon May 26 08:01:57 2014 Remi telenczak
=======
// Last update Mon May 26 16:19:43 2014 dedicker remi
>>>>>>> 86fd066f3cca2a094e91194976398fe97236bc1e
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
  void setMap(AObjectPhysic *bloc);
  int	getWidth() const;
  int	getHeight() const;
  std::vector<APlayer*> getIa() const;
  std::vector<APlayer *>getPlayers() const;
  void	setPlayer(Player *);
  void	setSkybox(Skybox *);

  void	draw(gdl::BasicShader, gdl::Clock);
  std::vector<AObjectPhysic *> getObjectsPos(AObjectPhysic *);
<<<<<<< HEAD
  std::vector<APlayer *> getPlayers();
=======
  Player *getPlayer() const;
>>>>>>> 86fd066f3cca2a094e91194976398fe97236bc1e
private:
  std::list<AObjectPhysic * > _map;
  std::vector <APlayer *> _ia;
  std::vector<AObjectPhysic *> _objectToDelete;
  std::vector<AObjectPhysic *> _objectToPush;
  int		_width;
  int		_height;
  Player *_player;
  Skybox	*_skybox;
};

#endif
