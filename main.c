#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


pthread_t filosofos[5];
pthread_mutex_t garfo[5];
int id[5];



void *jantar(void *var){
    int *filo = (int *)(var);
    while(true){
        printf("filosofo %d esta pensando \n",*filo);
        sleep(5000);
        pega(filo);
        printf("filosofo %d esta comendo\n",*filo);
        sleep(5000);
        larga(filo);
    }
}

void pega(int *filo){
    pthread_mutex_lock(&(mutex_garfo[*filo])));
    if(*filo<4){
        pthread_mutex_lock(&(mutex_garfo[*filo+1]));
    }
    else
        pthread_mutex_lock(&(mutex_garfo[0]));
}


void larga(int *filo){
     pthread_mutex_unlock(&(mutex_garfo[*filo])));
    if(*filo<4){
        pthread_mutex_unlock(&(mutex_garfo[*filo+1]));
    }
    else
        pthread_mutex_unlock(&(mutex_garfo[0]));
        printf("filosofo %d acabou de comer\n",*filo);
}

int main()
{
   for(int i = 0;i<5;i++){
    pthread_mutex_init(&(mutex_garfo[i]),NULL);
   }
    for(int j=0;j<5;j++){
        id[j]=j;
    }
    while(true){

    }
    return 0;
}
