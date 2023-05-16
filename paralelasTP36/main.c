#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
 
#define NUMBERTHREADS 8
#define LENTHARRAY 16
int total = 0;
int vector[LENTHARRAY] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
struct numbers{
    int first;
    int last;
};

void sumar(void *received_struct) {
    struct numbers *numbersObject = (struct numbers*) received_struct;
    for(int i =  numbersObject->first; i < numbersObject->last; i++) {

        printf("vector %d \n",vector[i]);
        total = total + vector[i];
    }
    pthread_exit(NULL);
}


int main(void) {
    
    for(int i = 0; i < LENTHARRAY; i++) {
        //vector[i] = rand();
    }
    
    int numbersForThread = LENTHARRAY/NUMBERTHREADS;
    struct numbers numbersObject[NUMBERTHREADS];
    pthread_t hilos[NUMBERTHREADS];
    int contador = 0;
    
    for(int i = 0; i < NUMBERTHREADS; i++) {
        numbersObject[i].first = contador;
        contador = contador + numbersForThread;
        numbersObject[i].last = contador;
        pthread_create(&hilos[i], NULL,(void *) sumar, (void *) &numbersObject[i]);
    }

    for(int i = 0; i < NUMBERTHREADS; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("total %d", total);
  return 0;
}

