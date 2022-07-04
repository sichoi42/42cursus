# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 18:35:07 by sichoi            #+#    #+#              #
#    Updated: 2022/07/03 21:28:05 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = war

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CHECK = \033[0;32m\xE2\x9C\x94\033[0m

FUNC = main\
		Weapon\
		HumanA\
		HumanB\

SRC = $(addsuffix .cpp, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))

%.o : %.cpp
	@echo "$(NAME): $(GREEN) compiling... $< $(CHECK) $(RESET)"
	@$(CC) $(CXXFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	@$(CC) $(CXXFLAGS) -o $(NAME) $(OBJ)
	@echo "$(NAME): $(GREEN) $(NAME) was created! $(CHECK) $(RESET)"

all : $(NAME)

clean :
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED) object files were deleted $(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED) $(NAME) was deleted $(RESET)"

re : fclean all
