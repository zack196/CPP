NAME=executeForms

CFLAG= -Wall -Wextra -Werror -Wshadow -std=c++98

CC=c++

INCLUDE= Bureaucrat.hpp AForm.hpp ShrubberyCreationForm.hpp \
		 RobotomyRequestForm.hpp PresidentialPardonForm.hpp

SRC= main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
	 RobotomyRequestForm.cpp PresidentialPardonForm.cpp

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
	rm -f *_shrubbery


.PHONY : clean