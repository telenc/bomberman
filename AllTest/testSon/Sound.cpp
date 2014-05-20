//
// Sound.cpp for Sound in /home/martre_s/Epitech/cpp_bomberman/AllTest/testSon
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Mon May 19 15:57:02 2014 Steven Martreux
// Last update Tue May 20 17:35:36 2014 Steven Martreux
//

#include	"Sound.hpp"

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
