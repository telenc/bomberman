//
// Player.hpp for Player.hpp in /home/dedick_r/Tek2/c++/cpp_bomberman/includes
//
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
//
// Started on  Tue May 13 17:27:33 2014 dedicker remi
// Last update Sun Jun 15 19:17:41 2014 Remi telenczak
//

#ifndef		PLAYER_HPP_
# define	PLAYER_HPP_

# include	"APlayer.hpp"


class Player : public APlayer
{
public:
  Player(int x, int y, int z, Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool	update(gdl::Clock const &clock, gdl::Input &input);
  ~Player();
  void		eventPosPlayer(void *);
  void		eventKeyUp(void *data);
  void		eventKeyDown(void *data);
  void		eventKeyRight(void *data);
  void		eventKeyLeft(void *data);
  void		eventRotate(void *data);
  void		eventRotateRight(void *data);
  void		eventRotateLeft(void *data);
  void		eventKeyA(void *data);
private:
  void		resetAnim();
  void		move(glm::vec3, std::string);
  ICallBack	*callPosPlayer;
  ICallBack	*callKeyUp;
  ICallBack	*callKeyDown;
  ICallBack	*callKeyLeft;
  ICallBack	*callKeyRight;
  ICallBack	*callRotate;
  ICallBack	*callKeyA;
  bool		none;
  bool		beginRun;
  bool		checkRun;
  bool		run;
  bool		endRun;
};

#endif		/* PLAYER_HPP_ */
