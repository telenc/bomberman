//
// myException.cpp<2> for nibbler in /home/martre_s/Epitech/Cpp/cpp_abstractvm/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Mon Mar 31 18:43:21 2014 Steven Martreux
// Last update Mon Mar 31 19:07:35 2014 Steven Martreux
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
