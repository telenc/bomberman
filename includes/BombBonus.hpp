//
// PoBonus.hpp for PoBonus in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Sun Jun 15 19:05:50 2014 Steven Martreux
//

#ifndef		_ABOMBBONUS_HPP_
# define	_ABOMBBONUS_HPP_

#include	"ABonus.hpp"

class		BombBonus : public ABonus
{
public:
  BombBonus(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  ~BombBonus();
};

#endif		/* _ABOMB_HPP_ */
