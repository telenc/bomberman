//
// Loader.hpp for Loader in /home/martre_s/workspace/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Sat May 24 17:09:41 2014 Steven Martreux
// Last update Sat May 24 18:36:39 2014 Steven Martreux
//

#ifndef		_LOADER_HPP_
#define		_LOADER_HPP_

#include	"Graphics.hpp"
#include	"ModelList.hpp"
#include	"Controller.hpp"
#include	"Sound.hpp"
#include	"Thread.hpp"
#include	"EventManager.hpp"

class		Loader
{
public:
  Loader();
  ~Loader();
  Graphics	*getEngine(void) const;
  ModelList	*getModel(void) const;
  Controller	*getController(void) const;
  Sound		*getSound(void) const;
  EventManager	*getEventManager(void) const;
  void		InitEvery();
  bool		getFinish() const;
  void		setFinish(bool);
private:
  Graphics	*_engine;
  ModelList	*_mod;
  Controller	*_controller;
  Sound		*_sound;
  EventManager	*_eventManager;
  bool		_finish;
};

#endif		/* _LOADER_HPP_ */
