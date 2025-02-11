# Basic configuration
NAME = so_long
CC = cc
CFLAGS = -Wall -Werror -Wextra -fPIE -Ilibs/MLX42-master/include -I/usr/include/GLFW
OBJS = $(CFILES:.c=.o)

# Files
CFILES = $(SO_LONG_FILES) $(GET_NEXT_LINE_FILES) $(PRINTF_FILES) $(SO_LIBFT_FILES)

# MLX42 lib
MLX42_DIR = libs/MLX42-master/build
MLX42_LIB = $(MLX42_DIR)/libmlx42.a
MLX42_FLAGS = -lglfw -pthread -lm -ldl

# Source Files
SO_LONG_FILES = 		src/so_long.c\
						src/so_long_loadmap.c\
						src/so_long_checkmap.c\
						src/so_long_textures.c\
						src/so_long_rendermap.c\
						src/so_long_player.c\
						src/so_long_exit.c\
						src/so_long_unload.c\
						src/so_long_lookmap.c\
						src/so_long_loading.c\
						src/so_long_accessibility_ec.c\

GET_NEXT_LINE_FILES = 	src/get_next_line/get_next_line.c\
						src/get_next_line/get_next_line_utils.c

PRINTF_FILES =			src/ft_printf/ft_printf.c \
						src/ft_printf/ft_putchar_print.c \
						src/ft_printf/ft_putnbrs_print.c \
						src/ft_printf/ft_putstr_print.c

SO_LIBFT_FILES =		src/so_libft/so_strdupp.c \
						src/so_libft/so_strjoin.c \
						src/so_libft/so_strlcat.c \
						src/so_libft/so_strlcpy.c \
						src/so_libft/so_strlen.c

# Orders
all: $(MLX42_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MLX42_LIB) $(MLX42_FLAGS) -o $(NAME)

$(MLX42_LIB):
	@chmod +x libs/MLX42-master/tools/compile_shader.sh
	@mkdir -p $(MLX42_DIR)
	@cd libs/MLX42-master && cmake -B build && cmake --build build

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -rf $(MLX42_DIR)

re: fclean all

winstall:
	sudo apt-get update
	sudo apt-get install -y cmake libgl-dev libglx-dev libglu-dev mesa-common-dev \
		libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
	sudo apt-get install libglfw3-dev
	sudo apt-get install build-essential
	sudo apt-get install libc6-dev
	sudo apt update
	sudo apt install libglfw3-dev

libs: $(MLX42_LIB)

test: 
	@./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

.PHONY: all clean fclean re winstall libs test valgrind
