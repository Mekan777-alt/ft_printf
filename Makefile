# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kshantay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 18:35:05 by kshantay          #+#    #+#              #
#    Updated: 2021/12/15 13:30:20 by kshantay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIST = ft_printf.c ft_printf_s.c ft_putnbr.c

OBJ = $(patsubst %.c,%.o,$(LIST))

CC = gcc

FLAGS = -Wall -Wextra -Werror

all : $(NAME)

HEAD = libft.h

.PHONY : all clean fclean re

$(NAME) : $(OBJ)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(NAME)

re : fclean all

