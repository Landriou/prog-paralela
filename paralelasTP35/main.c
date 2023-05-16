#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#define NTHREADS 4
int contador=0;

    pthread_mutex_t mutex_t;
void *hilo(void *arg) {
        pthread_mutex_lock(&mutex_t);
int i;
i = (int) arg;
contador = contador + i;
printf("Hilo %u, contador = %u\n",pthread_self(),contador);
        pthread_mutex_unlock(&mutex_t);
pthread_exit(0);
}

int main() {
int i;
        pthread_mutex_init(&mutex_t, NULL);
pthread_t thread[NTHREADS]; //vector para definir los hilos
for (i=0;i<NTHREADS;i++) {
pthread_create(&thread[i], NULL, hilo, (void *)i);
pthread_join(thread[i],NULL);
}
printf("Hilo principal, contador = %d\n",contador);
pthread_exit (0);
}
