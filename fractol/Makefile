NAME = fractol

SRC = main.c \
    init.c \
    keys.c \
    info.c \
    mouse.c \
    animation.c \
    animation_support.c \
    pthread.c \
    julia.c \
    mandelbrot.c \
    burningship.c \
    sierpinski.c \
    own_fractal.c \
    draw.c

S_DIR = src
O_DIR = obj
OBJ = $(addprefix $(O_DIR)/, $(SRC:.c=.o))
HEAD = fractol.h key.h
H_DIR = includes
BONUS = -lmlx -framework OpenGL -framework AppKit
LIBFT = libft/libft.a
GCC = gcc -Wall -Wextra -Werror
DEPS = $(patsubst %,$(H_DIR)/%,$(HEAD))

all: $(NAME)

$(NAME): $(OBJ) | $(LIBFT)
	@$(GCC) -o $@ $^ -I $(H_DIR) $(BONUS) $(LIBFT)
	@echo  "fractol \033[1;32m[OK]\033[0m"

$(O_DIR)/%.o : $(S_DIR)/%.c $(DEPS)
	$(GCC) -o $@ -c $< -I $(H_DIR)

$(OBJ): | $(O_DIR)

clean:
	@make -C libft clean
	@rm -rf $(O_DIR)
	@echo "clean \033[1;32m[OK]\033[0m"

fclean:
	@make -C libft fclean
	@rm -rf $(O_DIR)
	@rm -rf $(NAME)
	@echo "fclean \033[1;32m[OK]\033[0m"

re: fclean all

$(LIBFT):
	@make -C libft

$(O_DIR):
	mkdir $(O_DIR)