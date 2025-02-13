NAME=animal
CFLAG= -Wall -Wextra -Werror -Wshadow -std=c++98
CC=c++
INCLUDE= Animal.hpp WrongAnimal.hpp WrongCat.hpp Dog.hpp Cat.hpp 

SRC= Animal.cpp main.cpp Dog.cpp Cat.cpp WrongAnimal.cpp WrongCat.cpp


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