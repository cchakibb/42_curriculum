NAME = minitalk

SRC_DIR = src
INCLUDE_DIR = include
PRINTF_DIR = ft_printf

SERVER_SRC = $(SRC_DIR)/server.c
CLIENT_SRC = $(SRC_DIR)/client.c

SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

PRINTF_MAKEFILE = $(PRINTF_DIR)/Makefile

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(SERVER_OBJ) $(CLIENT_OBJ)
	@make -C $(PRINTF_DIR)
	@$(CC) $(CFLAGS) -o server $(SERVER_OBJ) -I$(INCLUDE_DIR) -L$(PRINTF_DIR) -lftprintf
	@$(CC) $(CFLAGS) -o client $(CLIENT_OBJ) -I$(INCLUDE_DIR) -L$(PRINTF_DIR) -lftprintf

$(SERVER_OBJ): $(SERVER_SRC)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR) -I$(PRINTF_DIR)

$(CLIENT_OBJ): $(CLIENT_SRC)
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INCLUDE_DIR) -I$(PRINTF_DIR)

clean:
	@make -C $(PRINTF_DIR) clean
	@$(RM) $(SERVER_OBJ) $(CLIENT_OBJ)

fclean: clean
	@make -C $(PRINTF_DIR) fclean
	@$(RM) server client

re: fclean all

.PHONY: all clean fclean re
