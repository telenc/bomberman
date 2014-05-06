//
// Thread.hpp for Thread in /home/martre_s/cpp_bomberman
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Tue May  6 15:00:34 2014 Steven Martreux
// Last update Tue May  6 15:05:47 2014 Steven Martreux
//

#ifndef		_THREAD_HPP_
#define		_THREAD_HPP_

#include	"myException.hpp"
#include	<pthread.h>
#include	<iostream>

class		Thread
{
public:
  Thread(void *(*fct)(void *), void *, const std::string &);
  ~Thread();
private:
  pthread_t	_thread_ing;
}

#endif		/* _THREAD_HPP_ */
