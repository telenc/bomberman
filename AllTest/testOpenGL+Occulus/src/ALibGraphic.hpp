//
// ALibGraphic.hpp for libGRaphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:13:37 2014 telenc_r
// Last update Fri Apr  4 16:01:23 2014 dedicker remi
//

#ifndef	_ALIBGRAPHIC
#define	_ALIBGRAPHIC

//#include	"Game.hpp"

class Game;
class ALibGraphic
{
public:
  ALibGraphic(Game *);
  virtual ~ALibGraphic() {};
  virtual void	refresh() = 0;
  Game *game() const;
protected:
  Game *_game;
};

#endif
