/*
// ModelList.cpp for modellist in /home/remi/cpp_bomberman
//
// Made by Remi telenczak
// Login   <remi@epitech.net>
//
// Started on  Tue May 13 06:17:30 2014 Remi telenczak

*/

#include	"ModelList.hpp"

ModelList::ModelList()
{

}

void		ModelList::loadModel()
{
  gdl::Model	*mod;

  mod = this->createModel("./assets/marvin.fbx");
  this->list.push_back(std::make_pair("marvin", mod));
  mod = this->createModel("./assets/cubeWallFer.fbx");
  this->list.push_back(std::make_pair("cube6", mod));
  mod = this->createModel("./assets/bonus_bomb_up.FBX");
  this->list.push_back(std::make_pair("bombBonus", mod));
  mod = this->createModel("./assets/bonus_fire_down.FBX");
  this->list.push_back(std::make_pair("bombDownBonus", mod));
  mod = this->createModel("./assets/bonus_fire_up.FBX");
  this->list.push_back(std::make_pair("poBonus", mod));
  mod = this->createModel("./assets/zombieFloor2.fbx");
  this->list.push_back(std::make_pair("zombieFloor", mod));
  mod = this->createModel("./assets/cubeWall.fbx");
  this->list.push_back(std::make_pair("cubeDest2", mod));
  mod = this->createModel("./assets/cubeWall2.fbx");
  this->list.push_back(std::make_pair("cubeDest1", mod));
  mod = this->createModel("./assets/bombe5.fbx");
  this->list.push_back(std::make_pair("defaultBomb", mod));
  mod = this->createModel("./assets/box.fbx");
  this->list.push_back(std::make_pair("skybox1", mod));
  mod = this->createModel("./assets/box2.fbx");
  this->list.push_back(std::make_pair("skybox2", mod));
  mod = this->createModel("./assets/box3.fbx");
  this->list.push_back(std::make_pair("skybox3", mod));
  mod = this->createModel("./assets/box4.fbx");
  this->list.push_back(std::make_pair("skybox4", mod));
  mod = this->createModel("./assets/box5.fbx");
  this->list.push_back(std::make_pair("skybox5", mod));
  mod = this->createModel("./assets/box6.fbx");
  this->list.push_back(std::make_pair("skybox6", mod));
  mod = this->createModel("./assets/fire_box.FBX");
  this->list.push_back(std::make_pair("fire", mod));
  mod = this->createModel("./assets/mytest.fbx");
  this->list.push_back(std::make_pair("box", mod));
  mod = this->createModel("./assets/box_menu.fbx");
  this->list.push_back(std::make_pair("box_menu", mod));
  mod = this->createModel("./assets/menu.fbx");
  this->list.push_back(std::make_pair("menu", mod));
  mod = this->createModel("./assets/cubeFloor.fbx");
  this->list.push_back(std::make_pair("sol", mod));
  mod = this->createModel("./assets/cubeTelen0123.fbx");
  this->list.push_back(std::make_pair("menu1", mod));
  mod = this->createModel("./assets/cubeTelen3456.fbx");
  this->list.push_back(std::make_pair("menu2", mod));
  mod = this->createModel("./assets/cubeTelen6789.fbx");
  this->list.push_back(std::make_pair("menu3", mod));
  mod = this->createModel("./assets/cubeTelen90.fbx");
  this->list.push_back(std::make_pair("menu4", mod));
  mod = this->createModel("./assets/menuSettings.fbx");
  this->list.push_back(std::make_pair("box_setting", mod));
  mod = this->createModel("./assets/menuPlay.fbx");
  this->list.push_back(std::make_pair("box_play", mod));
  mod = this->createModel("./assets/menuCredit.fbx");
  this->list.push_back(std::make_pair("box_credits", mod));
  mod = this->createModel("./assets/menuSave1234.fbx");
  this->list.push_back(std::make_pair("box_sauv", mod));
  mod = this->createModel("./assets/menuSaveVide.fbx");
  this->list.push_back(std::make_pair("box_vide", mod));
  mod = this->createModel("./assets/menuIngame.fbx");
  this->list.push_back(std::make_pair("box_menuig", mod));
  this->listChemin.push_back(std::make_pair("marvin", "./assets/marvin.fbx"));
  this->listChemin.push_back(std::make_pair("cube6", "./assets/cubeWallFer.fbx"));
  this->listChemin.push_back(std::make_pair("bombBonus", "./assets/bonus_bomb_up.FBX"));
  this->listChemin.push_back(std::make_pair("bombDownBonus", "./assets/bonus_bomb_down.FBX"));
  this->listChemin.push_back(std::make_pair("poBonus", "./assets/bonus_fire_up.FBX"));
  this->listChemin.push_back(std::make_pair("cubeDest2", "./assets/cubeWall2.fbx"));
  this->listChemin.push_back(std::make_pair("cubeDest1", "./assets/cubeWall3.fbx"));
  this->listChemin.push_back(std::make_pair("defaultBomb", "./assets/bombe5.fbx"));
  this->listChemin.push_back(std::make_pair("skybox", "./assets/box.fbx"));
  this->listChemin.push_back(std::make_pair("fire", "./assets/fire_box.FBX"));
  this->listChemin.push_back(std::make_pair("box", "./assets/mytest.fbx"));
  this->listChemin.push_back(std::make_pair("box_menu", "./assets/box_menu.fbx"));
  this->listChemin.push_back(std::make_pair("menu", "./assets/menu.fbx"));
  this->listChemin.push_back(std::make_pair("sol", "./assets/cubeWallWood.fbx"));
  this->listChemin.push_back(std::make_pair("menu1", "./assets/cubeTelen0123.fbx"));
  this->listChemin.push_back(std::make_pair("menu2", "./assets/cubeTelen3456.fbx"));
  this->listChemin.push_back(std::make_pair("menu3", "./assets/cubeTelen6789.fbx"));
  this->listChemin.push_back(std::make_pair("menu4", "./assets/cubeTelen90.fbx"));
}

gdl::Model	*ModelList::createModel(const std::string path)
{
  gdl::Model	*result;

  result = new gdl::Model();
  std::cout << path << std::endl;
  if (result->load(path.c_str()))
    result->setCurrentAnim(0);
  else
    {
      std::cout << "Erre" << path << std::endl;
      exit(0);
    }
return (result);
}


gdl::Model	*ModelList::getModel(const std::string name)
{
  std::vector<std::pair<std::string, gdl::Model *> >::iterator it;

  it = this->list.begin();
  while (it != this->list.end())
    {
      if (it->first == name)
	return it->second;
      it++;
    }
  return (NULL);
}

gdl::Model	*ModelList::getModelCopy(const std::string name)
{
  std::vector<std::pair<std::string, std::string > >::iterator it;

  it = this->listChemin.begin();
  while (it != this->listChemin.end())
    {
      if (it->first == name)
	return (this->createModel(it->second));
      it++;
    }
  return (NULL);
}
