#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define NUM_FILOSOFOS 5

#ifdef _WIN32
#include <Windows.h>
void comer(){
    Sleep(((float)rand()/(float)(RAND_MAX)) * 5);
}

void pensar(){
    Sleep(((float)rand()/(float)(RAND_MAX)) * 5);
}
#endif

#ifdef __linux__
#include <unistd.h>
void comer(){
    sleep(((float)rand()/(float)(RAND_MAX)) * 5);
}

void pensar(){
    sleep(((float)rand()/(float)(RAND_MAX)) * 5);
}
#endif

struct Filosofo{
    int id; // Guarda posição do filósofo
    sem_t garfo;
} filosofos[NUM_FILOSOFOS];

void *filosofo(int id){
    printf("Thread %d iniciando...\n", id);
    while(1){
        // Pensar
        printf("Filosofo %d pensando...\n", id);
        pensar();

        // Pegar garfo da esquerda
        printf("Filosofo %d pegando garfo da esquerda...\n", id);
        if(id == 0){
            sem_wait(&((filosofos[NUM_FILOSOFOS]).garfo));
        }else{
            sem_wait(&((filosofos[id - 1]).garfo));
        }

        // Pegar garfo da direita(próprio)
        printf("Filosofo %d pegando garfo da direita...\n", id);
        sem_wait(&((filosofos[id]).garfo));

        // Comer
        comer();

        // Soltar garfos
        printf("Filosofo %d soltandos os garfos...\n", id);
        if(id == 0){
            sem_post(&((filosofos[NUM_FILOSOFOS]).garfo));
        }else{
            sem_post(&((filosofos[id - 1]).garfo));
        }
        sem_post(&((filosofos[id]).garfo));
    }
}

int main(){
    pthread_t threads[NUM_FILOSOFOS];

    // Inicializar o array de filosofos
    for(int i = 0; i < NUM_FILOSOFOS; i++){
        filosofos[i].id = i;
        sem_init(&(filosofos[i].garfo), 0, 1);
    }
    for(int i = 0; i < NUM_FILOSOFOS; i++){
        pthread_create(&(threads[i]), NULL, filosofo, filosofos[i].id);
    }
    printf("Pressione qualquer tecla para parar o jantar...\n");
    getchar();
    for(int i = 0; i < NUM_FILOSOFOS; i++){
        sem_destroy(&(filosofos[i].garfo));
    }
    return 0;
}