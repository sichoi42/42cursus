# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sichoi <sichoi@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/02 21:30:15 by hyunwkim          #+#    #+#              #
#    Updated: 2021/07/05 21:34:14 by sichoi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs

SRCS = ft_printf.c\
	ft_printf_utils.c\
	ft_tools1.c\
	ft_tools2.c\
	ft_surplus.c\
	print_int.c\
	print_c.c\
	print_s.c\
	print_u.c\
	print_hex.c\
	print_p.c

OBJS = $(SRCS:.c=.o)

.c.o : $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $^

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $@ $^

all : $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
