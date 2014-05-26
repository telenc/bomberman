//
// Sound.cpp for Sound in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:23:13 2014 Steven Martreux
// Last update Mon May 26 05:55:29 2014 Remi telenczak
//

#include	"Sound.hpp"

Sound::Sound(EventManager *event) : _event(event), _position(0, 0, 0)
{
  if (!_InGame.OpenFromFile("sound/SoundInGame.wav"))
    std::cerr << "Fail to open SoundInGame" << std::endl;
  if (!_TicTacBomb.OpenFromFile("sound/TicTacBomb.wav"))
    std::cerr << "Fail to open TicTacBomb" << std::endl;
  if (!_ExplosionBomb.OpenFromFile("sound/Explosion.wav"))
    std::cerr << "Fail to open Explosion" << std::endl;
  if (!_InMenu.OpenFromFile("sound/Menu.wav"))
    std::cerr << "Fail to open Menu.wav" << std::endl;
  callBombDrop = new CallBack<Sound>(this, &Sound::eventBombDrop);
  event->listenEvent("bombDrop", callBombDrop);
  callPlayerMove = new CallBack<Sound>(this, &Sound::eventPlayerMove);
  event->listenEvent("playerPosition", callPlayerMove);
}

Sound::~Sound()
{

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
  glm::vec3	*test;

  test = (glm::vec3 *) data;
  (void)test;
  //this->StartTicTacBomb(test->x * 10, test->y * 10, test->z * 10);
  this->StartTicTacBomb(1300, 1300, 1300);
}

void	Sound::setPlayer(float x, float y, float z)
{
  sf::Listener::SetPosition(x * 0, y * 0, z * 0);
}

void	Sound::InGame()
{
  _InGame.SetLoop(true);
  _InGame.SetVolume(20.5);
  _InGame.Play();
}

void	Sound::InGameStop()
{
  _InGame.Stop();
}

void	Sound::InMenuStop()
{
  _InMenu.Stop();
}

void	Sound::InMenu()
{
  _InMenu.SetLoop(true);
  _InMenu.SetVolume(20.5);
  _InMenu.Play();
}

void	Sound::StartTicTacBomb(float x, float y, float z)
{
  _TicTacBomb.SetLoop(true);
  _TicTacBomb.SetPosition(x, y, z);
  _TicTacBomb.Play();
}

void	Sound::StopTicTacBomb()
{
  _TicTacBomb.Stop();
}

void	Sound::StartExplosion(float x, float y, float z)
{
  _ExplosionBomb.SetLoop(true);
  _ExplosionBomb.SetPosition(x, y, z);
  _ExplosionBomb.Play();
}

void	Sound::StopExplosion()
{
  _ExplosionBomb.Stop();
}
