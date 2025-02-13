NAME=Mutantstack
CFLAG= -Wall -Wextra -Werror -Wshadow -std=c++98
CC=c++
INCLUDE= MutantStack.hpp

SRC= main.cpp

OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

$(OBJ) : $(INCLUDE)

%.o: %.cpp
	$(CC) $(CFLAG) -c $< -o $@

clean:
	rm -f $(OBJ)

re : fclean all

fclean : clean
	rm -f $(NAME)

.PHONY : clean