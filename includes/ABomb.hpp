//
// ABomb.hpp for ABomb in /home/martre_s/cpp_bomberman/includes
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Thu May 15 07:38:03 2014 Remi telenczak
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
    ABomb();
    ~ABomb();
    virtual void createDeflag() = 0;
    void update(void);
    void setPo(int po);
    int	getPo(void) const;
    void setDamage(int damage);
    int getDamage(void) const;
    void setTime(int time);
    int getTime(void) const;
};

#endif		/* _ABOMB_HPP_ */
