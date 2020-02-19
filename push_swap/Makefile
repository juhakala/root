# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhakala <jhakala@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/10 19:48:51 by jhakala           #+#    #+#              #
#    Updated: 2020/02/03 14:12:06 by jhakala          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker
PUSH_SWAP = push_swap

C_SRC = main.c \
	utils.c \
	atoi_mod.c \
	make_move.c \
	cmd_s.c \
	cmd_p.c \
	cmd_r.c \
	cmd_rr.c \
	mlx.c \
	mlx_nega.c \
	keys.c

P_SRC = main.c \
	stack.c \
	atoi_mod.c \
	cmd_print.c \
	utils.c \
	get_order.c \
	put_cmd_s.c \
	put_cmd_p.c \
	put_cmd_r.c \
	put_cmd_rr.c \
	solve_pick.c \
	solve_small.c \
	solve_medium.c \
	solve_large.c \
	solve_calc.c \
	solve_utils.c \
	solve_support.c

C_DIR = c_src
CO_DIR = c_obj
OC_SRC = $(addprefix $(C_DIR)/, $(C_SRC))

P_DIR = p_src
PO_DIR = p_obj
OP_SRC = $(addprefix $(P_DIR)/, $(P_SRC))

COMP = gcc -Wall -Wextra -Werror

HEAD = -I libft/includes -I includes

LIBFT = libft/libft.a

BONUS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME) $(PUSH_SWAP)

$(CO_DIR)/%.o: $(C_DIR)%.c
	/bin/mkdir -p $(CO_DIR)
	$(COMP) -c $(HEAD) $< -o $@

$(NAME): $(OC_SRC)
	make -C libft
	$(COMP) -o $@ $^ $(HEAD) $(BONUS) $(LIBFT)

$(PO_DIR)/%.o: $(P_DIR)%.c
	/bin/mkdir -p $(PO_DIR)
	$(COMP) -c $(HEAD) $< -o $@

$(PUSH_SWAP): $(OP_SRC)
	make -C libft
	$(COMP) -o $@ $^ $(HEAD) $(LIBFT)

clean:
	/bin/rm -rf $(CO_DIR) $(PO_DIR)
	make -C libft clean

fclean:
	/bin/rm -rf $(CO_DIR) $(PO_DIR)
	/bin/rm -f $(NAME) $(PUSH_SWAP)
	make -C libft fclean
re:	fclean all
