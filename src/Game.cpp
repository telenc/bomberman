//
// Game.cpp for Game in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:18:15 2014 Steven Martreux
// Last update Fri Jun 13 17:50:55 2014 dedicker remi
//

#include	"Game.hpp"
#include	"Menu.hpp"
#include	"GenereMap.hpp"
#include	"Skybox.hpp"

Game::Game() : _display(0)
{
  this->eventManager = new EventManager();
  this->load = new Loader();
  while (load->getFinish() != true);
  this->engine = load->getEngine(); 
  this->menu = new Menu(load->getModel(), load->getEventManager(), engine->getClock()); 
  this->joystick = load->getController();
  this->sound = load->getSound();
  this->sound->InGame();
  this->menu->setSkybox(new Skybox(NULL, load->getModel(), load->getEventManager(), engine->getClock()));
}

void	Game::playMenu()
{
  while (engine->update(menu) && menu->getFinish() != 0)
    {
      engine->draw(menu);
      joystick->update();
    }
  this->menu->setFinish(0);
}

void	Game::draw()
{
  if (menu->getGoMap() == 1)
    {
      GenereMap gen(menu->getSizemap(), menu->getSizemap(), menu->getNumberIa(),load->getEventManager(), load->getModel(), engine->getClock());
      this->map = gen.getMap();
      this->map->setSkybox(new Skybox(map, load->getModel(), load->getEventManager(), engine->getClock()));
      _display = 1;
      std::cout << "CREATION DE MAP !" << std::endl;
      exit(0);
    }
  if (_display == 0)
    playMenu();
  else
    playMap();
}

int	Game::isFinish()
{
  return menu->getFinish();
}

void	Game::playMap()
{
  while (engine->update(map))
    {
      engine->draw(map);
      joystick->update();
    }
}

bool	Game::update()
{
  return true;
}

Game::~Game()
{
  delete eventManager;
}
