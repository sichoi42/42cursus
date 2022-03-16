# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/28 18:44:46 by sichoi            #+#    #+#              #
#    Updated: 2022/01/13 12:07:55 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FUNC = ./srcs/main\
		./srcs/init\
		./srcs/utils\
		./srcs/action

INC = ./include/philo.h

SRCS = $(addsuffix .c, $(FUNC))
OBJS = $(addsuffix .o, $(FUNC))

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
	@echo "$(GREEN)object files were created!$(RESET)"
	@echo "$(GREEN)$(NAME) was created!$(RESET)"

all : $(NAME)

norm :
	norminette include/*.h srcs/*.c

clean :
	rm -f $(OBJS)
	@echo "$(RED)object files were deleted$(RESET)"

fclean : clean
	rm -f $(NAME)
	@echo "$(RED)$(NAME) was deleted$(RESET)"

re : fclean all
