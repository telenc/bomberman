/*
** Sound.cpp for make in /home/bernar_x/Tech2/Projets/cpp_bomberman
**
** Made by mattieu bernard-guêle
** Login <bernar_x@epitech.net>
**
** Started on  Thu Jun  5 16:20:43 2014 mattieu bernard-guêle
<<<<<<< HEAD
// Last update Sun Jun 15 18:48:52 2014 thomas mendez
=======
// Last update Sun Jun 15 20:03:07 2014 Remi telenczak
>>>>>>> 85ad641a0fd5cdf5ea54042d653b2ccc9366ca40
*/

#include	"Sound.hpp"

Sound::Sound(EventManager *event) : _event(event), _position(0, 0, 0)
{
  if (!_InGame.OpenFromFile("sound/SoundInGame.wav"))
    throw new myException("Fail to open SoundInGame");
  if (!_TicTacBomb.OpenFromFile("sound/TicTacBomb.wav"))
    throw new myException("Fail to open TicTacBomb");
  if (!_ExplosionBomb.OpenFromFile("sound/Explosion.wav"))
    throw new myException("Fail to open Explosion");
  if (!_InMenu.OpenFromFile("sound/Menu.wav"))
    throw new myException("Fail to open Menu.wav");
  if (!_Zombie.OpenFromFile("sound/zombie2.wav"))
    throw new myException("Fail to open Zombie.wav");
  callBombDrop = new CallBack<Sound>(this, &Sound::eventBombDrop);
  event->listenEvent("bombDrop", callBombDrop);
  callPlayerMove = new CallBack<Sound>(this, &Sound::eventPlayerMove);
  event->listenEvent("playerPosition", callPlayerMove);
  callSoundOn = new CallBack<Sound>(this, &Sound::soundOn);
  event->listenEvent("soundon", callSoundOn);
  callSoundOff = new CallBack<Sound>(this, &Sound::soundOff);
  event->listenEvent("soundoff", callSoundOff);
  callSoundZombie = new CallBack<Sound>(this, &Sound::InZombie);
  event->listenEvent("soundZombie", callSoundZombie);
  callSoundGame = new CallBack<Sound>(this, &Sound::InGame);
  event->listenEvent("soundGame", callSoundGame);
  _soundOn = 1;
}

Sound::~Sound()
{

}

void	Sound::soundOff(void *data)
{
  (void)data;
  if (_soundOn != 1)
    _InGame.Stop();
  _soundOn = 1;
}

void	Sound::soundOn(void *data)
{
  (void)data;
  if (_soundOn != 0)
    _InGame.Play();
  _soundOn = 0;
}

void	Sound::eventPlayerMove(void *data)
{
  (void)data;
  glm::vec3 *test;

  test = (glm::vec3 *)data;
  this->setPlayer(test->x, test->y, test->z);
}

void	Sound::eventBombDrop(void *data)
{
  (void)data;
  if (_soundOn == 0)
      this->StartTicTacBomb(1300, 1300, 1300);
}

void	Sound::setPlayer(float x, float y, float z)
{
  if (_soundOn == 0)
    {
      sf::Listener::SetPosition(x * 0, y * 0, z * 0);
    }
}

void	Sound::InZombie(void *data)
{
  (void)data;
  this->InGameStop();
  if (_soundOn == 0)
    {
      _Zombie.SetLoop(true);
      _Zombie.SetVolume(20.5);
      _Zombie.Play();
    }
}

void	Sound::InGame(void *data)
{
  (void)data;
  if (_soundOn == 0)
    {
      _InGame.SetLoop(true);
      _InGame.SetVolume(20.5);
      _InGame.Play();
    }
}

void	Sound::InGameStop()
{
  if (_soundOn == 0)
    {
      _InGame.Stop();
    }
}

void	Sound::InMenuStop()
{
  if (_soundOn == 0)
    _InMenu.Stop();
}

void	Sound::InMenu()
{
  if (_soundOn == 0)
    {
      _InMenu.SetLoop(true);
      _InMenu.SetVolume(20.5);
      _InMenu.Play();
    }
}

void	Sound::StartTicTacBomb(float x, float y, float z)
{
  if (_soundOn == 0)
    {
      _TicTacBomb.SetPosition(x, y, z);
      _TicTacBomb.Play();
    }
}

void	Sound::StopTicTacBomb()
{
  if (_soundOn == 0)
    _TicTacBomb.Stop();
}

void	Sound::StartExplosion(float x, float y, float z)
{
  if (_soundOn == 0)
    {
      _ExplosionBomb.SetPosition(x, y, z);
      _ExplosionBomb.Play();
    }
}

void	Sound::StopExplosion()
{
  if (_soundOn == 0)
    _ExplosionBomb.Stop();
}
