//
// ABomb.hpp for ABomb in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Fri May 16 00:30:45 2014 Remi telenczak
//

#ifndef		_ABOMB_HPP_
# define	_ABOMB_HPP_

#include "AObjectPhysic.hpp"

class		ABomb : public AObjectPhysic
{
private:
    int _po;
    int _damage;
    int	_time;
public:
  ABomb(Map *, ModelList *, EventManager *);
  ~ABomb();
  virtual void createDeflag() = 0;
  virtual void update(gdl::Clock const &clock, gdl::Input &input) = 0;
  void setPo(int po);
  int	getPo(void) const;
  void setDamage(int damage);
  int getDamage(void) const;
  void setTime(int time);
  int getTime(void) const;
};

#endif		/* _ABOMB_HPP_ */
