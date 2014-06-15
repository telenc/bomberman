//
// LoadGame.cpp for LoadGame in /home/martre_s/cpp_bomberman/src
//
// Made by Steven Martreux
// Login   <martre_s@epitech.net>
//
// Started on  Mon May 12 13:48:39 2014 Steven Martreux
// Last update Sun Jun 15 21:48:17 2014 thomas mendez
//

#include	<cstring>
#include	<string.h>
#include	<tinyxml.h>
#include	"LoadGame.hpp"

LoadGame::LoadGame(const std::string & file, EventManager *event, ModelList *model, gdl::Clock *clock) : _file(file), _event(event), _model(model), _clock(clock)
{
  if (checkFile() == false)
    throw new myException("Save Fail dont change my Save !!");
  TiXmlDocument	doc(file);
  _loadOkay = doc.LoadFile();
  if (!_loadOkay)
    throw new myException("Load of file Error");
  _bomberman = doc.FirstChildElement("Bomberman");
  if (_bomberman == NULL)
    throw new myException("Balise <Bomberman> inexistant");
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("defaultwall", &LoadGame::CreateDefaultWall));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("destrucwall", &LoadGame::CreateDestrucWall));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("defaultbomb", &LoadGame::CreateDefaultBomb));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("bonuspo", &LoadGame::CreateBonusPo));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("bonusbomb", &LoadGame::CreateBonusBomb));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("fire", &LoadGame::CreateDefaultFire));
  _mapObject.insert(std::pair<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *)>("wallsol", &LoadGame::CreateSol));
  this->getMapSize();
  this->getPlayer();
  this->getIas();
  this->getObjMap();
}

bool	LoadGame::checkFile()
{
  std::string str = "md5sum " + _file + " > ." + _file + ".md5test";
  system(str.c_str());
  std::string namefile1 = "." + _file + ".md5test";
  std::string namefile2 = "." + _file + ".md5";
  std::fstream file1(namefile1.c_str());
  std::fstream file2(namefile2.c_str());
  std::ifstream fichier1(namefile1.c_str(), std::ios::in);
  std::ifstream fichier2(namefile2.c_str(), std::ios::in);

  if (fichier1 && fichier2)
    {
      std::string lignef1;
      std::string lignef2;
      while (std::getline( fichier1, lignef1) && std::getline( fichier2, lignef2))
	{
	  std::cout << "TEST" << std::endl;
	  if (strcmp(lignef1.c_str(),lignef2.c_str()) !=0)
	    {
	      std::cout << "NOT GOOD" << std::endl;
	      return false;
	    }
	}
      return true;
    }
  return false;
}

Map	*LoadGame::getMap() const
{
  return _mapGame;
}

bool	LoadGame::getLoad() const
{
  return _loadOkay;
}

AObjectPhysic	*LoadGame::CreateBonusPo(TiXmlElement *line)
{
  PoBonus	*obj;

  obj = new PoBonus(_mapGame, _model, _event, _clock);
  obj->setId(atoi(line->Attribute("id")));
  obj->set_x(atof(line->Attribute("x")));
  obj->set_y(atof(line->Attribute("y")));
  obj->set_z(atof(line->Attribute("z")));
  obj->setDied(atoi(line->Attribute("died")));
  _mapGame->setBonus((ABonus *)obj);
  return (AObjectPhysic *)obj;
}

std::vector<APlayer *>	 *LoadGame::getVectorPlayer(TiXmlElement *line)
{
  const char	       	*idPlayer;
  char			*id;
  std::vector<APlayer *> *playerTouched;

  idPlayer = line->Attribute("ID_PLAYER");
  id = strtok((char *)idPlayer, ",");
  playerTouched = new std::vector<APlayer *>;
  while (id != NULL)
    {
      playerTouched->push_back(GetPlayerBomb(atoi(id)));
      id = strtok(NULL, ",");
    }
  return playerTouched;
}

AObjectPhysic	*LoadGame::CreateDefaultFire(TiXmlElement *line)
{
  DefaultFire	*fire;

  fire = new DefaultFire(_mapGame, _model, _event, getVectorPlayer(line), _clock, atoi(line->Attribute("idbomb")));
  fire->setId(atoi(line->Attribute("id")));
  fire->set_x(atof(line->Attribute("x")));
  fire->set_y(atof(line->Attribute("y")));
  fire->set_z(atof(line->Attribute("z")));
  fire->setTime(atoi(line->Attribute("time")));
  fire->setDamage(atoi(line->Attribute("damage")));
  fire->setBombId(atoi(line->Attribute("idbomb")));
  _mapGame->setFire((AFire *)fire);
  return (AObjectPhysic *)fire;
}

AObjectPhysic	*LoadGame::CreateSol(TiXmlElement *line)
{
  SolWall      	*wall;

  wall = new SolWall(_mapGame, _model, _event, _clock);
  wall->setId(atoi(line->Attribute("id")));
  wall->set_x(atof(line->Attribute("x")));
  wall->set_y(atof(line->Attribute("y")));
  wall->set_z(atof(line->Attribute("z")));
  _mapGame->setSol((ABloc *)wall);
  return (AObjectPhysic *)wall;
}

AObjectPhysic	*LoadGame::CreateBonusBomb(TiXmlElement *line)
{
  BombBonus	*obj;

  obj = new BombBonus(_mapGame, _model, _event, _clock);
  obj->setId(atoi(line->Attribute("id")));
  obj->set_x(atof(line->Attribute("x")));
  obj->set_y(atof(line->Attribute("y")));
  obj->set_z(atof(line->Attribute("z")));
  obj->setDied(atoi(line->Attribute("died")));
  _mapGame->setBonus((ABonus *)obj);
  return (AObjectPhysic *)obj;
}

APlayer					*LoadGame::GetPlayerBomb(int id_player)
{
  std::vector<APlayer *>		play;
  std::vector<APlayer *>::iterator	it;

  play = _mapGame->getPlayers();
  it = play.begin();
  while (it != play.end())
    {
      if ((*it)->getId() == id_player)
	return (*it);
      it++;
    }
  throw new myException("Not find id_player. File not good");
  return NULL;
}

AObjectPhysic	*LoadGame::CreateDefaultBomb(TiXmlElement *line)
{
  DefaultBomb	*bomb;
  int		id_player;
  APlayer      	*player;

  id_player = atoi(line->Attribute("id_player"));
  player = this->GetPlayerBomb(id_player);
  bomb = new DefaultBomb(_mapGame, _model, _event, player, _clock);
  bomb->setId(atoi(line->Attribute("id")));
  bomb->set_x(atof(line->Attribute("x")));
  bomb->set_y(atof(line->Attribute("y")));
  bomb->set_z(atof(line->Attribute("z")));
  bomb->setPo(atoi(line->Attribute("po")));
  bomb->setDamage(atoi(line->Attribute("damage")));
  bomb->setTime(atoi(line->Attribute("time")));
  bomb->setPlayerColl(atoi(line->Attribute("playercoll")));
  bomb->setDied(atoi(line->Attribute("died")));
  _mapGame->setBomb((ABomb *)bomb);
  return (AObjectPhysic *)bomb;
}

AObjectPhysic	*LoadGame::CreateDefaultWall(TiXmlElement *line)
{
  DefaultWall	*wall;

  wall = new DefaultWall(_mapGame, _model, _event, _clock);
  wall->setId(atoi(line->Attribute("id")));
  wall->set_x(atof(line->Attribute("x")));
  wall->set_y(atof(line->Attribute("y")));
  wall->set_z(atof(line->Attribute("z")));
  _mapGame->setBloc((ABloc *)wall);
  return (AObjectPhysic *)wall;
}

AObjectPhysic	*LoadGame::CreateDestrucWall(TiXmlElement *line)
{
  DestrucWall	*wall;

  wall = new DestrucWall(_mapGame, _model, _event, _clock);
  wall->setId(atoi(line->Attribute("id")));
  wall->set_x(atof(line->Attribute("x")));
  wall->set_y(atof(line->Attribute("y")));
  wall->set_z(atof(line->Attribute("z")));
  wall->setLife(atoi(line->Attribute("life")));
  _mapGame->setBloc((ABloc *)wall);
  return (AObjectPhysic *)wall;
}

void	LoadGame::getObjMap()
{
  std::map<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *) >::iterator i;

  _map = _bomberman->FirstChildElement("Map");
  if (!_map)
    throw new myException("<BALISE> MAP non definie");
  while (_map)
    {
      i = _mapObject.find(_map->Attribute("object"));
      if (i != _mapObject.end())
	{
	  (this->*_mapObject[_map->Attribute("object")])(_map);
	}
      _map = _map->NextSiblingElement("Map");
    }
}

void	LoadGame::getMapSize()
{
  int	width;
  int	height;
  int	type;

  _map_size = _bomberman->FirstChildElement("Map_Size");
  if (_map_size)
    {
      if (!_map_size->Attribute("width") || !_map_size->Attribute("height"))
	throw new myException("<BALISE> Width Height");
      width = atoi(_map_size->Attribute("width"));
      height = atoi(_map_size->Attribute("height"));
      type = atoi(_map_size->Attribute("TypeGame"));
      if (type == 0)
	this->_mapGame = new Map(width, height, _event);
      else if (type == 1)
	this->_mapGame = new Map(width, height, _event, ZOMBIE);
    }
  else
    throw new myException("<Balise Map_Size not find");
}

void	 LoadGame::getPlayer()
{
  Player	*player;
  int		x;
  int		y;
  int		z;

  _player = _bomberman->FirstChildElement("Player");
  if (_player)
    {
      x = atoi(_player->Attribute("x"));
      y = atoi(_player->Attribute("y"));
      z = atoi(_player->Attribute("z"));
      player = new Player(x, y , z, _mapGame, _model, _event, _clock);
      player->setId(atoi(_player->Attribute("id")));
      player->setPo(atoi(_player->Attribute("po")));
      player->setLife(atoi(_player->Attribute("life")));
      player->set_rotx(atoi(_player->Attribute("rot_x")));
      player->set_roty(atoi(_player->Attribute("rot_y")));
      player->set_rotz(atoi(_player->Attribute("rot_z")));
      player->setNbrBomb(atoi(_player->Attribute("nbrMaxBomb")));
      player->setNbrMaxBomb(atoi(_player->Attribute("nbrCurrentBomb")));
      _mapGame->setPlayer(player);
    }
  else
    throw new myException("PLAYER BALISE NOT FIND SORRY");
}

IaBomber	*LoadGame::getIa(int x, int y, int z)
{
  IaBomber     	*ia;

  ia = new IaBomber(x, y , z, _mapGame, _model, _event, _clock);
  ia->setId(atoi(_ia->Attribute("id")));
  ia->setPo(atoi(_ia->Attribute("po")));
  ia->setLife(atoi(_ia->Attribute("life")));
  ia->set_rotx(atoi(_ia->Attribute("rot_x")));
  ia->set_roty(atoi(_ia->Attribute("rot_y")));
  ia->set_rotz(atoi(_ia->Attribute("rot_z")));
  ia->setNbrBomb(atoi(_ia->Attribute("nbrMaxBomb")));
  ia->setNbrMaxBomb(atoi(_ia->Attribute("nbrCurrentBomb")));
  return ia;
}

void	LoadGame::getIas()
{
  IaBomber	*ia;
  int	x;
  int	y;
  int	z;

  _ia = _bomberman->FirstChildElement("Ia");
  if(_ia)
    {
      while (_ia)
	{
	  x = atoi(_ia->Attribute("x"));
	  y = atoi(_ia->Attribute("y"));
	  z = atoi(_ia->Attribute("z"));
	  ia = getIa(x, y, z);
	  _mapGame->setIa(ia);
	  _ia = _ia->NextSiblingElement("Ia");
	}
      return;
    }
  throw new myException("PLAYER IA NOT FOUND");
}

LoadGame::~LoadGame()
{
  std::map<std::string, AObjectPhysic*(LoadGame::*)(TiXmlElement *) >::iterator it;

  for (it=_mapObject.begin(); it != _mapObject.end(); ++it)
    _mapObject.erase(it);
}
