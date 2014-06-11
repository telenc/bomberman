//
// Game.cpp for Game in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:18:15 2014 Steven Martreux
// Last update Wed Jun 11 11:17:41 2014 dedicker remi
//

#include	"Game.hpp"

Game::Game()
{
  this->eventManager = new EventManager();
  this->load = new Loader();
  while (load->getFinish() != true);
  this->menu = new Menu(load->getModel(), load->getEventManager(), engine->getClock());
  this->joystick = load->getController();
  this->engine = load->getEngine(); 
  this->sound = load->getSound();
  this->menu->setSkybox(new Skybox(NULL, load->getModel(), load->getEventManager(), engine->getClock()));
}

void	Game::playMenu()
{
  while (engine->update(menu))
    {
      engine->draw(menu);
      joystick->update();
    }
}
/*
void	Game::playMap()
{
}
*/
bool	Game::update()
{
  
  return true;
}

Game::~Game()
{
  delete eventManager;
}
