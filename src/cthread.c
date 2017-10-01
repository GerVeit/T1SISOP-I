#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ucontext.h>

#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/cthread.h"

//variaveis universales

int firstExec = 0;


void* func1(void* arg){

	printf("Hello\n");
}

void* func2(void* arg){

	printf("Hola\n");

}


int ccreate (void *(*newThreadBegin) (void*), void *arg, int zero){

	//cria contexto de execucao da thread main

	if (firstExec == 0){
		
		newThreadBegin((void *) NULL);		


	}

	newThreadBegin((void *) NULL);
	firstExec = 1;

	//cria a thread


}


int main(int argc, char **argv){

	int tidFunc1 = 0, tidFunc2 = 0;	
	
	tidFunc1 = ccreate(func1, (void *) NULL, 0);
	if(tidFunc1 < 0)
		printf("Erro na execucao para escrever oi em ingles!!\n");

	tidFunc2 = ccreate(func2, (void *) NULL, 0);
	if(tidFunc2 < 0)
		printf("Erro na execucao para escrever oi em espanhol!!\n");	
	

	return 0;
}
