/**
** Teste da função ccreate
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/support.h"
#include "../include/cthread.h"

csem_t sem1;
csem_t sem2;
csem_t sem3;

int main(int argc, char *argv[]) {
	
	int id1, id2, id3;

	id1 = csem_init(&sem1, 1);
	printf("Eu sou o primeiro retorno: %d\n", id1);
	
	id2 = csem_init(&sem1, 2);
	printf("Eu sou o segundo retorno: %d\n", id2);
	
	id3 = csem_init(&sem1, 3);
	printf("Eu sou o terceiro retorno: %d\n", id3);

	return 0;
}
