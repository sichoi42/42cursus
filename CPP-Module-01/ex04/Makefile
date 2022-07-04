# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/21 18:35:07 by sichoi            #+#    #+#              #
#    Updated: 2022/07/04 17:17:51 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = copy

CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CHECK = \033[0;32m\xE2\x9C\x94\033[0m

FUNC = main\
		Replace\

DOT_REPLACE = *.replace

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
	@rm -f $(NAME) $(DOT_REPLACE)
	@echo "$(NAME): $(RED) $(NAME) was deleted $(RESET)"
	@echo "$(NAME): $(RED) $(DOT_REPLACE) was deleted $(RESET)"

re : fclean all
