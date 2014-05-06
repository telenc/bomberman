//
// myException.hpp for myException.hpp in /home/martre_s/cpp_bomberman/includes
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Tue May  6 15:15:25 2014 Steven Martreux
// Last update Tue May  6 15:16:15 2014 Steven Martreux
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
