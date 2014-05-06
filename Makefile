##
## Makefile for Makefile in /home/martre_s/cpp_bomberman
## 
## Made by Steven Martreux
## Login   <martre_s@epitech.net>
## 
## Started on  Tue May  6 17:28:55 2014 Steven Martreux
## Last update Tue May  6 17:31:22 2014 Steven Martreux
##

GCC=		g++

RM=		rm -rf

CPPFLAGS=	-Wall $(INCLUDES) -lpthread -pthread

INCLUDES=	-Iincludes/

SRC=		

OBJ=		$(SRC:.cpp=.o)

NAME=		bomberman

all:		$(NAME)

$(NAME):	$(OBJ)
	$(GCC) $(CPPFLAGS) -o $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all