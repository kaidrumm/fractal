# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdrumm <kdrumm@student.42.us.org>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/04/20 12:44:47 by kdrumm            #+#    #+#              #
#    Updated: 2017/04/20 12:46:25 by kdrumm           ###   ########.us        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror -Ofast
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
