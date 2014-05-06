//
// Thread.cpp for Thread in /home/martre_s/cpp_bomberman
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Tue May  6 15:00:47 2014 Steven Martreux
// Last update Tue May  6 15:06:02 2014 Steven Martreux
//

#include	"Thread.hpp"

Thread::Thread(void *(*fct)(void *), void *data, const std::string & type)
{
  if (pthread_create(&(this->_thread_ing), NULL, fct, data) != 0)
    throw new myException("Error create thread " + type);
}

Thread::~Thread()
{
  if (pthread_cancel(this->_thread_ing) != 0)
    throw new myException("Error close thread");
}
