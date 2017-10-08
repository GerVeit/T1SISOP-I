/**
** Teste da função ccreate
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/support.h"
#include "../include/cthread.h"

void* func0(void *arg) {
	printf("Eu sou a thread ID0 imprimindo %d\n", *((int *)arg));

}

int main(int argc, char *argv[]) {

	int id0;
	int i;


	id0 = ccreate(func0, (void *)&i, 0);
	printf("Eu sou a thread de TID: %d\n", id0);
	

	printf("Eu sou a main após a criação de threads\n");

	return 0;
}
