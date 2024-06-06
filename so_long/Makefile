INC=%%%%
INCLIB= minilibx-linux/
UNAME := $(shell uname)
CFLAGS= -I$(INC) -O0 -I.. -g
NAME= so_long
SRC = main.c map_utils.c free.c map_parse.c draw.c game_utils.c Libft/get_next_line.c Libft/get_next_line_utils.c Libft/ft_printf.c Libft/ft_putchar.c Libft/ft_puthex.c Libft/ft_putnbr.c Libft/ft_putpointer.c Libft/ft_putstring.c Libft/ft_putunsigned_int.c
OBJ = $(SRC:%.c=%.o)
LFLAGS = -lmlx -L$(INCLIB) -lXext -lX11 -lm
ifeq ($(UNAME), Darwin)
    # mac
    CC = gcc
else ifeq ($(UNAME), FreeBSD)
    # FreeBSD
    CC = clang
else
    #Linux and others...
    CC = cc
    LFLAGS += -lbsd
endif
all: $(NAME)
$(NAME): $(OBJ)
	$(CC) -g -O0 -o $(NAME) $(OBJ) $(LFLAGS)
clean:
	rm -f $(NAME) $(OBJ) *~ core *.core
fclean: clean
	rm -rf $(NAME)
re: clean all
.PHONY: all clean fclean re
