NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -I ./includes -I ./LIB_C
CLONE = git clone

RM = rm -f

SRC = ./srcs/main.c \
	./srcs/utils.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(LIB_C):
	git clone $(LIB_C_GIT_URL) $(LIB_C)
	$(MAKE) -C $(LIB_C)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

make: make all

clean:
	$(RM) -r $(LIB_C)
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean LIB_C all

.PHONY : all clean fclean re
