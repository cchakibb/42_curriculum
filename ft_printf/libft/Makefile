NAME = libft.a
HEADER = libft.h
CC = cc
CFLAGS = -Wall -Werror -Wextra
AR = ar rc
RM = rm -f

#Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

SOURCES = ft_putnbr_fd.c ft_strlen.c
OBJECTS = $(SOURCES:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "-------------------------"
	$(AR) $@ $^
	@echo "$(GREEN)Libft compiled!$(DEF_COLOR)"

%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS)
	@echo "$(BLUE)libft objects files cleaned!$(DEF_COLOR)"


fclean: clean
	$(RM) $(NAME)
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for libft!$(DEF_COLOR)"

.PHONY: all clean fclean re
