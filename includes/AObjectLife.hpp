//
// ALife.hpp for ALife in /home/remi/cpp_bomberman/includes
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 08:24:19 2014 Remi telenczak
// Last update Tue May 13 08:26:52 2014 Remi telenczak
//

#ifndef		_ALIFE
# define	_ALIFE

class AObjectLife
{
public:
  AObjectLife();
  void	decLife();
  void	incLife();
  int	getLife();
private:
  int	_life;
};

#endif
