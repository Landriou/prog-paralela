#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int prueba = 0;

void increment() {
          for(int i = 0; i < 15; i++) {
           prueba = prueba + 1;
          printf("%d", prueba);
          }
    pthread_exit(NULL);
}

void decrement() {
      for(int i = 0; i < 15; i++) {
           prueba = prueba - 1;
          printf("%d", prueba);
          }
   
    pthread_exit(NULL);
}

int main(void) {
    pthread_t hilos[2];
    pthread_create(&hilos[0], NULL,(void *) increment, NULL);
    pthread_create(&hilos[1], NULL,(void *) decrement, NULL);
    
    for(int i = 0; i < 2; i++) {
        pthread_join(hilos[i], NULL);
    }
  return 0;
}

