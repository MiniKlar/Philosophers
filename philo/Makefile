NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -pthread -I ./includes
CLONE = git clone

RM = rm -f

SRC = ./srcs/main.c \
	./srcs/utils.c \
	./srcs/utils_philo.c \
	./srcs/init.c \
	./srcs/threads.c \

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

re: fclean all

.PHONY : all clean fclean re
