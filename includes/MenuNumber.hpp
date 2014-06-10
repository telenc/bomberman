//
// MenuNumber.hpp for mEnu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Mon Jun  2 02:10:08 2014 Remi telenczak
<<<<<<< HEAD
// Last update Tue Jun 10 16:58:03 2014 Remi telenczak
=======
// Last update Tue Jun 10 15:00:00 2014 thomas mendez
>>>>>>> 916de7b3c20cf250f236b6b4424aec081965524c
//

#ifndef		_MENUNUMBER
# define	_MENUNUMBER

# include	"ModelList.hpp"
# include	"EventManager.hpp"
#include        "Skybox.hpp"
# include	<Clock.hh>
# include	<BasicShader.hh>
# include	<Input.hh>

class MenuBoxNumber;
class MenuNumber
{
public:
  MenuNumber(ModelList *, EventManager *, gdl::Clock *);
  ~MenuNumber();
  int	draw(gdl::BasicShader &, gdl::Clock const &);
  int	update(gdl::Clock &, gdl::Input &);
  void	eventKeyUp(void *data);
  void	eventKeyA(void *data);
  void	eventKeyDown(void *data);
<<<<<<< HEAD
  void	upIt(std::list<int>::iterator );
  void	downIt(std::list<int>::iterator);
  int	getResult();
=======
void	upIt(std::list<int>::iterator );
void	downIt(std::list<int>::iterator);
int	getResult();
void	setSkybox(Skybox *skybox);
>>>>>>> 916de7b3c20cf250f236b6b4424aec081965524c
private:
  ModelList	*_mod;
  EventManager	*_event;
  gdl::Clock *_clock;
  std::list<MenuBoxNumber *>	listBox;
  std::list<MenuBoxNumber *>	listBoxToDelete;
  ICallBack	*callKeyUp;
  ICallBack	*callKeyDown;
  ICallBack	*callKeyA;
<<<<<<< HEAD
  std::list<int>		result;
  int		_nextX;
  std::map<int, float> rotationCube;
  bool		end;
=======
std::list<int>		result;
int		_nextX;
std::map<int, float> rotationCube;
  Skybox *_skin;
>>>>>>> 916de7b3c20cf250f236b6b4424aec081965524c
};

#endif
