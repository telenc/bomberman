//
// Sound.hpp for Sound in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:24:51 2014 Steven Martreux
// Last update Sun Jun 15 07:29:38 2014 Steven Martreux
//

#ifndef		_SOUND_HPP_
#define		_SOUND_HPP_

# include		<string>
# include		<iostream>
# include		<SFML/Audio.hpp>
# include		<glm/glm.hpp>

# include		"EventManager.hpp"
# include		"myException.hpp"

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
  void	soundOff(void *);
  void	soundOn(void *);
private:
  EventManager		*_event;
  ICallBack		*callBombDrop;
  ICallBack		*callPlayerMove;
  ICallBack		*callSoundOn;
  ICallBack		*callSoundOff;
  sf::Music		_InGame;
  sf::Music		_TicTacBomb;
  sf::Music		_ExplosionBomb;
  sf::Music		_InMenu;
  glm::vec3		_position;
  int			_soundOn;
};


#endif	       /* _SOUND_HPP_ */
