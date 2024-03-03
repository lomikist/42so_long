NAME = ../main

SRCS =  ./src/main.c ./42printf/functions.c

CC = cc

FLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
