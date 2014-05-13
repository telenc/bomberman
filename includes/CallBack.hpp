//
// CallBack.hpp for CallBack in /home/remi/testBomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Wed May  7 07:55:58 2014 Remi telenczak
// Last update Wed May  7 08:15:56 2014 Remi telenczak
//

#ifndef		_CALLBACK
# define	_CALLBACK

# include	"ICallBack.hpp"
# include	<unistd.h>

template<class T>
class CallBack : public ICallBack
{
private:
  T* m_object;
  void (T::*m_methode)(void*);

public:
  CallBack(T* object, void (T::*methode)(void*))  : m_object(object), m_methode(methode)
  {};
  void call(void *m_util)
  {
    (this->m_object->*this->m_methode)(m_util);
  }
};

#endif
