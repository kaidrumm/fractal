# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kdrumm <kdrumm@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 14:34:32 by kdrumm            #+#    #+#              #
#    Updated: 2016/10/24 15:57:59 by kdrumm           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SRC_NAME = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_itoa.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strsplit.c \
			ft_strtrim.c \
			ft_strjoin.c \
			ft_strtrimc.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_lstaddb.c \
			ft_lstprint.c \
			ft_iswhitespace.c \
			ft_strndup.c \
			ft_strsplit_list.c \
			ft_atoi_base.c \
			ft_itoa_base.c \
			ft_memcpy_r.c \
			ft_lstinsert.c \
			ft_lstsort.c \
			ft_lstpop.c \
			ft_strnlen.c \
			get_next_line.c \
			ft_swap.c
OBJ_NAME = $(SRC_NAME:.c=.o)
TESTFILE = test.c test1.c test2.c test3.c test4.c test5.c test6.c testlist.c

.PHONY: clean fclean re

all: $(NAME)

$(NAME): $(OBJ_NAME)
	ar rcs $(NAME) $(OBJ_NAME)

$(OBJ_NAME): $(SRC_NAME)
	$(CC) -c $(CFLAGS) $(SRC_NAME)

test: $(NAME)
	$(CC) $(CFLAGS) -o jk $(TESTFILE) -L. -lft

norme:
	norminette $(SRC_NAME)

clean:
	rm -f $(OBJ_NAME)

fclean: clean
	rm -f $(NAME)

re: fclean all
