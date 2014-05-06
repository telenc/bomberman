//
// myException.hpp<2> for nibbler in /home/martre_s/Epitech/Cpp/cpp_abstractvm/src
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Mon Mar 31 18:45:37 2014 Steven Martreux
// Last update Mon Mar 31 19:05:30 2014 Steven Martreux
//

#ifndef		_MY_EXECPTION_HPP_
# define	_MY_EXECPTION_HPP_

# include	<string>
# include	<exception>

class		myException : public std::exception
{
public:

  myException(std::string const & str) throw();
  virtual	~myException() throw();
  virtual const char *what() const throw();

private:
  std::string _str;
};

#endif		/* _MY_EXECPTION_HPP_ */

