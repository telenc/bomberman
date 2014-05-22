//
// Sound.hpp for Sound in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:24:51 2014 Steven Martreux
// Last update Thu May 22 09:13:57 2014 Remi telenczak
//

#ifndef		_SOUND_HPP_
#define		_SOUND_HPP_

#include	<string>
#include	<iostream>
#include	<SFML/Audio.hpp>
# include	"EventManager.hpp"
# include		<glm/glm.hpp>
class		Sound
{
public:
  Sound(EventManager *);
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
  void	eventBombDrop(void *data);
void	eventPlayerMove(void *data);
private:
  EventManager *_event;
ICallBack	*callBombDrop;
  ICallBack	*callPlayerMove;
  sf::Music		_InGame;
  sf::Music		_TicTacBomb;
  sf::Music		_ExplosionBomb;
  sf::Music		_InMenu;
glm::vec3		_position;
};


#endif	       /* _SOUND_HPP_ */
