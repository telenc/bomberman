//
// MenuNumber.hpp for mEnu in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Mon Jun  2 02:10:08 2014 Remi telenczak
// Last update Sun Jun 15 03:02:48 2014 Steven Martreux
//

#ifndef				_MENUNUMBER_
# define			_MENUNUMBER_

# include			<Clock.hh>
# include			<BasicShader.hh>
# include			<Input.hh>
# include			"ModelList.hpp"
# include			"EventManager.hpp"
# include			"Skybox.hpp"

class MenuBoxNumber;
class MenuNumber
{
public:
  MenuNumber(ModelList *, EventManager *, gdl::Clock *);
  ~MenuNumber();
  int				draw(gdl::BasicShader &, gdl::Clock const &);
  int				update(gdl::Clock &, gdl::Input &);
  void				eventKeyUp(void *data);
  void				eventKeyA(void *data);
  void				eventKeyDown(void *data);
  void				upIt(std::list<int>::iterator );
  void				downIt(std::list<int>::iterator);
  int				getResult();
  void				setSkybox(Skybox *skybox);
  void				setMinNumber(int);
private:
  ModelList			*_mod;
  EventManager			*_event;
  gdl::Clock			*_clock;
  std::list<MenuBoxNumber *>	listBox;
  std::list<MenuBoxNumber *>	listBoxToDelete;
  ICallBack			*callKeyUp;
  ICallBack			*callKeyDown;
  ICallBack			*callKeyA;
  bool				end;
  std::list<int>		result;
  int				_nextX;
  std::map<int, float>		rotationCube;
  Skybox			*_skin;
  int				_min;
};

#endif
