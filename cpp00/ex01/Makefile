NAME = phone_book
CC = g++
CFLAG = -Wall -Wextra -Werror -std=c++98
SOURCE = Contact.cpp \
		 PhoneBook.cpp \
		 main.cpp



OBJ = $(SOURCE:.cpp=.o)


all : $(NAME)

$(NAME): $(OBJ)

%.o: %.cpp PhoneBook.hpp Contact.hpp
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)


fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : clean