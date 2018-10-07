#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ollevche <ollevche@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/01 13:37:28 by ollevche          #+#    #+#              #
#    Updated: 2018/10/01 13:37:29 by ollevche         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= ft_retro

FLAGS	= -std=c++98 -Wall -Wextra -Werror -I./$(HDIR) -g #DEL

SRCDIR	= sources/

OBJDIR	= objects/

HDIR	= headers/

HDRS	= AGameEntity.hpp Boulder.hpp general.hpp Missile.hpp RetroGame.hpp \
			SpaceShip.hpp Star.hpp menu.hpp

PHDR	= $(addprefix $(HDIR), $(HDRS))

SRC		= AGameEntity.cpp general.cpp main.cpp RetroGame.cpp SpaceShip.cpp \
			Boulder.cpp Missile.cpp Star.cpp menu.cpp

OBJ		= $(addprefix $(OBJDIR), $(SRC:.cpp=.o))

all: $(NAME)

$(NAME): $(PHDR) $(OBJDIR) $(OBJ)
	clang++ -o $(NAME) $(OBJ) $(FLAGS) -lncurses

$(OBJDIR):
	mkdir $(OBJDIR)

$(OBJ): $(OBJDIR)%.o :  $(SRCDIR)%.cpp $(PHDR)
	clang++ -o $@ -c $< $(FLAGS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
