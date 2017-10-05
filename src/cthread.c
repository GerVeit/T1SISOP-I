#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ucontext.h>

#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/cthread.h"

//variaveis universales

int firstExec = 1;
int nroTID = 1;
FILA2 aptos;
TCB_t *exec;

void* func1(void* arg){

	printf("Hello\n");
}

void* func2(void* arg){

	printf("Hola\n");

}


int ccreate (void *(*start) (void*), void *arg, 0){
	
	//primeira execucao cria contexto da main

	if( firstExec == 1){
		TCB_t *main;
		main = malloc(sizeof(Thread));

		getcontext(&(main->context));
		main->context.uc_link = &(endThread->context);
		main->context.uc_stack.ss_sp = (main->stack);
		main->context.uc_stack.ss_size = sizeof(main->stack);
		
		main->tid = 0;
		main->state = PROCST_EXEC;
		main->prio = -1 //nao tem prioridade
		
		//cria contexto da thread que testa o fim de execucao de todas as threads

		TCB_t *endThread;
		endThread = malloc(sizeof(Thread));

		getcontext(&(endThread->context));
		endThread->context.uc_link = &(main->context);
		endThread->context.uc_stack.ss_sp = endThread->stack;
		endThread->context.uc_stack.ss_size = sizeof(endThread->stack);
 
		makecontext(&(endThread->context), (void (*) (void))fimThread, 0);
		
		//criando fila de aptos

		CreateFila2(&aptos);
		
		//setando variavel que indica qual thread esta executando

		exec = main;
		firstExec = 0;
	}
	
	//criando nova thread

	TCB_t *novaThread;
	novaThread = malloc(sizeof(Thread));
		
	getcontext(&(novaThread->context));
	novaThread->context.uc_link = &(endThread->context);
	novaThread->context.uc_stack.ss_sp = nova_Thread->stack;
	novaThread->context.stack.ss_size = sizeof(novaThread->stack);	
	makecontext(&(novaThread->context), (void (*) (void))start, 0);

	novaThread->prio = 0;
	novaThread->tid = nroTID;
	novaThread->state = PROCST_APTO;

	nroTID++;
	
	//Inserindo na Fila de Aptos;

	if (InsertByPrio(aptos, &(novaThread) == 0)
		printf("Nova Thread inserida na fila de Aptos\n");
		
	else
		printf("Erro na insercao na fila de Aptos\n");
	
	return nroTID;


}


int main(int argc, char **argv){

	int tidFunc1 = 0, tidFunc2 = 0;	
	
	tidFunc1 = ccreate(func1, (void *) NULL);
	if(tidFunc1 < 0)
		printf("Erro na execucao para escrever oi em ingles!!\n");

	tidFunc2 = ccreate(func2, (void *) NULL);
	printf("meupaiteama\n");
	if(tidFunc2 < 0)
		printf("Erro na execucao para escrever oi em espanhol!!\n");	
	

	return 0;
}
