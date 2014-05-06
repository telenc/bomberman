//
// myException.cpp for myException in /home/martre_s/cpp_bomberman/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Tue May  6 15:11:40 2014 Steven Martreux
// Last update Tue May  6 15:15:03 2014 Steven Martreux
//

#include	<iostream>
#include	<string>
#include	<exception>
#include	"myException.hpp"

myException::myException(std::string const & str) throw(): _str(str)
{

}

myException::~myException() throw()
{
}

const char *	myException::what() const throw()
{
  return (this->_str.c_str());
}
