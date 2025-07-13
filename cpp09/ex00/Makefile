NAME=btc
CC=c++
CFLAGS= -Wall -Wextra -Werror -std=c++98
INCLUDE=BitcoinExchange.hpp
SRC= main.cpp BitcoinExchange.cpp
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