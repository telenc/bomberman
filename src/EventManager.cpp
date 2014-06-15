//
// EventManager.cpp for EventManagerBomberman in /home/remi/testBomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May  7 06:31:46 2014 Remi telenczak
// Last update Sun Jun 15 19:46:52 2014 Remi telenczak
//

#include	<iostream>
#include	"EventManager.hpp"

/*
  exemple

void CLASS:FUNC(void *param)
{

}

listen :
ICallBack call = new CallBack<CLASS>(this, &CLASS:FUNC);
event->listenEvent("evenement", call);

remove :
event->removeEvent("evenement", call);

dispatch
event->dispatchEvent("evenement", param)
 */


EventManager::EventManager()
{

}

EventManager::~EventManager()
{

}


void	EventManager::listenEvent(std::string event, ICallBack *callBack)
{
  this->_listEvent.push_back(std::make_pair<std::string, ICallBack *>(event, callBack));
}


void								EventManager::dispatchEvent(std::string event, void *data)
{
  std::vector<std::pair<std::string, ICallBack *> >::iterator	it;
  std::list<ICallBack *>					listCallBack;
  ICallBack							*tmp;

  it = this->_listEvent.begin();
  while (it != this->_listEvent.end())
    {
      if (it->first == event)
	listCallBack.push_back(it->second);
      it++;
    }
  while (!listCallBack.empty())
    {
      tmp = listCallBack.front();
      listCallBack.pop_front();
      if (tmp)
	tmp->call(data);
    }
}

void								EventManager::removeEvent(std::string event, ICallBack *callBack)
{
  std::vector<std::pair<std::string, ICallBack *> >::iterator	it;

  it = this->_listEvent.begin();
  while (it != this->_listEvent.end())
    {
      if (it->second == callBack && it->first == event)
	{
	  this->_listEvent.erase(it);
	  return ;
	}
      it++;
    }
}
