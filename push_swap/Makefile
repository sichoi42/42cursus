NAME = push_swap
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

FUNC = commands/push\
		commands/swap\
		commands/rotate\
		commands/reverse_rotate\
		src/main\
		src/sorting\
		utils/ft_split\
		utils/ft_stacks\
		utils/ft_util1\
		utils/ft_util2\

SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))

.c.o : $(SRC)
	@$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "$(GREEN)object files were created!$(RESET)"
	@echo "$(GREEN)$(NAME) was created!$(RESET)"

all : $(NAME)

norm :
	Norminette commands/*.c src/*.c utils/*.c push_swap.h

clean :
	@rm -f $(OBJ)
	@echo "$(RED)object files were deleted!$(RESET)"

fclean : clean
	@rm -f $(NAME)
	@echo "$(RED)$(NAME) was deleted!$(RESET)"

re : fclean all
