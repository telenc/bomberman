//
// Loader.cpp for Loader in /home/martre_s/workspace/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Sat May 24 17:09:28 2014 Steven Martreux
// Last update Sat May 24 18:37:53 2014 Steven Martreux
//

#include	"Loader.hpp"

static void	*runThreadLoader(void *data)
{
  Loader	*load;

  load = (Loader *)data;
  load->InitEvery();
  load->setFinish(true);
  return (NULL);
}

Loader::Loader()
{
  Thread	*loader;

  _eventManager	= new EventManager();
  _engine = new Graphics(_eventManager);
  _engine->initialize();
  _controller = new Controller(_eventManager);
  _finish = false;
  loader = new Thread(runThreadLoader, this, "Thread Loader");
  (void)loader;
}

void		Loader::InitEvery()
{
  _sound = new Sound(_eventManager);
  _mod = new ModelList();
  _engine->setModelList(_mod);
}

bool		Loader::getFinish() const
{
  return _finish;
}

void		Loader::setFinish(bool finish)
{
  _finish = finish;
}

EventManager	*Loader::getEventManager(void) const
{
  return this->_eventManager;
}

Graphics	*Loader::getEngine(void) const
{
  return this->_engine;
}

ModelList	*Loader::getModel(void) const
{
  return this->_mod;
}

Controller	*Loader::getController(void) const
{
  return this->_controller;
}

Sound		*Loader::getSound(void) const
{
  return this->_sound;
}

Loader::~Loader()
{

}
