# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chbachir <chbachir@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/06 14:54:21 by chbachir          #+#    #+#              #
#    Updated: 2024/06/06 14:54:21 by chbachir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = ft_printf.c ft_putchar.c ft_putstring.c ft_putnbr.c ft_puthex.c ft_putunsigned_int.c ft_putpointer.c

OBJS			= $(SRCS:.c=.o)
HEADER			= ft_printf.h
CC			= cc
RM			= rm -f
CFLAGS			= -Wall -Wextra -Werror
NAME			= libftprintf.a
all:			$(NAME)
$(NAME):		$(OBJS)
			ar rc $(NAME) $(OBJS)
			ranlib $(NAME)
clean:
			$(RM) $(OBJS)
fclean:			clean
			$(RM) $(NAME)
re:			fclean $(NAME)
.PHONY:			all clean fclean re
