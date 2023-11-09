SRCS = main.cpp Serializer.cpp

NAME = convert

CC = c++ 

FLAGS = -Wall -Wextra -Werror -std=c++98 

HEADER = Serializer.hpp

all: $(NAME)

$(NAME): $(SRCS) $(HEADER)
	$(CC) $(FLAGS) $(SRCS) -o $@

fclean:
	rm -f $(NAME)

re: fclean all
