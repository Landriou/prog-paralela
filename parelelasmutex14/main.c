#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int prueba = 0;

    pthread_mutex_t mutex_t;
void increment() {
    pthread_mutex_lock(&mutex_t);
    printf("\n Job 1 has started\n");
          for(int i = 0; i < 15; i++) {
           prueba = prueba + 1;
          printf(" %d ", prueba);
          }
    
    pthread_mutex_unlock(&mutex_t);
    pthread_exit(NULL);
}

void decrement() {
    pthread_mutex_lock(&mutex_t);
     ocupado = false;
3 pthread_cond_signal(&cond);

    printf("\n Job 2 has started\n");
      for(int i = 0; i < 15; i++) {
           prueba = prueba - 1;
          printf(" %d ", prueba);
          }
    pthread_mutex_unlock(&mutex_t);
    pthread_exit(NULL);
}

int main(void) {
    pthread_t hilos[2];
    pthread_mutex_init(&mutex_t, NULL);
    pthread_create(&hilos[0], NULL,(void *) increment, (void *) &mutex_t);
    pthread_create(&hilos[1], NULL,(void *) decrement, (void *) &mutex_t);
    
    for(int i = 0; i < 2; i++) {
        pthread_join(hilos[i], NULL);
    }
  return 0;
}

