NAME	=	cub3D

CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra -g

SRCS	=	srcs/main.c srcs/init.c srcs/utils/exits.c srcs/utils/general_utils.c \
			srcs/events/key_handle.c srcs/extra/fps_tracking.c \
			srcs/render/raycasting.c srcs/render/ray_loop.c srcs/render/rendering_utils.c \
			srcs/render/movement.c srcs/render/player_pos.c srcs/render/texture_rendering.c \
			srcs/parsing/map_config.c srcs/parsing/map_reader.c srcs/parsing/resource_checks.c \
			srcs/parsing/resource_data.c srcs/parsing/grid_data.c srcs/parsing/grid_checks.c
			
OBJS	=	$(SRCS:.c=.o)

LIBFT_DIR	=	./Libs/libft
LIBFT		=	libft.a
MLX_DIR		=	./Libs/minilibx-linux
MLX			=	libmlx.a
INC			= 	-I$(MLX_DIR) -I$(LIBFT_DIR)
LIBS 		=	-L$(MLX_DIR) -lmlx -L$(LIBFT_DIR) -lft -lX11 -lXext -lm

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(MLX):
	make -C $(MLX_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(MLX_DIR) clean
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re