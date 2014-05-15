//
// ABloc.hpp for Block in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Thu May 15 09:15:05 2014 Remi telenczak
// Last update Thu May 15 09:16:14 2014 Remi telenczak
//

#ifndef		_ABLOCK_HPP
# define	_ABLOCK_HPP

# include	"AObjectPhysic.hpp"

class	ABloc : public
{
public:
  ABloc(Map *, ModelList *, EventManager *);
  ~ABloc();
}

#endif
