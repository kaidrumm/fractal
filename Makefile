# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaidrumm <kaidrumm@student.42.us>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 17:43:28 by kdrumm            #+#    #+#              #
#    Updated: 2017/03/23 20:56:39 by kaidrumm         ###   ########.us        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft/ -lft
HEADER = fractol.h
SRCS = main.c map.c draw_pixel.c hsv_rgb.c view.c triple.c

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
