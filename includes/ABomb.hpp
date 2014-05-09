//
// ABomb.hpp for ABomb in /home/martre_s/cpp_bomberman/includes
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Wed May  7 16:03:12 2014 Steven Martreux
// Last update Wed May  7 16:18:34 2014 Steven Martreux
//

#ifndef		_ABOMB_HPP_
# define	_ABOMB_HPP_

class		ABomb : public AObjPhysique
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
