# =========================
# Basic configuration
# =========================
NAME    = so_long
CC      = cc
CFLAGS  = -Wall -Werror -Wextra -fPIE

# =========================
# MLX42 (cache outside project path to avoid spaces issues)
# =========================
MLX42_REPO    = https://github.com/codam-coding-college/MLX42.git
MLX42_TAG     = v2.4.2

MLX42_CACHE   = $(HOME)/.cache/mlx42
MLX42_SRC     = $(MLX42_CACHE)/MLX42
MLX42_BUILD   = $(MLX42_SRC)/build
MLX42_LIB     = $(MLX42_BUILD)/libmlx42.a

HEADERS = -I$(MLX42_SRC)/include -I/usr/include/GLFW
LIBS    = $(MLX42_LIB) -ldl -lglfw -pthread -lm

# =========================
# Source Files
# =========================
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

CFILES = $(SO_LONG_FILES) $(GET_NEXT_LINE_FILES) $(PRINTF_FILES) $(SO_LIBFT_FILES)
OBJS   = $(CFILES:.c=.o)

# =========================
# Targets
# =========================
all: $(MLX42_LIB) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

# =========================
# MLX42: download + build (in cache)
# =========================
$(MLX42_SRC):
	@mkdir -p "$(MLX42_CACHE)"
	@if [ ! -d "$(MLX42_SRC)/.git" ]; then \
		echo "Cloning MLX42 into $(MLX42_SRC)"; \
		git clone --depth 1 --branch "$(MLX42_TAG)" "$(MLX42_REPO)" "$(MLX42_SRC)"; \
	fi

$(MLX42_LIB): | $(MLX42_SRC)
	@if [ -f "$(MLX42_SRC)/tools/compile_shader.sh" ]; then chmod +x "$(MLX42_SRC)/tools/compile_shader.sh"; fi
	@cmake -S "$(MLX42_SRC)" -B "$(MLX42_BUILD)"
	@cmake --build "$(MLX42_BUILD)"

libs: $(MLX42_LIB)

# (Opcional) borrar la cache de MLX42 para “empezar de cero”
mlxclean:
	rm -rf "$(MLX42_SRC)"

clean:
	rm -f $(OBJS)

fclean: clean mlxclean
	rm -f $(NAME)

re: fclean all

winstall:
	sudo apt-get update
	sudo apt-get install -y cmake libgl-dev libglx-dev libglu-dev mesa-common-dev \
		libxrandr-dev libxinerama-dev libxcursor-dev libxi-dev
	sudo apt-get install -y libglfw3-dev build-essential libc6-dev

test:
	@./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

valgrind: re
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(filter-out $@,$(MAKECMDGOALS))

.PHONY: all libs mlxclean clean fclean re winstall test valgrind