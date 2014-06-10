//
// MenuNumber.hpp for mEnu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Mon Jun  2 02:10:08 2014 Remi telenczak
// Last update Tue Jun 10 16:58:03 2014 Remi telenczak
//

#ifndef		_MENUNUMBER
# define	_MENUNUMBER

# include	"ModelList.hpp"
# include	"EventManager.hpp"
# include	<Clock.hh>
# include	<BasicShader.hh>
# include	<Input.hh>

class MenuBoxNumber;
class MenuNumber
{
public:
  MenuNumber(ModelList *, EventManager *, gdl::Clock *);
  ~MenuNumber();
  void	draw(gdl::BasicShader &, gdl::Clock const &);
  int	update(gdl::Clock &, gdl::Input &);
  void	eventKeyUp(void *data);
  void	eventKeyA(void *data);
  void	eventKeyDown(void *data);
  void	upIt(std::list<int>::iterator );
  void	downIt(std::list<int>::iterator);
  int	getResult();
private:
  ModelList	*_mod;
  EventManager	*_event;
  gdl::Clock *_clock;
  std::list<MenuBoxNumber *>	listBox;
  std::list<MenuBoxNumber *>	listBoxToDelete;
  ICallBack	*callKeyUp;
  ICallBack	*callKeyDown;
  ICallBack	*callKeyA;
  std::list<int>		result;
  int		_nextX;
  std::map<int, float> rotationCube;
  bool		end;
};

#endif
