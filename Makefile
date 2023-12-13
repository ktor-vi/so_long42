
NAME = so_long


SRC = 	        src/main.c    \
				src/parse_utils.c     \
				src/parsing.c         \
				src/verif.c           \
				src/key_press.c       \
				src/display_utils.c   \
				src/display.c         \
				src/move.c            \
				src/init.c            \
				src/init_player.c     \
				src/init_textures.c   \
				src/completion.c      \
				src/fool_proof.c      \

INC = includes/fdf.h

CC = cc

FLAGS = -Wall -Wextra -Werror  -g -fsanitize=address 

OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
MLX_DIR = mlx
MLX:= $(MLX_DIR)/libmlx42.a -ldl -lglfw -pthread -lm


all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/libft.a .
	@cp $(LIBFT_DIR)/libftprintf.a .
	@cp $(MLX_DIR)/libmlx42.a .
	$(CC) $(FLAGS) $(OBJ)  libft.a libftprintf.a libmlx42.a $(MLX) -L"/Users/$(USER)/.brew/opt/glfw/lib/" -framework Cocoa -framework OpenGL -framework IOKit	-o $(NAME)
	@rm libft.a
	@rm libftprintf.a
	@rm libmlx42.a

clean:
	@make fclean -C $(LIBFT_DIR)
	rm -f $(OBJ) $(BONUS_OBJS)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all clean

.PHONY: all clean fclean re
