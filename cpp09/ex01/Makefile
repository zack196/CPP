NAME=RPN
CC=c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
INCLUDE=RPN.hpp
SRC= main.cpp RPN.cpp
OBJ=$(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

$(OBJ) : $(INCLUDE)

re : fclean all

.PHONY : clean