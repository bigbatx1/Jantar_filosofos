#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


pthread_t filosofos[5];
pthread_mutex_t mutex_garfo[5];
int estado[5];
int id[5];





void pega(int *filo){

   if(estado[*filo +1] !=1 && estado[*filo-1] !=1){
    pthread_mutex_lock(&(mutex_garfo[*filo]));
    if(*filo<4){
        pthread_mutex_lock(&(mutex_garfo[*filo+1]));
         estado[*filo]=1;
    }
    else{
        pthread_mutex_lock(&(mutex_garfo[0]));
         estado[*filo]=1;
         }
   }
   }



void larga(int *filo){

     pthread_mutex_unlock(&(mutex_garfo[*filo]));
    if(*filo<4){
        pthread_mutex_unlock(&(mutex_garfo[*filo+1]));
        estado[*filo]=0;
    }
    else{
        pthread_mutex_unlock(&(mutex_garfo[0]));
        estado[*filo]=0;
        }
        printf("filosofo %d acabou de comer\n",*filo);
        
}

void *jantar(void *var){
    int *filo = (int *)(var);
    while(1){
        printf("filosofo %d esta pensando \n",*filo);
        sleep(5);
        pega(filo);
        printf("filosofo %d esta comendo\n",*filo);
        sleep(5);
        larga(filo);
    }
}

int main()
{
   for(int i = 0;i<5;i++){
    pthread_mutex_init(&(mutex_garfo[i]),NULL);
   }
    for(int j=0;j<5;j++){
        id[j]=j;
        pthread_create(&filosofos[j],NULL,&jantar,(void*)&id[j]);
    }
    while(1){

    }
    return 0;
}
