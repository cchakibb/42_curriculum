# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/19 14:50:00 by stobin            #+#    #+#              #
#    Updated: 2025/05/02 02:50:00 by stobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
INCLUDES = -Iincl -Ilibft -Iget_next_line -I$(MLX_DIR)

MLX_DIR = minilibx-linux
MLX_A = $(MLX_DIR)/libmlx.a
MLX_ZIP = minilibx-linux.zip
MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
MLX_URL = https://github.com/42Paris/minilibx-linux/archive/refs/heads/master.zip

LIBFT_DIR = libft
LIBFT_A = $(LIBFT_DIR)/libft.a
GNL_DIR = get_next_line
GNL_A = $(GNL_DIR)/gnl.a

SRC_FILES = src/main.c src/init_game.c src/input_handler.c \
			  src/parsing/parse_cub_file.c src/parsing/texture_parser.c \
			  src/parsing/colour_parser.c src/parsing/map_parser.c \
			  src/parsing/map_validator.c src/parsing/player_parser.c \
			  src/parsing/parse_tools.c src/raycasting/render.c \
			  src/raycasting/raycasting.c \
			  src/raycasting/mlx_utils.c

BUILD_DIR = build
OBJS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))

all: $(NAME)

$(NAME): $(LIBFT_A) $(GNL_A) $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT_A) $(GNL_A) -o $(NAME) $(MLX_FLAGS)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(GNL_A):
	$(MAKE) -C $(GNL_DIR)

$(BUILD_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(MLX_A):
	@if [ ! -d $(MLX_DIR) ]; then \
		echo "MiniLibX directory not found."; \
		if [ -f $(MLX_ZIP) ]; then \
			echo "Found zip. Unzipping..."; \
		else \
			echo "Zip not found. Downloading..."; \
			curl -L $(MLX_URL) -o $(MLX_ZIP); \
		fi; \
		unzip -q $(MLX_ZIP); \
		mv minilibx-linux-master $(MLX_DIR); \
	else \
		echo "MiniLibX directory already exists. Skipping download."; \
	fi
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(GNL_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(GNL_DIR) fclean
	$(RM) $(NAME)
	rm -rf $(MLX_DIR)
	rm -rf $(BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
