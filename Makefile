# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 17:43:28 by kdrumm            #+#    #+#              #
#    Updated: 2017/04/03 19:04:00 by kaidrumm         ###   ########.us        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft/ -lft
LIBVISUAL = -L libvisual/ -lvisual
HEADER = fractol.h
SRCS = main.c hooks.c fractal.c color.c controls.c

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	cd libft/ && make
	cd libvisual/ && make
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MINILIBX) $(LIBFT) $(LIBVISUAL)

norme:
	norminette $(SRCS) $(HEADER)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
