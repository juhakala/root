#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhakala <jhakala@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 14:21:02 by jhakala           #+#    #+#              #
#    Updated: 2019/11/23 20:06:45 by jhakala          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = src/main.c \
	src/read.c \
	src/new_and_del.c \
	src/apu_func.c \
	src/solver.c

INC = src/fillit.h

LIBFT_PATH = libft/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): make_libft
	gcc $(FLAGS) -o $(NAME) $(SRC) -I $(INC) -L libft/ -lft

make_libft:
	make -C libft/

clean:
	make clean -C libft/

fclean:
	make fclean -C libft/
	/bin/rm -rf fillit

re: fclean all
