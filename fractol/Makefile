# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/22 21:36:57 by sichoi            #+#    #+#              #
#    Updated: 2021/07/23 20:32:33 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
libmlx = ./mlx/libmlx.a
CC = gcc
AR = ar
ARFLAGS = rcs
CFLAGS = -Wall -Wextra -Werror -O3
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

SRC= ./srcs/fractol.c\
		./srcs/draw.c\
		./srcs/fractol_func.c\
		./srcs/key_events.c\
		./srcs/mouse_events.c\
		./srcs/ft_tools.c\
		./srcs/palette.c\
		./srcs/ft_itoa.c

OBJ=$(SRC:.c=.o)

.c.o : $(SRC)
	@$(CC) -c -o $@ $^

$(NAME) : $(libmlx) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -Imlx -Lmlx -lmlx -framework OpenGL -framework AppKit
	@norminette ./include/*.h ./srcs/*.c
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"
$(libmlx):
	@echo "$(NAME): $(GREEN)Creating $(libmlx)..."
	@$(MAKE) -sC ./mlx/

all : $(NAME)

clean :
	@$(MAKE) -sC ./mlx/ clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	@rm -f $(libmlx)
	@echo "$(NAME): $(RED)$(libmlx) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re : fclean all
