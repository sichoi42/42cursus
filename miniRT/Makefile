# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/24 17:05:57 by sichoi            #+#    #+#              #
#    Updated: 2022/06/18 16:40:31 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT

MLX_NAME = libmlx.dylib
MLX_DIR = ./mlx
LIB_MLX = $(MLX_DIR)/$(MLX_NAME)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
CHECK = \033[0;32m\xE2\x9C\x94\033[0m

FUNC = ./draw\
	./init/init\
	./init/add_sphere\
	./init/add_plane\
	./init/add_cylinder\
	./init/add_cone\
	./init/add_light\
	./print/print\
	./scene/camera\
	./scene/canvas\
	./scene/create_cone\
	./scene/create_cylinder\
	./scene/create_light\
	./scene/create_plane\
	./scene/create_sphere\
	./scene/object_create\
	./trace/hit/normal\
	./trace/hit/hit\
	./trace/hit/hit_plane\
	./trace/hit/hit_sphere\
	./trace/hit/hit_cylinder_cap\
	./trace/hit/hit_cylinder\
	./trace/hit/hit_cone\
	./trace/hit/hit_cone_side\
	./trace/ray/bumpmap\
	./trace/ray/checkerboard\
	./trace/ray/hit_color_select\
	./trace/ray/phong_lighting\
	./trace/ray/ray\
	./utils/obj_utils\
	./utils/vec3_utils\
	./utils/vec3_init\
	./utils/vec3_calc\
	./utils/vec3_calc2\
	./utils/mlx_utils\
	./utils/math_utils\
	./main\
	./base/ft_memset\
	./base/print_error\
	./base/ft_strlen\
	./base/ft_strcmp\
	./base/ft_read\
	./base/malloc_array\
	./base/ft_realloc\
	./base/stox\
	./parse/check\
	./parse/input_am_li_ca\
	./parse/input_obj\
	./parse/input_xyz\
	./parse/next_line\
	./parse/tool_sp_st_fl

SRC = $(addsuffix .c, $(FUNC))
OBJ = $(addsuffix .o, $(FUNC))

INC = ./include

%.o : %.c
	@echo "$(NAME): $(GREEN) compiling... $< $(CHECK) $(RESET)"
	@$(CC) $(CFLAGS) -I $(INC) -I $(MLX_DIR) -o $@ -c $<

$(NAME) : $(LIB_MLX) $(OBJ)
	@$(CC) $(CFLAGS) -L $(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJ)
	@echo "$(NAME): $(GREEN) $(NAME) was created! $(CHECK) $(RESET)"
	@install_name_tool -change libmlx.dylib $(LIB_MLX) $(NAME)
	@echo "$(NAME): $(GREEN) Completed Setting Path of $(MLX_NAME) $(CHECK) $(RESET)"

$(LIB_MLX):
	$(MAKE) -sC $(MLX_DIR)
	@echo "$(NAME): $(GREEN) $(MLX_NAME) was created! $(CHECK) $(RESET)"

norm :
	Norminette *.c include/ init/ print/ scene/ trace/ utils/ base/ parse/

all : $(NAME)

bonus : all

clean :
	@$(MAKE) -sC $(MLX_DIR) clean
	@rm -f $(OBJ)
	@echo "$(NAME): $(RED) object files deleted $(RESET)"

fclean : clean
	@rm -f $(LIB_MLX)
	@echo "$(NAME): $(RED) $(MLX_NAME) was deleted $(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED) $(NAME) was deleted $(RESET)"

re : fclean all
