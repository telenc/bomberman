//
// Game.cpp for Game in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Fri May  9 14:18:15 2014 Steven Martreux
// Last update Sun Jun 15 20:29:31 2014 thomas mendez
//

#include	"Game.hpp"
#include	"Menu.hpp"
#include	"MenuIG.hpp"
#include	"GenereMap.hpp"
#include	"Skybox.hpp"

Game::Game() : _display(0)
{
  if (getenv("DISPLAY") == NULL)
    throw new myException("Where is env ?");
  //  this->intro_game();
  this->eventManager = new EventManager();
  this->load = new Loader();
  while (load->getFinish() != true);
  this->engine = load->getEngine();
  this->menu = new Menu(load->getModel(), load->getEventManager(), engine->getClock());
  this->menuIG = new MenuIG(load->getModel(), load->getEventManager(), engine->getClock());
  this->menuIG->setSkybox(new Skybox(NULL, load->getModel(), load->getEventManager(), engine->getClock()));
  this->joystick = load->getController();
  this->sound = load->getSound();
  this->state = 0;
  this->menu->setSkybox(new Skybox(NULL, load->getModel(), load->getEventManager(), engine->getClock()));
  this->_callKeyStart = new CallBack<Game>(this, &Game::eventKeyStart);
  this->eventManager->listenEvent("pause", _callKeyStart);
}

void	Game::eventKeySelect(void *data)
{
  (void)data;
}

void	Game::intro_game()
{
  libvlc_instance_t	*instance;
  libvlc_media_player_t	*player;
  libvlc_media_t	*media;
  std::fstream	        file("sound/intro.avi");

  if (!file.is_open())
    throw new myException("intro.avi not found.");
  instance = libvlc_new (0, NULL);
  media = libvlc_media_new_path (instance, "sound/intro.avi");
  player = libvlc_media_player_new_from_media (media);
  libvlc_media_release (media);
  libvlc_media_player_play (player);
  sleep(33);
  libvlc_media_player_stop (player);
  libvlc_media_player_release (player);
  libvlc_release (instance);
}

void    Game::eventKeyStart(void *data)
{
  if (state == 0)
    state = 1;
  else
    state = 0;
  std::cout << "je suis la " << std::endl;
  (void)data;
}

void	Game::playMenu()
{
  while (engine->update(menu) && menu->getFinish() != 0 && menu->getGoMap() != 1 && menu->getGoMap() != 2)
    {
      engine->draw(menu);
      joystick->update();
    }
  if (menu->getGoMap() == 1 && menu->getFinish() != 0)
    {
      this->_gen = new GenereMap(menu->getSizemap(), menu->getSizemap(), menu->getNumberIa(),load->getEventManager(), load->getModel(), engine->getClock());
      this->map = _gen->getMap();
      this->map->setSkybox(new Skybox(map, load->getModel(), load->getEventManager(), engine->getClock()));
      _display = 1;
      this->menu->setGoMap(0);
    }
  else if (menu->getGoMap() == 2 && menu->getFinish() != 0)
    {
      this->_gen = new GenereMap(41, 41, 0,load->getEventManager(), load->getModel(), engine->getClock(), ZOMBIE);
      this->map = _gen->getMap();
      this->map->setSkybox(new Skybox(map, load->getModel(), load->getEventManager(), engine->getClock()));
      _display = 1;
      this->menu->setGoMap(0);
    }
  else if (menu->getGoMap() == 0)
    this->menu->setFinish(0);
}

void	Game::draw()
{
  while (menu->getFinish())
    {
      try
	{
	  if (_display == 0)
	    {
	      playMenu();
	    }
	  else
	    {
	      playMap();
	    }
	}
      catch(const myException *e)
	{
	  std::cerr << "Error : " << e->what() << std::endl;
	  this->menu->setCurrentMenu(0);
	  _display = 0;
	}
    }
}

int	Game::isFinish()
{
  return menu->getFinish();
}

void    Game::playMap()
{
  _runMap = 0;
  while (engine->update(map))
    {
      if (!map->getSelect())
        engine->draw(map);
      else
        {
          if (menuIG->getBack() == 1)
            {
              this->map->setSelect(false);
              menuIG->setBack(0);
              this->engine->getCamera()->setPosition(-3, -4, -3);
            }
          //      if (menuIG->getBack() == 1)
          //_runMap = 1;
          engine->draw(menuIG);
	  engine->update(menuIG, map);
        }
      joystick->update();
    }

  this->menu->setFinish(0);
}

bool	Game::update()
{
  return true;
}

Game::~Game()
{
  //  delete eventManager;
}
