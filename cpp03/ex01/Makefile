NAME=claptrap
CC=c++
CFLAG=-Wall -Wextra -Werror -std=c++98

SRCS= ClapTrap.cpp   main.cpp 

OBJS=$(SRCS:.cpp=.o)

$(OBJS) : ClapTrap.hpp

all : $(NAME)

%.o : %.cpp
	$(CC) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

run : all clean
	./$(NAME)

PHONY : clean