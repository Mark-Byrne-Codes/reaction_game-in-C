NAME = reaction_time_game
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src

SRC = $(SRC_DIR)/main.c \
      $(SRC_DIR)/game.c \
      $(SRC_DIR)/logic.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re