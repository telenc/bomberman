//
// ALife.hpp for ALife in /home/remi/cpp_bomberman/includes
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 08:24:19 2014 Remi telenczak
// Last update Sun Jun 15 19:31:41 2014 Steven Martreux
//

#ifndef		_ALIFE
# define	_ALIFE

# include	"Clock.hh"
# include	"Input.hh"

class AObjectLife
{
public:
  AObjectLife(int);
  virtual	~AObjectLife();
  void		decLife();
  void		incLife();
  int		getLife() const;
  void		setLife(int);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input) = 0;
protected:
  int		_life;
};

#endif
