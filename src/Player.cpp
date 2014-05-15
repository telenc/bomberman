//
// Player.cpp for Player.cpp in /home/dedick_r/Tek2/c++/cpp_bomberman/src
// 
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
// 
// Started on  Tue May 13 17:27:38 2014 dedicker remi
// Last update Wed May 14 15:31:02 2014 dedicker remi
//

#include "Player.hpp"

Player::Player(/*int x, int y, int z */) // APlayer(x, y, z)
{
  this->_event = new EventManager();
  std::cout << "Player Created" << std::endl;
}

Player::~Player()
{
  delete _event;
  std::cout << "Player Destroyed" << std::endl;
}
