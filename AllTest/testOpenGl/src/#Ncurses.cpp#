//
// Ncurses.cpp for nibbler in /home/martre_s/Epitech/Cpp/cpp_nibbler/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon Mar 31 12:47:08 2014 Steven Martreux
// Last update Sun Apr  6 15:43:22 2014 Steven Martreux
//

#include	<sys/ioctl.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<ncurses.h>
#include	<curses.h>
#include	<unistd.h>
#include	<sstream>
#include	<cstdlib>
#include	"myException.hpp"
#include	"Ncurses.hpp"
#include	"Game.hpp"
#include	"Snake.hpp"

ALibGraphic	*self;

extern "C" ALibGraphic *constructor_graphic(Game *game)
{
  self = new Ncurses(game);
  return self;
}

Ncurses::Ncurses(Game* game) : ALibGraphic(game)
{
  initscr();
  noecho();
  raw();
  if (has_colors() == FALSE)
    {
      endwin();
      throw new myException("Your term does not support color");
    }
  curs_set(0);
  win = newwin(0, 0, 0, 0);
  if (win == NULL)
    {
      endwin();
      throw new myException(" Lib Ncurses\n Fail init ncurses ");
    }
  start_color();
  init_pair(1, COLOR_BLUE, COLOR_BLUE);
  init_pair(2, COLOR_RED, COLOR_GREEN);
  init_pair(3, COLOR_GREEN, COLOR_GREEN);
  init_pair(4, COLOR_BLACK, COLOR_GREEN);
  init_pair(5, COLOR_YELLOW, COLOR_GREEN);
  init_pair(6, COLOR_BLUE, COLOR_GREEN);
  init_pair(7, COLOR_CYAN, COLOR_GREEN);
  init_pair(8, COLOR_MAGENTA, COLOR_GREEN);
  init_pair(9, COLOR_WHITE, COLOR_GREEN);
  createFruitColor();
  keypad(this->win, TRUE);
  box(this->win, 0, 0);
  mousemask(ALL_MOUSE_EVENTS, NULL);
  wrefresh(win);
  nodelay(win, TRUE);
  wclear(win);
}

void		Ncurses::createFruitColor()
{
  this->_colorFruit.insert(std::pair<char, int>('a', 2));
  this->_colorFruit.insert(std::pair<char, int>('r', 5));
  this->_colorFruit.insert(std::pair<char, int>('s', 8));
  this->_colorFruit.insert(std::pair<char, int>('d', 6));
  this->_colorFruit.insert(std::pair<char, int>('t', 4));
  this->_colorFruit.insert(std::pair<char, int>('m', 9));
  this->_colorFruit.insert(std::pair<char, int>('p', 7));
}

int		Ncurses::Scroll(char c, int i) const
{
  if (i < 0)
    return 0;
  else if (c == 'a')
    {
      if (h < LINES)
	return 0;
      if (i > this->h - LINES)
	return (h - LINES);
    }
  else if (c == 'b')
    {
      if (w < COLS)
	return 0;
      if (i > this->w - COLS)
	return (w - COLS);
    }
  return i;
}

void		Ncurses::printScore() const
{
  std::ostringstream ss;
  std::string score;

  ss << this->game()->getScore();
  score = "Score : " + ss.str();
  wattron(this->win, COLOR_PAIR(2));
  if (w > COLS)
    mvwprintw(this->win, LINES - 1, COLS / 2 - score.size() / 2, score.c_str());
  else if (w > COLS && h < LINES)
    mvwprintw(this->win, h - 1, COLS / 2 - score.size() / 2, score.c_str());
  else if (w < COLS && h < LINES)
    mvwprintw(this->win, h - 1, w / 2 - score.size() / 2 , score.c_str());
  else
    mvwprintw(this->win, LINES - 1, w / 2 - score.size() / 2 , score.c_str());
  wattroff(this->win, COLOR_PAIR(2));
  wrefresh(this->win);
}

void		Ncurses::printBackgroundMenu() const
{
  int		x;
  int		tmp;

  x = 0;
  wattron(this->win, COLOR_PAIR(1));
  while (x < LINES)
    {
      tmp = 0;
      while (tmp < COLS)
	{
	  mvwprintw(this->win, x, tmp, " ");
	  tmp++;
	}
      x++;
    }
  wattroff(this->win, COLOR_PAIR(1));
}

void		Ncurses::printButtonMenu() const
{
  wattron(this->win, COLOR_PAIR(2));
  mvwprintw(this->win, 9, 9, "                   ");
  mvwprintw(this->win, 10, 9, " Jouer Mode : Easy ");
  mvwprintw(this->win, 11, 9, "                   ");
  mvwprintw(this->win, 19, 9, "                   ");
  mvwprintw(this->win, 20, 9, " Jouer Mode : Hard ");
  mvwprintw(this->win, 21, 9, "                   ");
  mvwprintw(this->win, 29, 9, "         ");
  mvwprintw(this->win, 30, 9, " Quitter ");
  mvwprintw(this->win, 31, 9, "         ");
  wattroff(this->win, COLOR_PAIR(2));
}

void		Ncurses::printFruitMenu()
{
  std::map<char, int>::iterator j;
  int		tmp;

  tmp = 0;
  for (j = _colorFruit.begin(); j != _colorFruit.end(); ++j)
    {
      wattron(this->win, COLOR_PAIR((*j).second));
      mvwprintw(this->win, 39, 9 + tmp, "     ");
      mvwprintw(this->win, 40, 9 + tmp, "  Q  ");
      mvwprintw(this->win, 41, 9 + tmp, "     ");
      wattroff(this->win, COLOR_PAIR((*j).second));
      tmp += 20;
    }
}

void		Ncurses::printNameFruit() const
{
  int		tmp;

  wattron(this->win, COLOR_PAIR(4));
  mvwprintw(this->win, 40, 14, "Normal       ");
  mvwprintw(this->win, 40, 34, "RM           ");
  mvwprintw(this->win, 40, 54, "SpeedHack    ");
  mvwprintw(this->win, 40, 74, "Slow         ");
  mvwprintw(this->win, 40, 94, "Hangover     ");
  mvwprintw(this->win, 40, 114, "Give me more ");
  mvwprintw(this->win, 40, 134, "Random       ");
  tmp = 14;
  while (tmp <= 134)
    {
      mvwprintw(this->win, 39, tmp, "             ");
      mvwprintw(this->win, 41, tmp, "             ");
      tmp += 20;
    }
  wattroff(this->win, COLOR_PAIR(4));
}

void		Ncurses::printScoreMenu() const
{
  std::list<int>	list;
  std::list<int>::iterator i;
  std::ostringstream	ss;
  int	x;

  list = this->game()->getScores();
  i = list.begin();
  wattron(this->win , COLOR_PAIR(2));
  mvwprintw(this->win, 10, 134, " HighScores : ");
  x = 11;
  while (i != list.end())
    {
      ss << "      ";
      ss << (*i);
      mvwprintw(this->win, x, 134, "              ");
      mvwprintw(this->win, x, 134, ss.str().c_str());
      ss.str("");
      i++;
      x++;
    }
  wattroff(this->win , COLOR_PAIR(2));
}

void		Ncurses::printMenu()
{
  this->printBackgroundMenu();
  this->printButtonMenu();
  this->printFruitMenu();
  this->printNameFruit();
  this->printScoreMenu();
  wrefresh(this->win);
}

void		Ncurses::createPlan() const
{
  int	a;
  int	b;
  int	x;
  int	y;
  Tile *tile;
  Tile	*headSnake;

  headSnake = this->game()->getMap()->getSnake()->getSnake().front();
  a = headSnake->getY() - (LINES / 2);
  a = Scroll('a', a);
  y = 0;
  while (y < LINES)
    {
      b = headSnake->getX() - (COLS / 2);
      b	= Scroll('b', b);
      x = 0;
      while (x < COLS)
	{
	  if (y >= 0 && y < this->h && x >= 0 && x < this->w)
	    {
	      tile = this->game()->getMap()->getTile(a, b);
	      if (tile->getType() == 'w')
		{
		  wattron(this->win, COLOR_PAIR(1));
		  mvwprintw(this->win, y, x, " ");
		  wattroff(this->win, COLOR_PAIR(1));
		}
	      else
		{
		  wattron(this->win, COLOR_PAIR(3));
		  mvwprintw(this->win, y, x, " ");
		  wattroff(this->win, COLOR_PAIR(3));
		}
	    }
	  b++;
	  x++;
	}
      a++;
      y++;
    }
  wrefresh(this->win);
}

void		Ncurses::putFruit()
{
  std::list<Fruit *> fruit;
  std::list<Fruit *>::iterator i;
  std::map<char, int>::iterator j;
  Tile	*headSnake;
  int a;
  int b;

  headSnake = this->game()->getMap()->getSnake()->getSnake().front();
  fruit = this->game()->getMap()->getFruit();
  a = headSnake->getY() - (LINES / 2);
  b = headSnake->getX() - (COLS / 2);
  a = this->Scroll('a', a);
  b = this->Scroll('b', b);
  i = fruit.begin();
  while (i != fruit.end())
    {
      j = this->_colorFruit.find((*i)->getType());
      if (j != _colorFruit.end())
	{
	  wattron(this->win, COLOR_PAIR((*j).second));
	  mvwprintw(this->win, (*i)->getY() - a , (*i)->getX() - b, "Q");
	  wattroff(this->win, COLOR_PAIR((*j).second));
	}
      else
	{
	  wattron(this->win, COLOR_PAIR(2));
	  mvwprintw(this->win, (*i)->getY() - a , (*i)->getX() - b, "Q");
	  wattroff(this->win, COLOR_PAIR(2));
	}
      i++;
    }
  wrefresh(this->win);
}

void		Ncurses::createSnake() const
{
  std::list<Tile *> vect;
  std::list<Tile *>::iterator i;
  Tile	*headSnake;
  int a;
  int b;

  headSnake = this->game()->getMap()->getSnake()->getSnake().front();
  a = headSnake->getY() - (LINES / 2);
  b = headSnake->getX() - (COLS / 2);
  a = Scroll('a', a);
  b = Scroll('b', b);
  vect = this->game()->getMap()->getSnake()->getSnake();
  i = vect.begin();
  while (i != vect.end())
    {
      wattron(this->win, COLOR_PAIR(2));
      if (i == vect.begin())
	mvwprintw(this->win, (*i)->getY() - a, (*i)->getX() - b, "@");
      else
	mvwprintw(this->win, (*i)->getY() - a, (*i)->getX() - b, "o");
      wattroff(this->win, COLOR_PAIR(2));
      i++;
    }
  wrefresh(this->win);
}

void		Ncurses::keyPress() const
{
  int		c;
  int		x;
  int		y;
  MEVENT       	event;

  c = wgetch(this->win);
  if (c == 260 && this->game()->getMenu() == 0)
    self->game()->getMap()->getSnake()->changeDirectionLeft();
  else if (c == 261 && this->game()->getMenu() == 0)
    self->game()->getMap()->getSnake()->changeDirectionRight();
  else if (c == 27)
    {
      wclear(win);
      this->game()->setEnd(0);
    }
  else if (c == KEY_MOUSE && this->game()->getMenu() == 1)
    {
      if (getmouse(&event) == OK)
	{
	  x = event.x;
	  y = event.y;
	  if (y >= 29 && y <= 31 && x >= 9 && x <= 18)
	    {
	      wclear(win);
	      this->game()->setEnd(0);
	    }
	  else if (y >= 9 && y <= 11 && x >= 9 && x <= 28)
	    this->game()->launchGame();
	  else if (y >= 19 && y <= 21 && x >= 9 && x <= 28)
	    this->game()->launchHardGame();
	}
    }
  else if (c == KEY_MOUSE && this->game()->getMenu() == 0
	   && this->game()->getMap()->isAlive() == 0)
    {
      if (getmouse(&event) == OK)
	{
	  this->game()->launchMenu();
	}
    }
}

void		Ncurses::printDied() const
{
  std::string	score;
  std::ostringstream ss;

  wclear(this->win);
  wattron(this->win, COLOR_PAIR(2));
  mvwprintw(this->win, 19, 10, "           ");
  mvwprintw(this->win, 20, 10, " Game over ");
  mvwprintw(this->win, 21, 10, "           ");
  ss << " Score : ";
  ss << this->game()->getScore();
  ss << "     ";
  score = ss.str();
  mvwprintw(this->win, 29, 10, "              ");
  mvwprintw(this->win, 30, 10, score.c_str());
  mvwprintw(this->win, 31, 10, "              ");
  wattroff(this->win, COLOR_PAIR(2));
  wrefresh(this->win);
}

void		Ncurses::refresh()
{
  if (this->game()->getMenu() == 0 && this->game()->getMap()->isAlive() == 1)
    {
      this->w = this->game()->getMap()->getWidth();
      this->h = this->game()->getMap()->getHeight();
      wclear(win);
      createPlan();
      createSnake();
      putFruit();
      printScore();
    }
  else if (this->game()->getMenu() == 0 && this->game()->getMap()->isAlive() == 0)
    {
      this->printDied();
    }
  else if(this->game()->getMenu() == 1)
    {
      this->printMenu();
    }
  keyPress();
}

Ncurses::~Ncurses()
{
  wclear(this->win);
  delwin(this->win);
  endwin();
}
