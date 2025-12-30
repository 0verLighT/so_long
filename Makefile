CC = cc
CFLAGS = -Wall -Werror -Wextra -g
MLX= ./MacroLibX/libmlx.so
LIBFT= ./libft/libft.a
MLX_DIR= ./MacroLibX
LIBFT_DIR= ./libft
LDFLAGS = -L$(MLX_DIR) -L$(LIBFT_DIR) -Wl,-rpath,$(MLX_DIR)
LDLIBS = -lmlx -lft -lm -lSDL2
NAME = so_long
INCLUDES = -Iincludes -I$(MLX_DIR)/includes -I$(LIBFT_DIR)
BUILD_DIR = .build
SRC = main.c
SRC_CHECKER = map.c checker.c error.c flood_fill.c
SRC_WINDOW = init.c
SRC_HOOK = key.c window.c

SRCS = \
	$(addprefix src/, $(SRC)) \
	$(addprefix src/checker/, $(SRC_CHECKER)) \
	$(addprefix src/hook/, $(SRC_HOOK)) \
	$(addprefix src/window/, $(SRC_WINDOW))


OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

$(BUILD_DIR):
	@mkdir -p $@

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -C $(LIBFT_DIR)
	make -C $(MLX_DIR) -j
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

re: fclean all

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(MLX_DIR) clean
	rm -rf .build/

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(MLX_DIR) fclean
	rm -f $(NAME)

.PHONY: all re flcean clean