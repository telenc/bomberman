//
// ICallBack.hpp for ICallBack in /home/remi/testBomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May  7 07:57:15 2014 Remi telenczak
// Last update Sun Jun 15 19:15:27 2014 Steven Martreux
//

#ifndef		_ICALLBACK
# define	_ICALLBACK

class	ICallBack
{
public:
  virtual void call(void *util) = 0;
  virtual ~ICallBack() {};
};

#endif		/* _ICALLBACK */
