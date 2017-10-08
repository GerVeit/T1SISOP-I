#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ucontext.h>

#include "../include/support.h"
#include "../include/cdata.h"
#include "../include/cthread.h"

int oi()
{
	TCB_t *thread1 = NULL;

	return 0;

}
/*
//variaveis universales


int firstExec = 1;
int nroTID = 1;
int isMain = 1;

FILA2 aptos;

TCB_t *exec;


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


int ccreate (void *(*start) (void*), void *arg, int zero){
	
	//primeira execucao cria contexto da main

	if(firstExec){

		TCB_t *main;
		main = malloc(sizeof(TCB_t));

		main->tid = 0;
		main->state = PROCST_EXEC;

		//criando fila de aptos

		CreateFila2(&aptos);
		
		//setando variavel que indica qual thread esta executando

		exec = main;
		
		isMain = 1;	//variavel que indica que a main esta executando		
		
		firstExec = 0;	//variavel que indica o fim da primeira execucao
	}
	
	//criando nova thread

	TCB_t *novaThread;
	novaThread = malloc(sizeof(TCB_t));
		
	getcontext(&(novaThread->context));

	novaThread->context.uc_link = &(endThread->context);
	novaThread->context.uc_stack.ss_sp = (novaThread->stack);
	novaThread->context.uc_stack.ss_size = sizeof(novaThread->stack);
	
	makecontext(&(novaThread->context), (void (*) (void))start, 0);

	novaThread->prio = 0;
	novaThread->tid = nroTID;
	novaThread->state = PROCST_APTO;

	nroTID++;
	
	//Inserindo na Fila de Aptos;

	if (InsertByPrio(&aptos, (&(novaThread) == 0))
		printf("Nova Thread inserida na fila de Aptos\n");
	else
		printf("Erro na insercao na fila de Aptos\n");

	dispatcher();
	
	return nroTID;

}


int main(int argc, char **argv){

	int tidFunc1 = 0, tidFunc2 = 0;	
	
	tidFunc1 = ccreate(func1, (void *) NULL, 0);

	if(tidFunc1 < 0)
		printf("Erro na execucao para escrever oi em ingles!!\n");

	tidFunc2 = ccreate(func2, (void *) NULL, 0);
	//printf("nmeupaiteama\n");

	if(tidFunc2 < 0)
		printf("Erro na execucao para escrever oi em espanhol!!\n");	
	


	return 0;
}
*/
