# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror -g

# Include directories
INCLUDES = -I./include -I./libft -I./ft_printf

# Source files
SRC = $(wildcard src/*.c) $(wildcard src/commands/*.c) $(wildcard src/push_swap/*.c)

# Object files
OBJ_DIR = Objects

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

# Libraries
LIBFT = libft/libft.a
PRINTF = ft_printf/libftprintf.a
LIBS = $(LIBFT) $(PRINTF)

# Name of executable
NAME = push_swap

all: $(NAME)

# Create the Objects directory if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))
$(shell mkdir -p $(dir $(OBJ)))

$(NAME): $(LIBS) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

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
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
