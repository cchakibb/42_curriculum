# ft_printf Makefile

# Compiler
CC = cc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror

# Source files
SRC = $(wildcard *.c)

# Object files
OBJ = $(SRC:.c=.o)

# Name of library
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


#NAME = libftprintf.a

#SRC_DIR = . 
#INCLUDE_DIR = .
#OBJ_DIR = obj

#SRC = conversions_1.c conversions_2.c extra_func.c ft_printf.c ft_putnbr_fd.c ft_strlen.c
#OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

#CC = cc
#CFLAGS = -Wall -Wextra -Werror
#AR = ar rc
#RM = rm -f
#MKDIR = mkdir -p

#all: $(NAME)

#$(NAME): $(OBJ)
#	@$(AR) $(NAME) $(OBJ)

#$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
#	@$(MKDIR) $(OBJ_DIR)
#	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR)

#clean:
#	@$(RM) -r $(OBJ_DIR)

#fclean: clean
#	@$(RM) $(NAME)

#re: fclean all

#.PHONY: all clean fclean re
