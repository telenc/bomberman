#############################################################################
#
# Filename    : Makefile
# Content     : Makefile for building linux OculusWorldDemo
# Created     : 2013
# Authors     : Simon Hallam and Peter Giokaris
# Instruction : The g++ compiler and stdndard lib packages need to be 
#               installed on the system.  Navigate in a shell to the 
#               directory where this Makefile is located and enter:
#
#               make                builds the release version for the 
#                                   current architechture
#               make clean          delete intermediate release object files 
#                                   and the executabe file
#               make DEBUG=1        builds the debug version for the current
#                                   architechture
#               make clean DEBUG=1  deletes intermediate debug object files 
#                                   and the executable file
#
# Output      : Relative to the directory this Makefile lives in, executable
#               files get built at the following locations depending upon the
#               architechture of the system you are running:
#
#               ./Release/OculusWorldDemo_i386_Release
#               ./Release/OculusWorldDemo_x86_64_Release
#               ./Release/OculusWorldDemo_i386_Debug
#               ./Release/OculusWorldDemo_x86_64_Debug
#
# Copyright   :   Copyright 2012 Oculus VR, Inc. All Rights reserved.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#############################################################################

####### Detect system architecture

SYSARCH       = i386
ifeq ($(shell uname -m),x86_64)
SYSARCH       = x86_64
endif

####### Compiler, tools and options

CXX           = g++
LINK          = g++
MAKE          = make
DELETEFILE    = rm -f
DEFINES       = -DQT_WEBKIT -DGL_GLEXT_PROTOTYPES

####### Detect debug or release

DEBUG         = 0
ifeq ($(DEBUG), 1)
	CXXFLAGS      = -pipe -DDEBUG -g $(DEFINES)
	LFLAGS        = 
	RELEASETYPE   = Debug
else
	CXXFLAGS      = -pipe -O2 $(DEFINES)
	LFLAGS        = -O1
	RELEASETYPE   = Release
endif

####### Paths

LIBOVRPATH    = LibOVR
COMMONSRCPATH = CommonSrc
3RDPARTYPATH  = ../3rdParty
INCPATH       = -I. -I.. -I$(COMMONSRCPATH) -I$(LIBOVRPATH)/Include -I$(LIBOVRPATH)/Src -I./includes/
OBJPATH       = a.out
CXX_BUILD     = $(CXX) -c $(CXXFLAGS) $(INCPATH) 

####### Files

LIBS          = -L$(LIBOVRPATH)/Lib/Linux/$(RELEASETYPE)/$(SYSARCH) \
		-L./libs/ \
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

OBJECTS       = main.cpp

TARGET        = a.out

####### Rules

all:    $(TARGET)

$(TARGET):  $(LIBOVRPATH)/Lib/Linux/$(RELEASETYPE)/$(SYSARCH)/libovr.a
	$(MAKE) -C $(LIBOVRPATH) DEBUG=$(DEBUG)

$(TARGET):  $(OBJECTS)
	$(LINK) $(LFLAGS) $(OBJECTS) $(LIBS) $(INCPATH)

$(OBJPATH)/OculusWorldDemo.o: OculusWorldDemo.cpp 
	$(CXX_BUILD)OculusWorldDemo.o OculusWorldDemo.cpp

main2.o: main2.cpp 
	$(CXX_BUILD)main2.o main2.cpp

$(OBJPATH)/Player.o: Player.cpp 
	$(CXX_BUILD)Player.o Player.cpp

$(OBJPATH)/Platform.o: ../../Samples/CommonSrc/Platform/Platform.cpp 
	$(CXX_BUILD)Platform.o ../../Samples/CommonSrc/Platform/Platform.cpp

$(OBJPATH)/Linux_Platform.o: ../../Samples/CommonSrc/Platform/Linux_Platform.cpp 
	$(CXX_BUILD)Linux_Platform.o ../../Samples/CommonSrc/Platform/Linux_Platform.cpp

$(OBJPATH)/Linux_Gamepad.o: ../../Samples/CommonSrc/Platform/Linux_Gamepad.cpp 
	$(CXX_BUILD)Linux_Gamepad.o ../../Samples/CommonSrc/Platform/Linux_Gamepad.cpp

$(OBJPATH)/Render_Device.o: ../../Samples/CommonSrc/Render/Render_Device.cpp $
	$(CXX_BUILD)Render_Device.o ../../Samples/CommonSrc/Render/Render_Device.cpp

$(OBJPATH)/Render_GL_Device.o: ../../Samples/CommonSrc/Render/Render_GL_Device.cpp 
	$(CXX_BUILD)Render_GL_Device.o ../../Samples/CommonSrc/Render/Render_GL_Device.cpp

$(OBJPATH)/Render_LoadTextureDDS.o: ../../Samples/CommonSrc/Render/Render_LoadTextureDDS.cpp 
	$(CXX_BUILD)Render_LoadTextureDDS.o ../../Samples/CommonSrc/Render/Render_LoadTextureDDS.cpp

$(OBJPATH)/Render_LoadTextureTGA.o: ../../Samples/CommonSrc/Render/Render_LoadTextureTGA.cpp 
	$(CXX_BUILD)Render_LoadTextureTGA.o ../../Samples/CommonSrc/Render/Render_LoadTextureTGA.cpp

$(OBJPATH)/Render_XmlSceneLoader.o: ../../Samples/CommonSrc/Render/Render_XmlSceneLoader.cpp 
	$(CXX_BUILD)Render_XmlSceneLoader.o ../../Samples/CommonSrc/Render/Render_XmlSceneLoader.cpp

clean:
	-$(DELETEFILE) $(TARGET)

