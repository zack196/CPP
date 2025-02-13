NAME=interface

CFLAG= -Wall -Wextra -Werror -Wshadow -std=c++98

CC=c++

INCLUDE = AMateria.hpp Ice.hpp ICharacter.hpp Cure.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp

SRC= AMateria.cpp main.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp


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