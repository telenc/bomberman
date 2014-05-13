//
// EventManager.hpp for EventManager in /home/remi/testBomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May  7 06:31:56 2014 Remi telenczak
// Last update Wed May  7 08:37:38 2014 Remi telenczak
//

#ifndef		_EVENT_MANAGER
# define	_EVENT_MANAGER

# include	<vector>
# include	<list>
# include	<string>
# include	"CallBack.hpp"

class EventManager
{
public:
  EventManager();
  ~EventManager();

  void	listenEvent(std::string, ICallBack *callBack);
  void	dispatchEvent(std::string, void *);
  void	removeEvent(std::string, ICallBack *);
private:
  std::vector<std::pair<std::string, ICallBack *> > _listEvent;
};

#endif
