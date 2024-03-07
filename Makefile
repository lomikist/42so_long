NAME = main

SRCS = ./src/main.c ./src/checker.c ./utils/get_next_line/get_next_line.c ./utils/get_next_line/get_next_line_utils.c  ./utils/get_next_line/ft_split.c 

CC = cc -g

FLAGS = -Wall -Wextra -Werror -fsanitize=address

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@ 

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all
