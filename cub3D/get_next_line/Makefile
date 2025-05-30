# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stobin <stobin@student.42berlin.de>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/03 18:03:44 by stobin            #+#    #+#              #
#    Updated: 2024/06/15 22:51:14 by stobin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= get_next_line.a
CC 		= cc
CFLAGS 	= -Wall -Wextra -Werror
SRCS 	= get_next_line.c get_next_line_utils.c free_drop.c
RM 		= rm -f

HEADERS = get_next_line.h

OBJS = $(SRCS:.c=.o)

NAME = gnl.a

ARC = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(ARC) $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(OBJS) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
