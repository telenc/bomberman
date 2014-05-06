//
// Map.cpp for map in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 07:32:32 2014 telenc_r
// Last update Sun Apr  6 16:03:09 2014 dedicker remi
//

#include	<map>
#include	<stdlib.h>
#include	"Map.hpp"
#include	<cstdlib>
#include	<ctime>
#include	"Snake.hpp"
#include	"Game.hpp"
#include	"CreateEvent.hpp"

Map::Map(int w, int h, Game *game): _width(w), _height(h), _game(game)
{
  int	x;
  int	y;
  Tile	*tmp;
  int	total;

  y = 0;
  this->_is_alive = 1;
  while (y < h)
    {
      x = 0;
      this->_map.push_back(std::vector<Tile *>());
      while (x < w)
	{
	  tmp = new Tile(x, y);
	  if (x == 0 || y == 0 || x == w - 1 || y == h - 1)
	    tmp->setType('w');
	  this->_map[y].push_back(tmp);
	  x++;
	}
      y++;
    }
  this->_popfruit = 0;
  this->eventManager = new CreateEvent(game);
  this->snake = new Snake(this);
  total = w * h;
  if (total < 2000)
    addFruit('a');
  else
    while (total > 2000)
      {
	addFruit('a');
	total -= 2000;
      }
}

bool	Map::asFruit(int x, int y) const
{
  bool  good;
  std::list<Fruit *>::const_iterator i;

  good = true;
  for(i = _fruit.begin(); i != _fruit.end(); ++i)
    {
      if ((*i)->getX() == x && (*i)->getY() == y)
	good = false;
    }
  return (good);
}

void	Map::addFruit(char type)
{
  int	x;
  int	y;
  bool	good;
  Fruit *result;

  good = false;
  std::srand(std::time(0));
  while (good == false)
    {
      x = std::rand() % _width;
      y = std::rand() % _height;
      if (this->getTile(y, x)->getType() != 'w')
	if (this->snake->asSnake(x, y) == true && this->asFruit(x, y) == true)
	  good = true;
    }
  result = new Fruit(x, y, type);
  _fruit.push_back(result);
  _popfruit++;
  if (_popfruit == 5)
    pop_special_fruit();
}

void	Map::checkFruit(int x, int y)
{
  std::list<Fruit *>::iterator i;

  for(i = _fruit.begin(); i != _fruit.end(); ++i)
    {
      if ((*i)->getX() == x && (*i)->getY() == y)
	{
	  this->eventManager->newEvent(((*i)->getType()), (*i));
	  _fruit.erase(i);
	  addFruit('a');
	  return ;
	}
    }
}

void	Map::clearRandWall()
{
  std::list<Tile *>::iterator i;

  for (i = this->_wallrand.begin(); i != _wallrand.end(); ++i)
    {
      this->getTile((*i)->getY(), (*i)->getX())->setType(' ');
    }
  while (!this->_wallrand.empty())
    {
      this->_wallrand.pop_back();
    }
}

void	Map::addWall()
{
  int	x;
  int	y;
  bool	good;
  Tile	*wall;

  good = false;
  std::srand(std::time(0));
  while (good == false)
    {
      x = std::rand() % _width;
      y = std::rand() % _height;
      if (this->getTile(y, x)->getType() != 'w')
	if (this->snake->asSnake(x, y) == true && this->asFruit(x, y) == true)
	  {
	    good = true;
	    wall = this->getTile(y, x);
	    wall->setType('w');
	    this->_wallrand.push_back(wall);
	  }
    }
}

void	Map::pop_special_fruit()
{
  std::map<char , AEventNib*(CreateEvent::*)(Fruit*) >::iterator i;
  std::map<char , AEventNib*(CreateEvent::*)(Fruit*) > _map;
  int	x;

  _map = this->eventManager->getMapEvent();
  i = _map.begin();
  i++;
  x = std::rand() % 6;
  while (i != _map.end() && x > 0)
    {
      i++;
      x--;
    }
  addFruit(i->first);
  this->_popfruit = 0;
}

int	Map::isAlive() const
{
  return this->_is_alive;
}

void	Map::checkEvent()
{
  this->eventManager->updateEvents();
}

void	Map::checkSnake()
{
  Tile	*front;

  front = this->snake->getSnake().front();
  if (front->getType() == 'w')
    {
      this->_is_alive = 0;
      this->_game->addFinalScore(this->_game->getScore());
    }
  else if (asFruit(front->getX(), front->getY()) == false)
    this->checkFruit(front->getX(), front->getY());
  else if (this->snake->inSnake() == false)
    {
      this->_is_alive = 0;
      this->_game->addFinalScore(this->_game->getScore());
    }
}

Tile	*Map::getTile(int y, int x) const
{
  return this->_map[y][x];
}

int	Map::getWidth() const
{
  return this->_width;
}

int	Map::getHeight() const
{
  return this->_height;
}

std::list<Fruit *>	Map::getFruit() const
{
  return this->_fruit;
}

Snake	*Map::getSnake() const
{
  return this->snake;
}
