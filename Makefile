NAME = Cub3D

FLAGS = -Wall -Wextra -Werror

CC = gcc

LIBFT = libft/libft.a

MLXSRC = minilibx-linux

MLXFLAGS = -lmlx -Lmlx -lm -lbsd -lX11 -lXext

HEADER = includes/cub3d.h

SRCS =	src/cub3d.c \
		src/setup_map_ft.c \
		src/check_error.c \
		src/ft_init_player.c \
		src/ft_loop.c \
		src/ft_check_path.c \
		src/ft_put_path.c \
		src/ft_draw.c \
		src/ft_mv_cam.c \
		src/ft_mv.c \
		src/ft_put_sp.c \
		src/ft_sp_tab.c \
		src/ft_key.c \
		src/ft_free.c \
		src/ft_bmp.c \
		src/check_color.c


OBJS = $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(MAKE) -C libft
	$(CC) $(HEADER) $(FLAGS) $(OBJS) $(LIBFT) -o ${NAME} $(MLXFLAGS)

norme:
	norminette libft
	@echo
	norminette $(HEADER)
	@echo
	norminette $(SRCS)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: fclean re norme all clean