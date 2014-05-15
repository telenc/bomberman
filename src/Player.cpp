//
// Player.cpp for Player.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:27:38 2014 dedicker remi
// Last update Thu May 15 07:33:59 2014 Remi telenczak
//

#include "Player.hpp"

Player::Player(int x, int y, int z) : APlayer(x, y, z)
{
  std::cout << "Player Created" << std::endl;
}

Player::~Player()
{
  std::cout << "Player Destroyed" << std::endl;
}
