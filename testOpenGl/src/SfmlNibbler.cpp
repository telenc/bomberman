//
// SfmlNibbler.cpp for SfmlNibbler.cpp in /home/dedick_r/Tek2/c++/cpp_nibbler/src
// 
// Made by dedicker remi
// Login   <dedick_r@epitech.net>
// 
// Started on  Tue Apr  1 11:26:33 2014 dedicker remi
// Last update Sun Apr  6 22:26:43 2014 dedicker remi
//

#include	<sstream>
#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>
#include	<list>
#include	"SfmlNibbler.hpp"
#include	"myException.hpp"
#include	"Game.hpp"
#include	"Snake.hpp"

ALibGraphic	*self;

extern "C" ALibGraphic *constructor_graphic(Game *game)
{
  self = new SfmlNibbler(game);
  return self;
}

void		SfmlNibbler::KeyPress()
{
  sf::Event	event;

  while (_window.GetEvent(event))
    {
      if ((event.Type == sf::Event::KeyPressed) && \
	  (event.Key.Code == sf::Key::Right))
	self->game()->getMap()->getSnake()->changeDirectionRight();
      else if ((event.Type == sf::Event::KeyPressed) && \
	       (event.Key.Code == sf::Key::Left))
	self->game()->getMap()->getSnake()->changeDirectionLeft();
      else if ((event.Type == sf::Event::KeyPressed) && \
	       (event.Key.Code == sf::Key::Escape))
	this->game()->setEnd(0);
    }
}

void		SfmlNibbler::displayImage(sf::Sprite &sprite,\
					  const sf::Image &image,\
					  int pos_x, int pos_y)
{
  sprite.SetImage(image);
  sprite.SetPosition(sf::Vector2f(pos_x, pos_y));
  _window.Draw(sprite);
}

void		SfmlNibbler::displayText(const std::string &string,\
					 int pos_x, int pos_y)
{
  _text.SetText(string);
  _text.SetPosition(pos_x, pos_y);
  _window.Draw(_text);
}

void		SfmlNibbler::displaySprite()
{
  _window.Clear(sf::Color(100, 150, 255));
  displayImage(_spritemenu, _hard, 100, 250);
  displayImage(_spritemenu, _exit, 100, 450);
  displayImage(_spritemenu, _easy, 120, 100);
  displayImage(_sprite, _apple, 90, 600);
  displayText("Normal", 50 , 630);
  displayImage(_sprite, _rm, 385, 600);
  displayText("rm", 375 , 630);
  displayImage(_sprite, _speed, 690, 600);
  displayText("Speedhack", 625 , 630);
  displayImage(_sprite, _slow, 920, 600);
  displayText("Normal", 890 , 630);
  displayImage(_sprite, _hangover, 260, 700);
  displayText("Hangover", 210 , 730);
  displayImage(_sprite, _giveme, 530, 700);
  displayText("Give me more", 450 , 730);
  displayImage(_sprite, _random, 820, 700);
  displayText("Random", 780 , 730);
}

void		SfmlNibbler::KeyPressMenu()
{
  sf::Event	event;
  int		x;
  int		y;

  while (_window.GetEvent(event))
    {
      if ((event.Type == sf::Event::KeyPressed) && \
	  (event.Key.Code == sf::Key::Escape))
	this->game()->setEnd(0);
      if ((event.Type == sf::Event::MouseButtonPressed) && \
	  (event.MouseButton.Button == sf::Mouse::Left))
	{
	  x = event.MouseButton.X;
	  y = event.MouseButton.Y;
	  if (x >= 130 && x <= 410 && y >= 120 && y <= 190)
	    {
	      this->game()->launchGame();
	      launchgame();
	    }
	  if (x >= 110 && x <= 490 && y >= 260 && y <= 340)
	    {
	      this->game()->launchHardGame();
	      launchgame();
	    }
	  if (x >= 110 && x <= 500 && y >= 460 && y <= 530)
	    this->game()->setEnd(0);
	}
    }
}

void		SfmlNibbler::displayMenu()
{
  int		x;
  sf::Sprite	sprite;
  std::ostringstream ss;
  std::list<int> score;
  std::list<int>::iterator it;
  std::string	string;

  displaySprite();
  x = 100;
  score = this->game()->getScores();
  it = score.begin();
  displayText("HighScore", 700 , 50);
  while (it != score.end())
    {
      ss << (*it);
      string = ss.str();
      ss.str("");
      displayText(string, 750, x);
      x += 50;
      it++;
    }
  _window.Display();
  KeyPressMenu();
 }

void		SfmlNibbler::setView()
{
  std::list<Tile *>		vect;
  std::list<Tile *>::iterator	i;
  int	x;
  int	y;

  vect = this->game()->getMap()->getSnake()->getSnake();
  i = vect.begin();
  x = (*i)->getX() * 16;
  y = (*i)->getY() * 16;
  if (x - 500 < 0)
    x = 500;
  if (y - 500 < 0)
    y = 500;
  if (y + 500 > _y)
    y = _y - 500;
  if (x + 500 > _x)
    x = _x - 500;
  _text.SetPosition(x + 350, y - 450);
  _view.SetCenter(x, y);
  _window.SetView(_view);
}

void		SfmlNibbler::displaySnake()
{

  std::list<Tile *>		vect;
  std::list<Tile *>::iterator	i;

  vect = this->game()->getMap()->getSnake()->getSnake();
  i = vect.begin();
  this->_sprite.SetImage(_head);
  this->_sprite.SetPosition(sf::Vector2f((*i)->getX() * 16, (*i)->getY() * 16));
  this->_window.Draw(this->_sprite);
  this->_sprite.SetImage(_snake);
  while (++i != vect.end())
    {
      this->_sprite.SetPosition(sf::Vector2f((*i)->getX() * 16, \
					     (*i)->getY() * 16));
      this->_window.Draw(_sprite);
    }
}

void		SfmlNibbler::displayWall()
{
  int		x;
  int		y;
  int		x_map;
  int		y_map;
  Tile		*tile;

  x = 0;
  y = 0;
  this->_sprite.SetImage(_wall);
  x_map = this->game()->getMap()->getWidth();
  y_map = this->game()->getMap()->getHeight();
  while (x < x_map)
    {
      y = 0;
      while (y < y_map)
	{
	  tile = this->game()->getMap()->getTile(x , y);
	  if (tile->getType() == 'w')
	    {
	      this->_sprite.SetPosition(sf::Vector2f(x * 16, y * 16));
	      this->_window.Draw(_sprite);
	    }
	  y++;
	}
      x++;
    }
}

void		SfmlNibbler::createFruitColor()
{
  this->_colorFruit.insert(std::pair<char, sf::Image >('a', this->_apple));
  this->_colorFruit.insert(std::pair<char, sf::Image >('r', this->_rm));
  this->_colorFruit.insert(std::pair<char, sf::Image >('s', this->_speed));
  this->_colorFruit.insert(std::pair<char, sf::Image >('d', this->_slow));
  this->_colorFruit.insert(std::pair<char, sf::Image >('t', this->_hangover));
  this->_colorFruit.insert(std::pair<char, sf::Image >('m', this->_giveme));
  this->_colorFruit.insert(std::pair<char, sf::Image >('p', this->_random));
}

void		SfmlNibbler::putFruit()
{
  std::list<Fruit *> fruit;
  std::list<Fruit *>::iterator i;
  std::map<char, sf::Image>::iterator j;

  fruit = this->game()->getMap()->getFruit();
  i = fruit.begin();
  while (i != fruit.end())
    {
      j = this->_colorFruit.find((*i)->getType());
      if (j != _colorFruit.end())
        {
	  this->_sprite.SetImage((*j).second);
	  this->_sprite.SetPosition(sf::Vector2f((*i)->getX() * 16, \
						 (*i)->getY() * 16));
	  this->_window.Draw(_sprite);
	}
      else
	{
	  this->_sprite.SetImage(_apple);
	  this->_sprite.SetPosition(sf::Vector2f((*i)->getX() * 16, \
						 (*i)->getY() * 16));
	  this->_window.Draw(_sprite);
	}
      i++;
    }
}

void		SfmlNibbler::setText()
{
  int		x;
  std::stringstream ss;
  std::string	str;

  x = this->game()->getScore();

  ss << "Score : " << x;
  str =  ss.str();
  _text.SetText(str);
  _window.Draw(_text);
}

SfmlNibbler::~SfmlNibbler()
{

}

void		SfmlNibbler::displayEnd()
{
  sf::Sprite	sprite;
  sf::Event	event;
  std::stringstream ss;
  std::string	str;

  _window.Clear();
  ss << "Tu as perdu ! Ton score est de : " << \
    this->game()->getScore()<<" point(s)";
  str = ss.str();
  _window.SetView(_defaultview);
  _text.SetText(str);
  _text.SetPosition(100, 200);
  _window.Draw(_text);
  _window.Draw(sprite);
  _window.Display();  
  while (_window.GetEvent(event))
    {
      if ((event.Type == sf::Event::KeyPressed) && \
	  (event.Key.Code == sf::Key::Escape))
	this->game()->setEnd(0);
      if ((event.Type == sf::Event::MouseButtonPressed) \
	  && (event.MouseButton.Button == sf::Mouse::Left))
	this->game()->launchMenu();
    }
}

void		SfmlNibbler::refresh()
{
  if (this->game()->getMenu() == 1)
    displayMenu();
  else
    {
      if (this->game()->getMap()->isAlive())
	{
	  KeyPress();
	  _window.Clear(sf::Color::Black);
	  setView();
	  setText();
	  putFruit();
	  displayWall();
	  displaySnake();
	  _window.Display();
	}
      else
	this->displayEnd();
    }
}

void		SfmlNibbler::launchgame()
{
  _x = this->game()->getMap()->getWidth() * 16;
  _y = this->game()->getMap()->getHeight() * 16;
}

void		SfmlNibbler::setImage()
{
  if (!_wall.LoadFromFile("./ressources/Wall.png"))
    throw new myException("Lib SFML\nFail to load Wall.png");
  if (!_apple.LoadFromFile("./ressources/apple.png"))
    throw new myException("Lib SFML\nFail to load apple.png");
  if (!_head.LoadFromFile("./ressources/head_snake.png"))
    throw new myException("Lib SFML\nFail to load head snake sprite");
  if (!_snake.LoadFromFile("./ressources/snake.png"))
    throw new myException("Lib SFML\nFail to load snake sprite");
  if (!_easy.LoadFromFile("./ressources/facile.png"))
    throw new myException("Lib SFML\nFail to load menu easy sprite");
  if (!_hard.LoadFromFile("./ressources/difficile.png"))
    throw new myException("Lib SFML\nFail to load menu hard sprite");
  if (!_exit.LoadFromFile("./ressources/exit.png"))
    throw new myException("Lib SFML\nFail to load menu exit sprite");
  if (!_rm.LoadFromFile("./ressources/rm.png"))
    throw new myException("Lib SFML\nFail to load menu rm sprite");
  if (!_speed.LoadFromFile("./ressources/speedhack.png"))
    throw new myException("Lib SFML\nFail to load menu speedhack sprite");
  if (!_slow.LoadFromFile("./ressources/slow.png"))
    throw new myException("Lib SFML\nFail to load menu slow sprite");
  if (!_hangover.LoadFromFile("./ressources/hangover.png"))
    throw new myException("Lib SFML\nFail to load menu hangover sprite");
  if (!_giveme.LoadFromFile("./ressources/givememore.png"))
    throw new myException("Lib SFML\nFail to load menu givememore sprite");
  if (!_random.LoadFromFile("./ressources/random.png"))
    throw new myException("Lib SFML\nFail to load menu random sprite");
}

SfmlNibbler::SfmlNibbler(Game *game) : ALibGraphic(game)
{
  setImage();
  createFruitColor();
  _view.SetHalfSize(500, 500);
  _view.Zoom(1.0f);  
  this->_window.Create(sf::VideoMode(1024, 800, 64), \
		       "Nibbler - Telenc_r - Martre_s - Dedick_r");
  _defaultview = _window.GetDefaultView();
}
