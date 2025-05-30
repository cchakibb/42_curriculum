# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:43:37 by stobin            #+#    #+#              #
#    Updated: 2023/12/09 00:00:27 by stobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_isalnum.c ft_isdigit.c ft_memchr.c ft_memmove.c \
		ft_putendl_fd.c ft_split.c ft_striteri.c ft_strlen.c ft_strnstr.c \
		ft_substr.c ft_bzero.c ft_isalpha.c ft_isprint.c ft_memcmp.c \
		ft_memset.c ft_putnbr_fd.c ft_strchr.c ft_strjoin.c ft_strmapi.c \
		ft_strrchr.c ft_tolower.c ft_calloc.c ft_isascii.c ft_itoa.c \
		ft_memcpy.c ft_putchar_fd.c ft_putstr_fd.c ft_strdup.c ft_strlcat.c \
		ft_strlcpy.c ft_strncmp.c ft_strtrim.c ft_toupper.c ft_isspace.c \
		ft_free_strarr.c
BSRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
		ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
		ft_lstmap.c

HEADERS = libft.h

OBJS = $(SRCS:.c=.o)
BOBJS = $(BSRCS:.c=.o)

NAME = libft.a

ARC = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BOBJS) $(NAME)
	$(ARC) $(NAME) $(BOBJS)
	ranlib $(NAME)

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
