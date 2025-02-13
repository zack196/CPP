NAME=identify
CFLAG= -Wall -Wextra -Werror -Wshadow -std=c++98
CC=c++
INCLUDE= Base.hpp A.hpp B.hpp C.hpp

SRC= main.cpp Base.cpp 
 
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