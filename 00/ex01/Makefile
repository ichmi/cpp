NAME	= phonebook

CC		= clang++
FLAGS	= -Wall -Werror -Wextra -std=c++98 -pedantic

SRCS	= main.cpp Contact.cpp PhoneBook.cpp utils.cpp
OBJSDIR	= obj
OBJS	= $(addprefix ${OBJSDIR}/, ${SRCS:.cpp=.o})

all: ${NAME}
.PHONY = all

${NAME}: ${OBJSDIR} ${OBJS}
	${CC} ${FLAGS} ${OBJS} -o $@

${OBJSDIR}:
	mkdir -p $@

${OBJS}: | ${OBJSDIR}

${OBJSDIR}/%.o: %.cpp
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJSDIR}
.PHONY += clean

fclean: clean
	rm -f ${NAME}
.PHONY += fclean

re: fclean all
.PHONY += re


# Valgrind setup
VOPTIONS	= --show-leak-kinds=all --leak-check=full -q
VOPTIONS	+= --trace-children=yes --track-fds=yes --track-origins=yes

v: ${NAME}
	valgrind ${VOPTIONS} ./$^ ${args}
.PHONY += v


# Formatter and Static analyser setup
FORMAT		= Google
TDOPTIONS	= --checks=cppcoreguidelines-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-pro-bounds-constant-array-index,-cppcoreguidelines-avoid-magic-numbers,-cppcoreguidelines-avoid-c-arrays,-cppcoreguidelines-pro-bounds-array-to-pointer-decay
TDOPTIONS	+= --format-style=file

tidy:
	rm -rf .clang-tidy
	clang-tidy ${TDOPTIONS} --dump-config > .clang-tidy

FMTOPTIONS	= --style="{BasedOnStyle: ${FORMAT}, IndentWidth: 4}"
format:
	clang-format ${FMTOPTIONS} --dump-config > .clang-format

analyser: tidy format
.PHONY	+= analyser


# Test setup
TFLAGS		= -Wall -Werror -Wextra -pedantic
TSRCS		= main_test.cpp Contact.cpp PhoneBook.cpp utils.cpp
TOBJSDIR	= test_obj
TOBJS		= $(addprefix ${TOBJSDIR}/, ${TSRCS:.cpp=.o})
TURL		= https://raw.githubusercontent.com/doctest/doctest/master/doctest/doctest.h
t: doctest.h ${TOBJS}
	@${CC} ${TFLAGS} ${TOBJS} -o test.out; ./test.out
	@rm -rf ${TOBJSDIR} test.out

doctest.h:
	wget ${TURL}

${TOBJS}: | ${TOBJSDIR}

${TOBJSDIR}:
	@rm -rf ${TOBJSDIR}
	mkdir -p $@

${TOBJSDIR}/%.o: %.cpp
	${CC} ${TFLAGS} -c $< -o $@
