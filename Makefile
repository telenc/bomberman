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
	LFLAGS        = -g
	RELEASETYPE   = Debug
else
	CXXFLAGS      = -pipe -O2 $(DEFINES)
	LFLAGS        = -O1
	RELEASETYPE   = Release
endif


LIBOVRPATH    = LibOVR
COMMONSRCPATH = CommonSrc
3RDPARTYPATH  = ../3rdParty
INCPATH       = -I. -I.. -I$(COMMONSRCPATH) -I$(LIBOVRPATH)/Include -I$(LIBOVRPATH)/Src -I./includes/ -I./LibGdl/includes
OBJPATH       = bomberman
CXX_BUILD     = $(CXX) -c $(CXXFLAGS) $(INCPATH) 
CXXFLAGS	= $(INCPATH)

LIBS          = -L$(LIBOVRPATH)/Lib/Linux/$(RELEASETYPE)/$(SYSARCH) \
		-L./LibGdl/libs/ \
		-lgdl_gl \
		-lGL \
		-lGLEW \
		-ldl \
		-lrt \
		-lfbxsdk \
		-lSDL2 \
		-ldl \
		-lovr \
		-ludev \
		-lpthread \
		-lGL \
		-lX11 \
		-lXinerama \
		-lglut \
		-lGLU \

SRC		= src/main.cpp \
		src/Occulus.cpp \
		src/ModelList.cpp

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

