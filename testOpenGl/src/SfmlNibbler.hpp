//
// OpenGlNibbler.hpp for Opennibler in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:16:27 2014 telenc_r
// Last update Sun Apr  6 22:11:24 2014 dedicker remi
//

#ifndef	_OPENGL_NIBBLER
#define	_OPENGL_NIBBLER

#include	"ALibGraphic.hpp"
#include	<SFML/Graphics.hpp>
#include	<SFML/Window.hpp>

class SfmlNibbler : public ALibGraphic
{
public:
  SfmlNibbler(Game *);
  virtual ~SfmlNibbler();
  void		refresh();
private:
  void		displaySprite();
  void		launchgame();
  void		setView();
  void		setText();
  void		displayMenu();
  void		displayEnd();
  void		createFruitColor();
  void		displayImage(sf::Sprite &sprite, const sf::Image &image, \
			     int pos_x, int pos_y);
  void		displayText(const std::string &string, int pos_x, int pos_y);
  void		KeyPress();
  void		KeyPressMenu();
  void		displayWall();
  void		displaySnake();
  void		setImage();
  void		putFruit();
  Game				*_game;
  std::map<char, sf::Image>	_colorFruit;
  sf::Event			_event;
  sf::RenderWindow		_window;
  sf::Sprite			_sprite;
  sf::Sprite			_headsnake;
  sf::Sprite			_spritemenu;
  sf::Image			_wall;
  sf::Image			_apple;
  sf::Image			_rm;
  sf::Image			_speed;
  sf::Image			_slow;
  sf::Image			_hangover;
  sf::Image			_giveme;
  sf::Image			_random;
  sf::Image			_snake;
  sf::Image			_head;
  sf::Image			_easy;
  sf::Image			_hard;
  sf::Image			_exit;
  sf::View			_view;
  sf::View			_defaultview;
  sf::String			_text;
  int				_angle;
  int				_isview;
  int				_x;
  int				_y;
};

#endif
