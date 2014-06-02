//
// PoBonus.hpp for PoBonus in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Fri May 30 08:21:33 2014 Remi telenczak
//

#ifndef		_APOBONUS_HPP_
# define	_APOBONUS_HPP_

#include "ABonus.hpp"

class		PoBonus : public ABonus
{
public:
  PoBonus(Map *, ModelList *, EventManager *, gdl::Clock *);
  virtual bool update(gdl::Clock const &clock, gdl::Input &input);
  ~PoBonus();
};

#endif		/* _ABOMB_HPP_ */
