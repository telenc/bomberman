##
## Makefile for Makefile in /home/martre_s/cpp_bomberman
## 
## Made by Steven Martreux
## Login   <martre_s@epitech.net>
## 
## Started on  Tue May  6 17:28:55 2014 Steven Martreux
##


SYSARCH       = i386
ifeq ($(shell uname -m),x86_64)
SYSARCH       = x86_64
endif


CXX           = g++
LINK          = g++
MAKE          = make
DELETEFILE    = rm -f
DEFINES       = -DQT_WEBKIT -DGL_GLEXT_PROTOTYPES


DEBUG         = 0
ifeq ($(DEBUG), 1)
	CXXFLAGS      = -pipe -DDEBUG -g $(DEFINES)
	LFLAGS        = -g -O3
	RELEASETYPE   = Debug
else
	CXXFLAGS      = -pipe -O2 $(DEFINES)
	LFLAGS        = -O3
	RELEASETYPE   = Release
endif


LIBOVRPATH    = LibOVR
COMMONSRCPATH = CommonSrc
3RDPARTYPATH  = ../3rdParty
INCPATH       = -I. -I.. -I$(COMMONSRCPATH) -I$(LIBOVRPATH)/Include -I$(LIBOVRPATH)/Src -I./includes/ -I./LibGdl/includes
OBJPATH       = bomberman
CXX_BUILD     = $(CXX) -c $(CXXFLAGS) $(INCPATH)
CXXFLAGS	= $(INCPATH) -Werror -Wextra -Wall

LIBS          = -L$(LIBOVRPATH)/Lib/Linux/$(RELEASETYPE)/$(SYSARCH)	\
		-L./LibGdl/libs/					\
		-lgdl_gl						\
		-lGL							\
		-lGLEW							\
		-ldl							\
		-lrt							\
		-lfbxsdk						\
		-lSDL2							\
		-ldl							\
		-lovr							\
		-ludev							\
		-lX11							\
		-lXinerama						\
		-lglut							\
		-lGLU							\
		-lfbxsdk						\
		-lrt							\
		-ltinyxml						\
		-Wl,-rpath,./LibGdl/libs/				\
		-lsfml-audio						\
		-lSDL							\
		-lvlc							\
		-lpthread						\

SRC		= src/main.cpp						\
		src/Occulus.cpp						\
		src/ModelList.cpp					\
		src/Game.cpp						\
		src/Graphics.cpp					\
		src/EventManager.cpp					\
		src/Menu.cpp						\
		src/AObjectPhysic.cpp					\
		src/APlayer.cpp						\
		src/ABomb.cpp						\
		src/AObjectLife.cpp					\
		src/Map.cpp						\
		src/Player.cpp						\
		src/LoadGame.cpp					\
		src/CameraBomber.cpp					\
		src/ABloc.cpp						\
		src/Bloc/DefaultWall.cpp				\
		src/Bloc/SolWall.cpp					\
		src/Bloc/DestrucWall.cpp				\
		src/Bloc/MenuWall.cpp					\
		src/Bloc/MenuBox.cpp					\
		src/Bloc/MenuBoxIG.cpp					\
		src/Bloc/PlayBox.cpp					\
		src/Bloc/SaveBox.cpp					\
		src/Bloc/CreditsBox.cpp					\
		src/Bloc/MenuBoxNumber.cpp				\
		src/Bloc/LoadBox.cpp					\
		src/Bloc/SettingBox.cpp					\
		src/Bloc/SettingBoxIG.cpp				\
		src/GenereMap.cpp					\
		src/Bomb/DefaultBomb.cpp				\
		src/Controller.cpp					\
		src/Skybox.cpp						\
		src/Sound.cpp						\
		src/AFire.cpp						\
		src/Fire/DefaultFire.cpp				\
		src/Loader.cpp						\
		src/myException.cpp					\
		src/ABonus.cpp						\
		src/Bonus/PoBonus.cpp					\
		src/Bonus/BombBonus.cpp					\
		src/Bonus/BombDownBonus.cpp				\
		src/SaveGame.cpp					\
		src/MenuNumber.cpp					\
		src/SaveMenu.cpp					\
		src/MainMenu.cpp					\
		src/MainMenuIG.cpp					\
		src/PlayMenu.cpp					\
		src/MenuIG.cpp						\
		src/SettingsMenu.cpp					\
		src/SettingsMenuIG.cpp					\
		src/LoadMenu.cpp					\
		src/CreditsMenu.cpp					\
		src/IaBomber.cpp					\
		src/Thread.cpp						\

OBJECTS       = $(SRC:.cpp=.o)

TARGET        = bomberman


all:   	 $(TARGET)

$(TARGET):	$(OBJECTS)
		$(LINK) $(LFLAGS) $(OBJECTS) $(LIBS) $(INCPATH) -o $(TARGET)

clean:
	$(DELETEFILE) $(OBJECTS)

fclean:	clean
	-$(DELETEFILE) $(TARGET)

re :	fclean all

