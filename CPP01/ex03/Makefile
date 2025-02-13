NAME=violence

CFLAG= -Wall -Wextra -Werror -Wshadow -std=c++98

CC=c++

INCLUDE= HumanA.hpp HumanB.hpp Weapon.hpp

SRC= HumanA.cpp    HumanB.cpp    main.cpp  Weapon.cpp  

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
