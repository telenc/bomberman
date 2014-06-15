//
// PoBonus.hpp for PoBonus in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Sun Jun 15 19:33:15 2014 Steven Martreux
//

#ifndef		_ABOMBDOWNBONUS_HPP_
# define	_ABOMBDOWNBONUS_HPP_

#include	"ABonus.hpp"

class		BombDownBonus : public ABonus
{
public:
  BombDownBonus(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  ~BombDownBonus();
};

#endif		/* _ABOMB_HPP_ */
