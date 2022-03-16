# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/07 18:29:36 by sichoi            #+#    #+#              #
#    Updated: 2021/05/20 19:24:16 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

FUNC = ft_strlen\
	ft_memset\
	ft_bzero\
	ft_memcpy\
	ft_memccpy\
	ft_memmove\
	ft_memchr\
	ft_memcmp\
	ft_strlcpy\
	ft_strlcat\
	ft_strchr\
	ft_strrchr\
	ft_strnstr\
	ft_strncmp\
	ft_atoi\
	ft_isalpha\
	ft_isdigit\
	ft_isalnum\
	ft_isascii\
	ft_isprint\
	ft_toupper\
	ft_tolower\
	ft_calloc\
	ft_strdup\
	ft_substr\
	ft_strjoin\
	ft_strtrim\
	ft_split\
	ft_itoa\
	ft_strmapi\
	ft_putchar_fd\
	ft_putstr_fd\
	ft_putendl_fd\
	ft_putnbr_fd

FUNC_b = ft_lstnew\
	ft_lstadd_front\
	ft_lstsize\
	ft_lstlast\
	ft_lstadd_back\
	ft_lstdelone\
	ft_lstclear\
	ft_lstiter\
	ft_lstmap

SRCS = $(addsuffix .c, $(FUNC))
SRCS_b = $(addsuffix .c, $(FUNC_b))
OBJS = $(addsuffix .o, $(FUNC))
OBJS_b = $(addsuffix .o, $(FUNC_b))

.c.o : $(SRCS) $(SRCS_b)
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

bonus : $(OBJS_b)
	$(AR) $(ARFLAGS) $(NAME) $^

all : $(NAME)

clean :
	rm -f $(OBJS) $(OBJS_b)

fclean : clean
	rm -f $(NAME)

re : fclean all
