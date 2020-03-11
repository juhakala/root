#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/25 18:10:43 by jhakala           #+#    #+#              #
#    Updated: 2019/12/04 20:23:42 by jhakala          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fdf

SRC = src/main.c \
	src/init.c \
	src/read.c \
	src/apu_func.c \
	src/draw.c \
	src/rotate.c \
	src/color.c \
	src/controls.c

SRC_N = main.c \
	init.c \
	read.c \
	apu_func.c \
	draw.c \
	rotate.c \
	color.c \
	controls.c

OBJ =  $(SRC_N:.c=.o)

FLAGS = -Wall -Wextra -Werror

ADD = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@make -C libft/
	gcc $(FLAGS) -I libft/includes -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(ADD) -L libft/ -lft

clean:
	@make -C libft/ clean
	@/bin/rm -f $(OBJ)

fclean:
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(OBJ)
	@make -C libft/ fclean


re:	fclean all

