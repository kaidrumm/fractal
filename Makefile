# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Kai <kdrumm@student.42.us.org>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/14 17:43:28 by kdrumm            #+#    #+#              #
#    Updated: 2017/03/28 20:05:10 by KaiDrumm         ###   ########.us        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft/ -lft
HEADER = fractol.h
SRCS = main.c map.c draw_pixel.c hsv_rgb.c view.c triple.c color.c

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
