NAME=scarvtrap
CC=c++
CFLAG= -Wall -Wextra -Werror -Wshadow -std=c++98

SRC = ClapTrap.cpp main.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp

OBJ=$(SRC:.cpp=.o)

INCLUDE= ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAG) -c $< -o $@

$(OBJ) : $(INCLUDE)

$(NAME): $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

run : all clean
	./$(NAME)

PHONY : clean