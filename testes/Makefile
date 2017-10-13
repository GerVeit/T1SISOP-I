
CC=gcc
LIB_DIR=../lib
FLAGS=-m32 -o
LIB=-lcthread

all: ccreate cjoin cyield

ccreate:
	$(CC) $(FLAGS) ccreate ccreate.c -L$(LIB_DIR) $(LIB)

cjoin:
	$(CC) $(FLAGS) cjoin cjoin.c -L$(LIB_DIR) $(LIB)

cyield:
	$(CC) $(FLAGS) cyield cyield.c -L$(LIB_DIR) $(LIB)

clean:
	find -type f ! -name '*.c' ! -name 'Makefile' -delete
