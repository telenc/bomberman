//
// PoBonus.hpp for PoBonus in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Sat Jun 14 15:41:07 2014 Remi telenczak
//

#ifndef		_ABOMBDOWNBONUS_HPP_
# define	_ABOMBDOWNBONUS_HPP_

#include "ABonus.hpp"

class		BombDownBonus : public ABonus
{
public:
  BombDownBonus(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  ~BombDownBonus();
};

#endif		/* _ABOMB_HPP_ */
