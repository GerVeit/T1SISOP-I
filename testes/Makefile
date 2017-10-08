
CC=gcc
LIB_DIR=../lib
FLAGS=-m32 -o
LIB=-lcthread

all: ccreate

ccreate:
	$(CC) $(FLAGS) ccreate ccreate.c -L$(LIB_DIR) $(LIB)

clean:
	find -type f ! -name '*.c' ! -name 'Makefile' -delete
