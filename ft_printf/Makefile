NAME = libftprintf.a
LIBFTNAME = libft.a
HEADER = ft_printf.h
LIBFTDIR = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(addsuffix .c, conversions_1 conversions_2 extra_func ft_printf)
OBJS := $(SRCS:%.c=%.o)
AR = ar rc
RM = rm -f

# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

all: $(NAME)

makelibft:
	@echo "-------------------------"
	@make -C $(LIBFTDIR)
	@cp $(LIBFTDIR)/$(LIBFTNAME) .
	@mv $(LIBFTNAME) $(NAME)

$(NAME): makelibft $(OBJS)
	$(AR) $@ $(OBJS)
	@echo "$(GREEN)ft_printf compiled!$(DEF_COLOR)"

%.o: %.c $(HEADER)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	@cd $(LIBFTDIR) && make clean
	@echo "$(BLUE)ft_printf object files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)ft_printf executable files cleaned!$(DEF_COLOR)"
	@echo "$(CYAN)libft executable files cleaned!$(DEF_COLOR)"

fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFTDIR) && make fclean

re: fclean all
	@echo "$(GREEN)Cleaned and rebuilt everything for ft_printf!$(DEF_COLOR)"

.PHONY:		all clean fclean re
