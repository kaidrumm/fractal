# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdrumm <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 17:43:28 by kdrumm            #+#    #+#              #
#    Updated: 2016/12/14 17:44:37 by kdrumm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft/ -lft
HEADER = fractol.h
SRCS = main.c init_map.c draw_pixel.c

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	cd libft/ && make re
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MINILIBX) $(LIBFT)

norme:
	norminette $(SRCS) $(HEADER)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
