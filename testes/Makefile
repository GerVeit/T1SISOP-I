
CC=gcc
LIB_DIR=../lib
FLAGS=-m32 -o
LIB=-lcthread

all: ccreate cjoinHard cjoinTeta cyieldHard cyieldTeta cidentify csem_teta csemInit

ccreate:
	$(CC) $(FLAGS) ccreate ccreate.c -L$(LIB_DIR) $(LIB)

cjoinHard:
	$(CC) $(FLAGS) cjoinHard cjoinHard.c -L$(LIB_DIR) $(LIB)

cjoinTeta:
	$(CC) $(FLAGS) cjoinTeta cjoinTeta.c -L$(LIB_DIR) $(LIB)

cyieldHard:
	$(CC) $(FLAGS) cyieldHard cyieldHard.c -L$(LIB_DIR) $(LIB)

cyieldTeta:
	$(CC) $(FLAGS) cyieldTeta cyieldTeta.c -L$(LIB_DIR) $(LIB)

cidentify:
	$(CC) $(FLAGS) cidentify cidentify.c -L$(LIB_DIR) $(LIB)

csem_teta:
	$(CC) $(FLAGS) csem_teta csem_teta.c -L$(LIB_DIR) $(LIB)

csemInit:
	$(CC) $(FLAGS) csemInit csemInit.c -L$(LIB_DIR) $(LIB)

clean:
	find -type f ! -name '*.c' ! -name 'Makefile' -delete
