CC := gcc -Wall -Werror -Wextra
CC1 := ${CC}
LFLAGS := -lcheck -lm -lpthread
BROWSER := open
ifeq ($(shell uname -s), Linux)
	LFLAGS := ${LFLAGS} -lsubunit
	BROWSER := firefox
endif
SRC := $(wildcard s21_*.c)
OBJ := $(patsubst %.c, %.o, ${SRC})

TEST_SRC := $(wildcard tests/s21_*.c)
TESTS_ARGS := $(patsubst tests/s21_%.c, ../s21_%.c, ${TEST_SRC})
VM ?= CK_ENV
SM ?= 0
ifneq ($(SM), 0)
	TESTS_ARGS := ${TESTS_ARGS} -D SILENT_MODE
endif
TT ?= all

all: s21_math.a

s21_math.o:
	$(CC1) -c ${SRC} 

s21_math.a: s21_math.o
	ar rcs s21_math.a ${OBJ}
	ranlib s21_math.a
	rm *.o

test: s21_math.a
	cd ./tests/build && $(CC) -c ${TESTS_ARGS} && $(CC1) ../my_test.c *.o ../../$^ ${LFLAGS} -D TT="${TT}" -D VM=${VM} -o test
	./tests/build/test
	cd ./tests/build && rm -rf *.o
	
gcov_report: add_coverage clear test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	$(BROWSER) report/index.html
	
add_coverage:
	$(eval CC1 += --coverage)

clear:
	cd tests/build && rm -rf *.o
	rm -rf *.o
	rm -rf s21_math.a
	rm  -rf ./tests/build/test
	cd tests/build && rm -rf *.gc*
	rm -rf *.gc*
	rm -rf report
	rm -rf test.info