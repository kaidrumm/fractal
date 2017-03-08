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

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
MINILIBX = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit
LIBFT = -L libft/ -lft
SRCS = fdf.c fdf2.c fdf3.c fdf4.c fdf5.c fdf6.c

.PHONY: clean fclean re

all: $(NAME)

$(NAME):
	cd libft/ && make re
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS) $(MINILIBX) $(LIBFT)

norme:
	norminette $(SRCS) fdf.h

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
