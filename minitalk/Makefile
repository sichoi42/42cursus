# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/12 20:21:15 by sichoi            #+#    #+#              #
#    Updated: 2021/08/13 16:01:27 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server
NAME2 = client
NAME_b = server_b
NAME2_b = client_b

CC = gcc
CFLAGS = -Wall -Wextra -Werror
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FUNC = ./servers/server\
		./servers/utils\
		./servers/ft_itoa\

FUNC2 = ./clients/client\
		./clients/utils

FUNC_b = ./servers_bonus/server_bonus\
		./servers_bonus/utils_bonus\
		./servers_bonus/ft_itoa_bonus\

FUNC2_b = ./clients_bonus/client_bonus\
		./clients_bonus/utils_bonus

SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))
SRC2 = $(addsuffix .c, $(FUNC2))
OBJ2 = $(addsuffix .o, $(FUNC2))

SRC_b = $(addsuffix .c, $(FUNC_b))
OBJ_b = $(addsuffix .o, $(FUNC_b))
SRC2_b = $(addsuffix .c, $(FUNC2_b))
OBJ2_b = $(addsuffix .o, $(FUNC2_b))

.c.o : $(SRC) $(SRC2) $(SRC_b) $(SRC2_b)
	@$(CC) $(CFLAGS) -c -o $@ $^
	@echo "$(GREEN)object files were created!$(RESET)"

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(NAME): $(GREEN)$(NAME) was created!$(RESET)"

$(NAME2) : $(OBJ2)
	@$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)
	@echo "$(NAME2): $(GREEN)$(NAME2) was created!$(RESET)"

$(NAME_b) : $(OBJ_b)
	@$(CC) $(CFLAGS) $(OBJ_b) -o $(NAME_b)
	@echo "$(NAME_b): $(GREEN)$(NAME_b) was created!$(RESET)"

$(NAME2_b) : $(OBJ2_b)
	@$(CC) $(CFLAGS) $(OBJ2_b) -o $(NAME2_b)
	@echo "$(NAME2_b): $(GREEN)$(NAME2_b) was created!$(RESET)"

all : $(NAME) $(NAME2)

norm :
	@Norminette clients/*.c servers/*.c clients_bonus/*.c servers_bonus/*.c *.h

bonus : $(NAME_b) $(NAME2_b)

clean :
	@rm -f $(OBJ) $(OBJ2) $(OBJ_b) $(OBJ2_b)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"
	@echo "$(NAME2): $(RED)object files were deleted$(RESET)"
	@echo "$(NAME_b): $(RED)object files were deleted$(RESET)"
	@echo "$(NAME2_b): $(RED)object files were deleted$(RESET)"

fclean : clean
	@rm -f $(NAME) $(NAME2) $(NAME_b) $(NAME2_b)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@echo "$(NAME2): $(RED)$(NAME2) was deleted$(RESET)"
	@echo "$(NAME_b): $(RED)$(NAME_b) was deleted$(RESET)"
	@echo "$(NAME2_b): $(RED)$(NAME2_b) was deleted$(RESET)"

re : fclean all bonus
