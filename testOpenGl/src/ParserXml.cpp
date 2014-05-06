//
// ALibGraphic.cpp for libgraphic in /home/remi/Epitech/Teck2/rendu/nibler/cpp_nibbler/src
//
// Made by telenc_r
// Login   <remi@epitech.net>
//
// Started on  Sat Mar 15 09:15:09 2014 telenc_r
// Last update Mon Mar 17 08:16:14 2014 telenc_r
//

#include	<fstream>
#include	<iostream>
#include	<stdlib.h>
#include	"ParserXml.hpp"
#include	<algorithm>
ParserXml::ParserXml()
{

}

ParserXml::~ParserXml()
{

}

void	ParserXml::parseFile()
{
  std::fstream	stream;
  std::string	line;
  int		lineType;
  std::string	fileName;

  this->_scores.clear();
  fileName = "scores.xml";
  stream.open(fileName.c_str(), std::fstream::in);
  if (stream.is_open())
    {
      while (std::getline(stream, line))
	{
	  lineType = this->getLineType(line);
	  if (lineType != -1)
	    {
	      if (lineType == 10)
		this->foundScore(line);
	      this->_tabulations += 2;
	    }
	}
      stream.close();
      this->_tabulations = 0;
    }
  else
    std::cout << "Error open file scores.xml" << std::endl;
  this->_scores.sort();
  this->_scores.reverse();
}

std::list<int>	ParserXml::getScores() const
{
  return this->_scores;
}

void	ParserXml::addScore(int newScore)
{
  this->_scores.push_back(newScore);
  this->_scores.sort();
  this->_scores.reverse();
}

void	ParserXml::generateXml()
{
  std::list<int>::iterator	i;
  int				j;

  this->_newFile.open("scores.xml", std::fstream::out);
  this->_scores.sort();
  this->_scores.reverse();
  if (this->_newFile.is_open())
    {
      this->_newFile << "<scoreslist>" << std::endl;
      i = this->_scores.begin();
      j = 0;
      while (i != this->_scores.end() && j < 10)
	{
	  this->_newFile << "<score value=\"" << *i << "\" />" << std::endl;
	  i++;
	  j++;
	}
      this->_newFile << "</scoreslist>" << std::endl;
    }
}

void	ParserXml::foundScore(const std::string &line)
{
  size_t	pos;
  size_t	endStr;
  std::string	name;
  int res;

  if ((pos = line.find("value=\"")) == std::string::npos)
    return;
  endStr = line.find_last_of('"');
  if (endStr == pos + 6)
    return ;
  name = line.substr(pos + 7, endStr - (pos + 7));
  std::stringstream(name) >> res;
  this->_scores.push_back(res);
}

int	ParserXml::getLineType(const std::string &line)
{
  size_t	i = 0;
  bool		space = false;
  bool		isOpen = false;
  std::string	balise = "";

  while (i < line.length())
    {
      if (line.at(i) == '<')
	{
	  if (isOpen == true)
	    return -1;
	  isOpen = true;
	}
      else if (line.at(i) == '>')
	{
	  if (isOpen == false)
	    return -1;
	  isOpen = false;
	}
      else
	{
	  if (isOpen && line.at(i) == ' ')
	    space = true;
	  if (isOpen && space == false)
	    balise += line.at(i);
	}
      i++;
    }
  if (isOpen)
    return -1;
  if (balise == "score")
    return 10;
  return -1;
}


