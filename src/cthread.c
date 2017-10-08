#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ucontext.h>

#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/cthread.h"


//variaveis universais


int firstExec = 1;
int nroTID = 1;
int isMain = 1;

FILA2 aptos;
FILA2 bloqueados;
FILA2 cjoinQueue;

TCB_t exec;
TCB_t threadMain;

ucontext_t endThread;

/*

//funcoes teste

void* func1(void* arg){

	printf("Hello\n");
}

void* func2(void* arg){

	printf("Hola\n");

}


void dispatcher(){
	
	TCB_t *aux = NULL;

	if (exec != NULL)
		aux = exec;

	if (FirstFila2(&aptos) != 0)
		printf("Fila de aptos vazia\n");

	else{

		exec = GetAtIteratorFila2(&aptos);

		if (exec == NULL)
			printf("Fila de aptos vazia vazia\n");
		else{

			if (FirstFila2(&aptos) == 0)
				if (DeleteAtIteratorFila2(&aptos) == 0)
					printf("Deletado primeiro elemento da fila de aptos\n");
				else
					printf("Erro ao deletar primeiro elemento da fila de apto\n");

			else
				printf("Fila de aptos vazia\n");
		}
	
	exec->state = PROCST_EXEC;
	startTimer();
	
	if (aux != NULL)
		swapcontext(&(aux->context), &(exec->context));	//realiza swap se houver uma thread executando
	else
		setcontext(&(exec->context));		        //realiza set se nao houver nenhuma thread executando
	
	
}
*/

int ccreate (void *(*start) (void*), void *arg, int zero){
	
	//primeira execucao cria contexto da main e inicializa filas

	if(firstExec){

		threadMain.tid = 0;
		threadMain.state = PROCST_EXEC;
		exec = threadMain;

		getcontext(&threadMain.context);		
		
		printf("Sou a main\n");

		//comeca a contar o tempo que main esta com CPU 
		startTimer();

		//criando fila de aptos, bloqueados e das threads que esperam por cjoin
		if(CreateFila2(&aptos) != 0){
			printf("Nao criou a fila de aptos\n");
			return -1;
		}
		
		if(CreateFila2(&bloqueados) != 0){
			printf("Nao criou a fila de bloqueados\n");
			return -1;
		}
		
		if(CreateFila2(&cjoinQueue) != 0){
			printf("Nao criou a fila do cjoin\n");
			return -1;
		}	
		
		firstExec = 0;	//variavel que indica que nao eh mais a primeira execucao
	}
	
	//criando nova thread

	TCB_t *novaThread;
	novaThread = malloc(sizeof(TCB_t));
		
	getcontext(&(novaThread->context));

	novaThread->context.uc_link = &endThread;
	novaThread->context.uc_stack.ss_sp = novaThread->stack;
	novaThread->context.uc_stack.ss_size = sizeof(novaThread->stack);
	
	makecontext(&(novaThread->context), (void (*) (void))start, 1, arg);

	novaThread->prio = zero;
	novaThread->tid = nroTID;
	novaThread->state = PROCST_APTO;

	
	
	//Inserindo na Fila de Aptos;

	if (InsertByPrio(&aptos, &novaThread) == 0)
		printf("Nova Thread inserida na fila de Aptos\n");
	else{
		printf("Erro na insercao na fila de Aptos\n");
		return -1;
	}

	nroTID++;
	
	return novaThread->tid;

}

