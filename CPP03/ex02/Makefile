NAME = ScavTrap

CC = c++

CFLAG = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

OBJ=$(SRC:.cpp=.o)


all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAG) -c $< -o $@

$(OBJ) : ClapTrap.hpp ScavTrap.hpp FragTrap.hpp

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