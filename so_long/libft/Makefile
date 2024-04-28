# Compiler
CC = cc

# Compiler flags
CFLAGS = -g -Wall -Wextra -Werror

# Source files
SRC = $(wildcard *.c)

# Object files
OBJ_DIR = Objects

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

# Name of library
NAME = libft.a

all: $(NAME)

# Create the Objects directory if it doesn't exist
$(shell mkdir -p $(OBJ_DIR))

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf $(OBJ_DIR)

re: fclean all

.PHONY: all clean fclean re
