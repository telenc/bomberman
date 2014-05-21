//
// Sound.hpp for Sound in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:24:51 2014 Steven Martreux
// Last update Wed May 21 00:38:01 2014 Remi telenczak
//

#ifndef		_SOUND_HPP_
#define		_SOUND_HPP_

#include	<string>
#include	<iostream>
#include	<SFML/Audio.hpp>

class		Sound
{
public:
  Sound();
  ~Sound();
  void	InGame();
  void	StartTicTacBomb(float, float, float);
  void	StopTicTacBomb();
  void	StartExplosion(float, float, float);
  void	StopExplosion();
  void	InGameStop();
  void	InMenuStop();
  void	InMenu();
  void	setPlayer(float, float, float);
private:
  sf::Music		_InGame;
  sf::Music		_TicTacBomb;
  sf::Music		_ExplosionBomb;
  sf::Music		_InMenu;
};


#endif	       /* _SOUND_HPP_ */
