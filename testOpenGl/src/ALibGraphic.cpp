//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Wed Apr  2 19:06:54 2014 Steven Martreux
//

#include	"ALibGraphic.hpp"

ALibGraphic::ALibGraphic(Game *game) : _game(game)
{

}

Game	*ALibGraphic::game() const
{
  return this->_game;
}
