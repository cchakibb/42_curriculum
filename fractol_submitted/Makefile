# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 12:00:31 by chbachir          #+#    #+#              #
#    Updated: 2024/06/14 12:00:32 by chbachir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_PATH = minilibx-linux
MLX = minilibx-linux/libmlx.a
LIB = fractol.h
SRC = main.c \
	events.c \
	julia.c \
	mandelbrot.c \
	utils.c

OBJS = $(SRC:.c=.o)
all:        $(NAME) $(MLX)
$(NAME): $(OBJS)
	@make -C $(MLX_PATH)
	$(CC) $(CFLAGS) $(OBJS) -L$(MLX_PATH) -lmlx_Linux -lX11 -lXext -lm -o $(NAME)
clean:
		rm -f $(OBJS)
		@make clean -C $(MLX_PATH)
fclean: clean
		rm -f $(NAME) $(MLX)
re:     fclean all
.PHONY: all clean fclean re
