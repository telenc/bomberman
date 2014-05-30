//
// ALife.hpp for ALife in /home/remi/cpp_bomberman/includes
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 08:24:19 2014 Remi telenczak
// Last update Fri May 30 15:06:44 2014 Steven Martreux
//

#ifndef		_ALIFE
# define	_ALIFE

class AObjectLife
{
public:
  AObjectLife(int);
  virtual ~AObjectLife();
  void	decLife();
  void	incLife();
  int	getLife() const;
  virtual void	setLife(int) = 0;
protected:
  int	_life;
};

#endif
