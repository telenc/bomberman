//
// Sound.hpp for Sound in /home/martre_s/Epitech/cpp_bomberman/AllTest/testSon
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Mon May 19 15:45:20 2014 Steven Martreux
// Last update Tue May 20 17:39:06 2014 Steven Martreux
//

#ifndef		_SOUND_HPP_
# define	_SOUND_HPP_

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

#endif		/* _SOUND_HPP_ */