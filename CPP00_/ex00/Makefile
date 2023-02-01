# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samantha <samantha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 12:06:01 by sle-huec          #+#    #+#              #
#    Updated: 2022/11/01 13:54:32 by samantha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -g3 -std=c++98

SRC = ./megaphone.cpp

OBJ = $(SRC:%.cpp=%.o)

all: $(NAME)

${NAME}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${NAME}

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

re : fclean
	make all

grind: ${NAME}
		valgrind ./$(NAME) "je teste valgrind"

test: $(NAME)
	./$(NAME) "123 pouet pouet"
	
test1: $(NAME)
	./$(NAME) "Je TEste une chaine AVec DES MAj"
	
test2: $(NAME)
	./$(NAME) "je teste une chaine av_*c des sy_mb+les"

test3: $(NAME)
	./$(NAME) "je" "teste plusieurs" "arg"
	
test4: $(NAME)
	./$(NAME)

.PHONY: clean fclean re grind test
