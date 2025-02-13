NAME=fixed

CC=c++

CFLAG=-Wall -Wextra -Werror -std=c++98

SRCS= main.cpp Fixed.cpp

OBJS=$(SRCS:.cpp=.o)

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS) : Fixed.hpp

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

run : all clean
	./$(NAME)

PHONY : clean