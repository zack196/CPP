NAME=phonebook
CC=c++
CFLAGS=-Wall -Wextra -Werror  -std=c++98

INCLUDE= Contact.hpp PhoneBook.hpp

SRC= Contact.cpp PhoneBook.cpp main.cpp

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