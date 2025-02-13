NAME=megaphone
CFLAGS=-Wall -Wextra -Werror -Wshadow -std=c++98
CC=c++

SRC= megaphone.cpp

OBJ = $(SRC:.cpp=.o)


all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

re : fclean all

fclean : clean
	rm -f $(NAME)

.PHONY : clean
