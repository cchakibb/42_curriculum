# Root Makefile

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Include directories
INCLUDES = -I./include -I./libft -I./ft_printf

# Source files
SRC = $(wildcard src/commands/*.c) $(wildcard src/push_swap/*.c)

# Object files
OBJ = $(SRC:.c=.o)

# Libraries
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIBS = $(LIBFT) $(PRINTF)

# Name of executable
NAME = push_swap

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	make -C libft

$(PRINTF):
	make -C ft_printf

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
