NAME=account
CC=c++
CFLAGS=-Wall -Wextra -Werror  -std=c++98

INCLUDE= Account.hpp

SRC= Account.cpp tests.cpp

OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(OBJ) : $(INCLUDE)

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