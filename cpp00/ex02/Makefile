NAME = account
CC = g++
CFLAG = -Wall -Wextra -Werror -std=c++98
SOURCE = Account.cpp \
		 tests.cpp

OBJ = $(SOURCE:.cpp=.o)


all : $(NAME)

$(NAME): $(OBJ)

%.o: %.cpp 
	$(CC) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJ)
	$(CC) $(CFLAG) $(OBJ) -o $(NAME)

clean :
	rm -f $(OBJ)

re : fclean all

fclean : clean
	rm -f $(NAME)

.PHONY : clean