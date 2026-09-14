NAME = PmergeMe

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp PmergeMe.cpp

OBJS = ${SRC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CXXLAGS} ${OBJS} -o ${NAME}

debug: CXXFLAGS += -DDEBUG
debug: re

clean:
	rm -rf ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

default:
	make re
	./PmergeMe 3 5 9 7 4

symt:
	objdump -tC ${NAME}

.PHONY: all clean fclean re debug default