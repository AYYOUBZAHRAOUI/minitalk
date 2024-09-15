CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_CLIENT = client.c
SRC_SERVER = server.c

NAME = client
NAME_SERVER = server

all: $(NAME) $(NAME_SERVER)

$(NAME): $(SRC_CLIENT)
	$(CC) $(CFLAGS) $(SRC_CLIENT) -o $(NAME)

$(NAME_SERVER): $(SRC_SERVER)
	$(CC) $(CFLAGS) $(SRC_SERVER) -o $(NAME_SERVER)

clean:
	@echo "No Object file in this program"

fclean: clean
	rm -f $(NAME) $(NAME_SERVER)

re: fclean all

.PHONY: all clean fclean re