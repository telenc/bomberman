//
// Player.hpp for Player.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman/includes
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:27:33 2014 dedicker remi
// Last update Thu May 15 08:54:58 2014 Remi telenczak
//

#ifndef PLAYER_HPP_
# define PLAYER_HPP_

# include	"APlayer.hpp"


class Player : public APlayer
{
public:
  Player(int x, int y, int z, Map *, ModelList *, EventManager *);
  ~Player();
};

#endif
