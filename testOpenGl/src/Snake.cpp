//
// Snake.cpp for Snake in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Mon Mar 17 10:20:17 2014 telenc_r
// Last update Mon Mar 17 10:58:09 2014 telenc_r
//

#include	"Snake.hpp"
#include	"Map.hpp"
#include	"Tile.hpp"

Snake::Snake(Map *map) : _map(map)
{
  int	middle_w;
  int	middle_h;

  this->_size = 4;
  this->_direction = 1;
  this->_directionFruit = 1;
  middle_w = map->getWidth() / 2;
  middle_h = map->getHeight() / 2;
  this->_snake.push_back(map->getTile(middle_h, middle_w));
  this->_snake.push_back(map->getTile(middle_h, middle_w - 1));
  this->_snake.push_back(map->getTile(middle_h, middle_w - 2));
  this->_snake.push_back(map->getTile(middle_h, middle_w - 3));
}

int	Snake::getDirectionFruit()
{
  return this->_directionFruit;
}

void	Snake::changeDirectionFruit()
{
  if (this->_directionFruit == 1)
    this->_directionFruit = 0;
  else
    this->_directionFruit = 1;
}

void	Snake::removeSnake()
{
  if (this->_snake.size() > 4)
    {
      this->_snake.pop_back();
      this->_size -= 1;
    }
}

void	Snake::checkAddSnake(int y, int x, Tile *last)
{
  if (this->_map->getTile(y, x)->getType() == 'w')
    {
      if (_map->getTile(last->getY() - 1, last->getX())->getType() != 'w' &&
	  this->asSnake(last->getY() - 1, last->getX()) == true)
	this->_snake.push_back(_map->getTile(last->getY() - 1, last->getX()));
      if (_map->getTile(last->getY() + 1, last->getX())->getType() != 'w' &&
	  this->asSnake(last->getY() + 1, last->getX()) == true)
	this->_snake.push_back(_map->getTile(last->getY() + 1, last->getX()));
      if (_map->getTile(last->getY(), last->getX() - 1)->getType() != 'w' &&
	  this->asSnake(last->getY(), last->getX() - 1) == true)
	this->_snake.push_back(_map->getTile(last->getY(), last->getX() - 1));
      if (_map->getTile(last->getY(), last->getX() + 1)->getType() != 'w' &&
	  this->asSnake(last->getY(), last->getX() + 1) == true)
	this->_snake.push_back(_map->getTile(last->getY(), last->getX() + 1));
    }
  else
    this->_snake.push_back(_map->getTile(y, x));
}

void	Snake::addSnake()
{
  Tile * last;
  Tile *before;
  Tile *sauv;
  std::list<Tile *>::const_iterator i;

  i = _snake.begin();
  before = *i;
  ++i;
  sauv = before;
  last = *i;
  while (i != _snake.end())
    {
      before = *i;
      ++i;
      if (i != _snake.end())
	{
	  sauv = before;
	  last = *i;
	}
      else
	before = sauv;
    }
  this->setSizeSnake(this->getSizeSnake() + 1);
  // verifier si on peux en rajouter
  if (before->getX() - last->getX() == 0 && before->getY() - last->getY() == 1)
    this->checkAddSnake(last->getY() - 1, last->getX(), last);
  else if (before->getX() - last->getX() == 0 && before->getY() - last->getY() == -1)
    this->checkAddSnake(last->getY() + 1, last->getX(), last);
  else if (before->getX() - last->getX() == 1 && before->getY() - last->getY() == 0)
    this->checkAddSnake(last->getY(), last->getX() - 1, last);
  else
    this->checkAddSnake(last->getY(), last->getX() + 1, last);
}

bool	Snake::asSnake(int x, int y) const
{
  bool  good;
  std::list<Tile *>::const_iterator i;

  good = true;
  for(i = _snake.begin() ; i != _snake.end() ; ++i)
    {
      if ((*i)->getX() == x && (*i)->getY() == y)
	good = false;
    }
  return (good);
}

bool	Snake::checkInSnake(int x, int y) const
{
  std::list<Tile *>::const_iterator i;

  i = _snake.begin();
  i++;
  while (i != _snake.end())
    {
      if ((*i)->getX() == x && (*i)->getY() == y)
	return (false);
      i++;
    }
  return (true);
}

void	Snake::setSizeSnake(int size)
{
  this->_size = size;
}

int	Snake::getSizeSnake() const
{
  return (this->_size);
}

void	Snake::changeDirectionLeft()
{
  if (this->_directionFruit == 1)
    {
      this->_direction -= 1;
      if (this->_direction <= 0)
	this->_direction = 4;
    }
  else
    {
  this->_direction += 1;
  if (this->_direction > 4)
    this->_direction = 1;
    }
}

void	Snake::changeDirectionRight()
{
  if (this->_directionFruit == 0)
    {
      this->_direction -= 1;
      if (this->_direction <= 0)
	this->_direction = 4;
    }
  else
    {
      this->_direction += 1;
      if (this->_direction > 4)
	this->_direction = 1;
    }
}

int	Snake::getDirection() const
{
  return this->_direction;
}

bool	Snake::inSnake() const
{
  Tile	*currentTile;

  currentTile = this->_snake.front();
  if (checkInSnake(currentTile->getX(), currentTile->getY()) == false)
    return (false);
  return (true);
}

void	Snake::move()
{
  Tile	*currentTile;
  Tile	*newTile;

  currentTile = this->_snake.front();
  newTile = NULL;
  if (this->_direction == 1)
    newTile = this->_map->getTile(currentTile->getY(), currentTile->getX() + 1);
  else if (this->_direction == 2)
    newTile = this->_map->getTile(currentTile->getY() + 1, currentTile->getX());
  else if (this->_direction == 3)
    newTile = this->_map->getTile(currentTile->getY(), currentTile->getX() - 1);
  else if (this->_direction == 4)
    newTile = this->_map->getTile(currentTile->getY() - 1, currentTile->getX());
  this->_snake.push_front(newTile);
  this->_snake.pop_back();
}

std::list<Tile *>	Snake::getSnake() const
{
  return this->_snake;
}
