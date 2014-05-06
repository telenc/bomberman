##
## Makefile for MakefileMalloc in /home/martre_s/PSU_2013_malloc
## 
## Made by Steven Martreux
## Login   <martre_s@epitech.net>
## 
## Started on  Wed Feb  5 15:09:33 2014 Steven Martreux
##

CC=		g++

RM=		rm -rf

INCLUDES=	-I includes/

SRC 		=	src/main.cpp 	\
			src/Game.cpp  	\
			src/Map.cpp 	\
			src/Snake.cpp \
			src/Tile.cpp	\
			src/ALibGraphic.cpp \
			src/myException.cpp \
			src/Fruit.cpp \
			src/ParserXml.cpp \
			src/CreateEvent.cpp \
			src/AEventNib.cpp \
			src/events/EventAddSnake.cpp \
			src/events/EventAddMoreSnake.cpp \
			src/events/EventRemoveSnake.cpp \
			src/events/EventSpeedSnake.cpp \
			src/events/EventDespeedSnake.cpp \
			src/events/EventDirectionSnake.cpp \
			src/events/EventScoreSnake.cpp \

SRC_OPENGL 	=	src/OpenGlNibbler.cpp \


SRC_NCURSES 	=	src/Ncurses.cpp \

SRC_SFML	=	src/SfmlNibbler.cpp \
			src/ALibGraphic.cpp \
			src/Game.cpp \
			src/Map.cpp \
			src/Tile.cpp \
			src/myException.cpp \
			src/Snake.cpp \

OBJ		=	$(SRC:.cpp=.o)

OBJ_OPENGL	=	$(SRC_OPENGL:.cpp=.o)

OBJ_NCURSES	=	$(SRC_NCURSES:.cpp=.o)

OBJ_SFML	=	$(SRC_SFML:.cpp=.o)

NAME		=	nibbler

NAME_OPENGL	=	lib/lib_nibbler_opengl.so

NAME_NCURSES	=	lib/lib_nibbler_ncurses.so

NAME_SFML	=	lib/lib_nibbler_sfml.so

all:	$(NAME)	$(NAME_OPENGL)

$(NAME) : $(OBJ)
	$(CC) -Wall -Werror -Wextra -O5 -o $(NAME) $(OBJ) -ldl -g -Wextra -Wall -Werror -export-dynamic

$(NAME_OPENGL):	$(OBJ_OPENGL)
		$(CC) -Wall -Werror -Wextra -O5 -o $(NAME_OPENGL) $(SRC_OPENGL) -shared -fPIC -lglut -lGL -lGLU

$(NAME_NCURSES):
		$(CC) -Wall -Werror -Wextra -o $(NAME_NCURSES) $(SRC_NCURSES) -shared -fPIC -lncurses -ldl

$(NAME_SFML):	$(OBJ_SFML)
		$(CC) -Wall -Werror -Wextra -o $(NAME_SFML) $(SRC_SFML) -shared -fPIC -lsfml-system -lsfml-window  -lsfml-graphics -lsfml-audio

clean:
	$(RM) src/*.o
	$(RM) *.o
	$(RM) *~
	$(RM) *#

fclean : clean
	$(RM) $(NAME_NCURSES)
	$(RM) $(NAME_OPENGL)
	$(RM) $(NAME_SFML)
	$(RM) $(NAME)

re: fclean all
