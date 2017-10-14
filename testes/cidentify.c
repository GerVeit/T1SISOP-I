/**
** Teste da função cidentify
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/support.h"
#include "../include/cthread.h"


int main(int argc, char *argv[]) {
	
	char *nomes = "Geronimo Veit\t260004\nJulia Rittmann\t262512\nVilmar Fonseca\t262519\n";			
	int size = sizeof(nomes);

	int id0;

	id0 = cidentify(nomes, size);
	if(id0 == 0)
		printf("Deve ter aparecido nossos nomes na tela\n");
	else
		printf("Provavelmente nossos nomes nao foram escritos na tela\n");
	
	return 0;
}
