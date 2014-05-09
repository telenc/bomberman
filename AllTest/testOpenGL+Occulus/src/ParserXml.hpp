//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#ifndef	PARSE_XML
#define	PARSE_XML

#include	<string>
#include	<iostream>
#include	<list>
#include	<fstream>
#include	<sstream>
class	ParserXml
{
public:
  ParserXml();
  virtual ~ParserXml();
  void	parseFile();
  std::list<int>	getScores() const;
  void			addScore(int);
  void			generateXml();
private:
  int	getLineType(std::string const &line);
  void	foundScore(std::string const &line);
  int	_tabulations;
  std::list<int>	_scores;
  std::fstream		_newFile;
};


#endif
