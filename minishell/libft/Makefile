.PHONY: all bonus clean fclean re

SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_strncpy.c ft_strcpy.c ft_strcat.c \
	ft_strcmp.c
OBJS = $(SRCS:.c=.o)
NAME  = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

%.o : %.c
	@$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	@echo "Make LIBFT"
	@ar rc $(NAME) $(OBJS)

bonus: $(NAME) $(B_OBJS)
	@ar rc $(NAME) $(B_OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
