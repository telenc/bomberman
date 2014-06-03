//
// MenuNumber.cpp for MenuNumber in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Mon Jun  2 02:08:04 2014 Remi telenczak
// Last update Tue Jun  3 07:13:12 2014 Remi telenczak
//

#include	"MenuNumber.hpp"
#include	"MenuBoxNumber.hpp"
MenuNumber::MenuNumber(ModelList *mod, EventManager *event, gdl::Clock *clock) : _mod(mod), _event(event), _clock(clock)
{
  MenuBoxNumber	*firstBox;

  firstBox = new MenuBoxNumber(NULL, _mod, _event, _clock);
  firstBox->set_x(10);
  this->_nextX = 5;
  firstBox->set_y(20);
  firstBox->set_vy(-1.8);
  this->listBox.push_back(firstBox);


  callKeyA = new CallBack<MenuNumber>(this, &MenuNumber::eventKeyA);
  event->listenEvent("keyA", callKeyA);

  callKeyUp = new CallBack<MenuNumber>(this, &MenuNumber::eventKeyUp);
  event->listenEvent("keyUp", callKeyUp);
  callKeyDown = new CallBack<MenuNumber>(this, &MenuNumber::eventKeyDown);
  event->listenEvent("keyDown", callKeyDown);
  result.push_back(1);
  rotationCube.insert(std::pair<int, float>(0, 0));
  rotationCube.insert(std::pair<int, float>(1, 90));
  rotationCube.insert(std::pair<int, float>(2, 180));
  rotationCube.insert(std::pair<int, float>(3, 270));
  rotationCube.insert(std::pair<int, float>(4, 360));
  rotationCube.insert(std::pair<int, float>(5, 450));
  rotationCube.insert(std::pair<int, float>(6, 540));
  rotationCube.insert(std::pair<int, float>(7, 630));
  rotationCube.insert(std::pair<int, float>(8, 720));
  rotationCube.insert(std::pair<int, float>(9, 810));
}

void	MenuNumber::upIt(std::list<int>::iterator it)
{
  std::list<int>::iterator it2;

  it = result.begin();
  while (it != result.end())
    {
      if (it == result.begin())
	*it += 1;
      if (*it > 9)
	{
	  it2 = it;
	  it2++;
	  *it = 0;
	  //++it2;
	  if (it2 != result.end())
	    {
	      *it2 += 1;
	    }
	  else
	    {
	      MenuBoxNumber	*firstBox;

	      firstBox = new MenuBoxNumber(NULL, _mod, _event, _clock);
	      firstBox->set_x(_nextX);
	      _nextX -= 5;
	      firstBox->set_y(20);
	      firstBox->set_vy(-2.0);
	      this->listBox.push_back(firstBox);
	      this->result.push_back(1);
	      return;
	    }
	}
      it++;
    }
  /*
    if (it == result.end())
    {
    MenuBoxNumber	*firstBox;

    firstBox = new MenuBoxNumber(NULL, _mod, _event, _clock);
    firstBox->set_x(_nextX);
    std::cout << "ON ADD" << std::endl;
    _nextX -= 5;
    firstBox->set_y(20);
    firstBox->set_vy(-2.0);
    this->listBox.push_back(firstBox);
    this->result.push_back(1);
    return ;
    }
    *it += 1;
    if (*it > 9)
    {
    this->upIt(++it);
    *it = 0;
    }*/
}

void	MenuNumber::downIt(std::list<int>::iterator it)
{
  std::list<int>::iterator it2;
  std::list<MenuBoxNumber *>::iterator it3;
  std::list<MenuBoxNumber *>::iterator it4;

  it = result.begin();
  it3 = listBox.begin();
  while (it != result.end())
    {
      if (it == result.begin())
	*it -= 1;
      if (*it < 0)
	{
	  it2 = it;
	  it2++;
	  it4 = it3;
	  it4++;
	  *it = 9;
	  //++it2;
	  if (it2 != result.end())
	    {
	      *it2 -= 1;
	      it2++;
	      if (it2 == result.end())
		{
		  it2--;
		  if (*it2 == 0)
		    {
		  result.erase(it2);
		  listBoxToDelete.push_back(*it4);
		  (*it4)->goDelete();
		  listBox.erase(it4);
		  _nextX += 5;
		    }
		}
	    }

	}
      it3++;
      it++;
    }
}

void	MenuNumber::eventKeyUp(void *data)
{
  std::list<int>::iterator it;

  it = result.begin();
  std::cout << _clock->getElapsed() << std::endl;
  this->upIt(it);
  (void)data;
  std::cout << "On up result : " << getResult() << std::endl;
}

void	MenuNumber::eventKeyA(void *data)
{
  (void)data;
}

void	MenuNumber::eventKeyDown(void *data)
{
  (void)data;
  if (getResult() != 0)
    {
      this->downIt(result.begin());
    }
  //std::cout << "On down " << getResult() << std::endl;
}

int	MenuNumber::getResult()
{
  int	res;
  int	multi;

  std::list<int>::iterator it;

  res = 0;
  multi = 1;
  it = this->result.begin();
  while (it != result.end())
    {
      res += (*it * multi);
      multi *= 10;
      it++;
    }
  return res;
}

MenuNumber::~MenuNumber()
{
}

void MenuNumber::draw(gdl::BasicShader &shader, gdl::Clock const &clock)
{
  std::list<MenuBoxNumber *>::iterator it;

  it = listBox.begin();
  while (it != listBox.end())
    {
      (*it)->draw(shader, clock);
      it++;
    }
  it = listBoxToDelete.begin();
  while (it != listBoxToDelete.end())
    {
      (*it)->draw(shader, clock);
      it++;
    }

  (void)shader;
  (void)clock;
}

int	MenuNumber::update(gdl::Clock &clock, gdl::Input &input)
{
  std::list<MenuBoxNumber *>::iterator it;
  std::list<int>::iterator it2;
  int i = 0;

  it = listBox.begin();
  it2 = result.begin();
  while (it != listBox.end())
    {
      if ((*it)->update(clock, input) == false)
	it = listBox.erase(it);
      if (it2 == result.end())
	return -1;
      int test = (*it2);
      i++;
      (void)test;
      (*it)->setTargetRotation(rotationCube[*it2]);
      it2++;
      it++;
    }

  it = listBoxToDelete.begin();
  while (it != listBoxToDelete.end())
    {
      if ((*it)->update(clock, input) == false)
	it = listBoxToDelete.erase(it);
      it++;
    }

  (void)clock;
  (void)input;
  return -1;
}