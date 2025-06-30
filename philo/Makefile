NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I ./includes
# -fsanitize=thread data race
# -fsanitize=address leaks

RM = rm -f

SRC = ./srcs/main.c \
	./srcs/init.c \
	./srcs/utils.c \
	./srcs/parsing.c \
	./srcs/threads.c \
	./srcs/routine.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

make: make all

clean:
	$(RM) -r $(LIB_C)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY : all clean fclean re
