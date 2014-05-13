//
// main.cpp for main in /home/martre_s/cpp_bomberman/test
// 
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
// 
// Started on  Wed May  7 17:33:58 2014 Steven Martreux
// Last update Wed May  7 18:30:12 2014 Steven Martreux
//

#include	<iostream>
#include	"tinyxml.h"
//#include	"tinystr.h"

int		main(int ac, char **av)
{
  TiXmlDocument XMLdoc(av[1]);
  bool loadOkay = XMLdoc.LoadFile();

  if (loadOkay)
    {
      std::cout << "Xml Loaded" << std::endl;
      TiXmlElement *bomberman;
      bomberman = XMLdoc.FirstChildElement("Bomber");
      if (bomberman)
	{
	  TiXmlElement *map_size;
	  map_size = bomberman->FirstChildElement("Map_Size");
	  if (map_size)
	    {
	      int width = atoi(map_size->Attribute("width"));
	      int height = atoi(map_size->Attribute("height"));
	      std::cout << "widht = " << width << " height = " << height << std::endl;
	      TiXmlElement *map;
	      map = bomberman->FirstChildElement("Map");
	      while (map)
		{

		  int x = atoi(map->Attribute("x"));
		  int x = atoi(map->Attribute("y"));
		  int x = atoi(map->Attribute("z"));
		  std::cout << "x = " << x << std::endl;
		  map = map->NextSiblingElement("Map");
		}
	    }
	}
    }
  else
    std::cout << "Bomber not find" << std::endl;
  return (0);
}
