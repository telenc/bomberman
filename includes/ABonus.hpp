//
// ABonus.hpp for ABonus in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Thu Jun  5 18:07:44 2014 Steven Martreux
//

#ifndef		_ABONUS_HPP_
# define	_ABONUS_HPP_

#include "AObjectPhysic.hpp"

class		APlayer;
class		ABonus : public AObjectPhysic
{
public:
  ABonus(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input) = 0;
  bool	getDied(void) const;
  ~ABonus();
  void	fireTouch();
protected:
  bool	_died;
};

#endif		/* _ABOMB_HPP_ */
