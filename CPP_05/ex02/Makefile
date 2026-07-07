NAME = AForm

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 

INCLUDE_DIRS = \
				./include/

INCLUDE = ${addprefix -I, ${INCLUDE_DIRS}}

SRC = \
				./src/

OBJ = ${patsubst ./src/%.cpp,./obj/%.o,${SRC}}

all: ${NAME}

${NAME}: ${OBJ}
	${CXX} ${OBJ} -o $@

./obj/%.o: ./src/%.cpp | obj_dir
	${CXX} ${CXXFLAGS} ${INCLUDE} -c $< -o $@ 

./obj_dir/:
	@mkdir -p obj

clean:
	rm -rf obj

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re