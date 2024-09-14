CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
SRC_SERVER = server.c

NAME = client
NAME_SERVER = server

all: $(NAME) $(NAME_SERVER)

$(NAME): $(SRC_CLIENT)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC_CLIENT)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) -o $(NAME_SERVER) $(SRC_SERVER)

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(NAME) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re