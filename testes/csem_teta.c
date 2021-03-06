#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include "../include/support.h"
#include "../include/cthread.h"
#include <stdio.h>


#define   CHAIRS 5

time_t end_time;

csem_t customers;
csem_t mutex;
csem_t barbers;
int    waiting = 0;

void sleepao() {
     int i = 0;
 
     i = rand()%5 + 1;
     for (; i<0; i--) cyield();
     return;
}

void cut_hair(void)
{
    cyield(); cyield(); cyield(); cyield;
    return;
}

void* barber(void* arg)
{
   while(time(NULL)<end_time || waiting > 0) {
     cwait(&customers);
     cwait(&mutex);
     waiting = waiting - 1;
     printf("Barbeiro trabalhando, %d clientes esperam!! \n",waiting);
     csignal(&mutex);
     cut_hair();
     csignal(&barbers);
  }
  return;
}

void* customer(void* arg)
{   
   while(time(NULL) < end_time) {
      cwait(&mutex);
      //printf("fdp do cwait do mutex\n");
      if (waiting < CHAIRS) {
         waiting = waiting + 1;
         printf(" ---> Cliente chegando. Há %d clientes esperando.\n", waiting);
         csignal(&customers);
         csignal(&mutex);
         cwait(&barbers);
      } else {
        printf("  ***Cliente indo embora. Não há mais cadeiras.\n");
        csignal(&mutex);
        //printf("fdp do csignal do mutex\n");
      }
      sleepao();
    }
    return;
}

int main(int argc, char **argv)
{
    int tidBarber, tidCustomer;

    end_time=time(NULL)+10;  /*Barbearia fica aberta 120 s */
    srand((unsigned)time(NULL));

    csem_init(&customers, 0);
    csem_init(&barbers, 1);
    csem_init(&mutex, 1);

    tidBarber = ccreate (barber, (void *) NULL, 0);
    if (tidBarber < 0 )
       perror("Erro na criação do Barbeiro...\n");

    tidCustomer = ccreate (customer, (void *) NULL, 0);
    if (tidCustomer < 0 )
       perror("Erro na criação do gerador de clientes...\n");

    cjoin(tidBarber);
    cjoin(tidCustomer);

    exit(0);
}



/*csem_t customers;
csem_t mutex;
csem_t barbers;

void* barber(){
    printf("Eu sou a thread 'Barber'");

}






int main(int argc, char **argv){
    int tidBarber, tidCustomer;
    
    printf("A criacao da fila retornou %d\n", csem_init(&barbers, 1)); 
    printf("Eu sou o semaforo do barbeiro, com o count = %d\n", barbers.count);
    
    tidBarber = ccreate (barber, (void *) NULL, 0);
    if (tidBarber < 0){
        printf("Erro na criacao do barbeiro");
    }
}*/
