NAME = cub3D

LIBFT = libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

INCLUDE = -L libft/ -lft

HEADER = libft/libft.h cub3d.h

MLX_LIB = mlx/libmlx_Linux.a

MLX_FLAGS = -Lmlx -lXext -lX11 -lm

SRC_F :=	main.c \
			parsing/parser.c \
			parsing/parse_identifiers.c \
			parsing/parse_colors.c \
			parsing/parse_textures.c \
			parsing/parse_map.c \
			parsing/check_map.c \
			parsing/toolbox.c \
			rays/utils_1.c \
			rays/rays.c \
			rays/rays_utils_1.c \
			rays/utils_2.c \
			rays/render_3d.c \
			rays/utils_3.c \
			rays/key_handler.c

OBJ_F := $(SRC_F:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJ_F) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_F) $(MLX_LIB) $(MLX_FLAGS) -o $@ $(INCLUDE)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	@make -C libft/

clean:
	@make -C libft/ clean
	rm -rf $(OBJ_F)

fclean: clean
	@make -C libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: clean libft
