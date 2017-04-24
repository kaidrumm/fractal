# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/17 16:03:35 by kdrumm            #+#    #+#              #
#    Updated: 2017/04/20 12:46:28 by kdrumm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libvisual.a
CFLAGS = -Wall -Wextra -Werror
SRC_NAME = draw_pixel.c \
			hsv_rgb.c \
			map.c \
			triple.c
OBJ_NAME = $(SRC_NAME:.c=.o)
INCLUDE = -I ../include/libft.h
LIBFT = -L ../libft/ -lft

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ_NAME)
	ar rcs $(NAME) $(OBJ_NAME)

$(OBJ_NAME): $(SRC_NAME)
	$(CC) -c $(CFLAGS) $(SRC_NAME) $(INCLUDE)

norme:
	norminette $(SRC_NAME)

clean:
	rm -f $(OBJ_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
