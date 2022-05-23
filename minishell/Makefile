# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/13 14:52:17 by sichoi            #+#    #+#              #
#    Updated: 2022/05/21 18:13:54 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIB_NAME = readline
LIB_DIR = $(shell brew --prefix readline)/lib/
LIB_INC = $(shell brew --prefix readline)/include/
INC = minishell.h

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CHECK = \033[0;32m\xE2\x9C\x94\033[0m

FUNC = ./tokenize/print_token_info\
		./tokenize/token_utils\
		./tokenize/tokenize\
		./tokenize/tokenize_dollar_in_word\
		./tokenize/tokenize_one_elem\
		./tokenize/tokenize_quote_in_word\
		./tokenize/tokenize_redirect\
		./tokenize/tokenize_word\
		./parsing/parse_utils\
		./parsing/parsing\
		./parsing/syntax_analysis\
		./term/cursor\
		./term/termios\
		./signal/signal\
		./runtime/exit\
		./runtime/init\
		./runtime/loop\
		./base/ft_atoi\
		./base/ft_itoa\
		./base/ft_max\
		./base/ft_realloc\
		./base/ft_strcat\
		./base/ft_strcmp\
		./base/ft_strcpy\
		./base/ft_strlen_c\
		./base/ft_tolower\
		./base/is_digit\
		./base/malloc_array\
		./base/print_error\
		./base/dup_check\
		./base/utils\
		./builtin/builtin\
		./builtin/pwd_exit_env\
		./builtin/unset_export\
		./oper_path/exe_make_oper\
		./oper_path/find_path_etc\
		./env/input_env\
		./env/insert\
		./env/print\
		./env/search_get_delete\
		./env/set_env\
		./free/free\
		./pipe/make_init_close\
		main\
		./redirect/redirect

SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))

%.o : %.c
	@echo "$(NAME)$$ $(GREEN) compiling... $< $(CHECK) $(RESET)"
	@$(CC) $(CFLAGS) -I $(INC) -o $@ -c $< -I $(LIB_INC)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -I $(INC) -o $(NAME) $(OBJ) -l $(LIB_NAME) -lcurses -I $(LIB_INC) -L $(LIB_DIR)
	@echo "$(NAME)$$ $(GREEN) $(NAME) was created! $(RESET)"

all : $(NAME)

bonus : all

norm :
	Norminette *.h *.c */*.c

clean :
	@rm -f $(OBJ)
	@echo "$(NAME)$$ $(RED) object files were deleted $(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(NAME)$$ $(RED) $(NAME) was deleted $(RESET)"

re: fclean all
