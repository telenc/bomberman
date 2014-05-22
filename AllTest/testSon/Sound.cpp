//
// Sound.cpp for Sound in /home/martre_s/Epitech/cpp_bomberman/AllTest/testSon
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon May 19 15:57:02 2014 Steven Martreux
// Last update Thu May 22 09:31:12 2014 Remi telenczak
//

#include	"Sound.hpp"
#include <unistd.h>
int main()
{
  Sound s;

  s.setPlayer(0, 0, 0);
  s.StartTicTacBomb(1000, 1000, 1000);
  sleep(10);
}

Sound::Sound()
{
  if (!_InGame.OpenFromFile("Sound/SoundInGame.wav"))
    std::cerr << "Fail to open SoundInGame" << std::endl;
  if (!_TicTacBomb.OpenFromFile("Sound/TicTacBomb.wav"))
    std::cerr << "Fail to open TicTacBomb" << std::endl;
  if (!_ExplosionBomb.OpenFromFile("Sound/Explosion.wav"))
    std::cerr << "Fail to open Explosion" << std::endl;
  if (!_InMenu.OpenFromFile("Sound/Menu.wav"))
    std::cerr << "Fail to open Menu.wav" << std::endl;
}

Sound::~Sound()
{

}

void	Sound::setPlayer(float x, float y, float z)
{
  sf::Listener::SetPosition(x, y, z);
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
