#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h> 

int v = 0;
pthread_mutex_t mutex_t;
pthread_cond_t cond_plus;
pthread_cond_t cond_minus;
bool didPlus;
bool didMinus;

void increment() {
    pthread_mutex_lock(&mutex_t);


    for(int i = 0; i < 1000; i++) {
        v = v + 1;
        didPlus = true;
        printf("%d \n", v);
        didMinus = false;
        pthread_cond_signal(&cond_minus);
        
        while (didPlus == true) {
            pthread_cond_wait(&cond_plus, &mutex_t);
        }
        
    }
    didMinus = false;
    pthread_cond_signal(&cond_minus);
    pthread_mutex_unlock(&mutex_t);
    pthread_exit(NULL);
}

void decrement() {
    pthread_mutex_lock(&mutex_t);
    
    for(int i = 0; i < 1000; i++) {
        v = v - 1;
        didMinus = true;
        printf("%d \n", v);
        didPlus = false;
        pthread_cond_signal(&cond_plus);
        
        while (didMinus == true) {
            pthread_cond_wait(&cond_minus, &mutex_t);
        }

    }
    didPlus = false;
    pthread_cond_signal(&cond_plus);
    pthread_mutex_unlock(&mutex_t);
    pthread_exit(NULL);
}

int main(void) {
    pthread_mutex_init(&mutex_t, NULL);
    pthread_cond_init(&cond_plus, NULL);
    pthread_cond_init(&cond_minus, NULL);
    pthread_t hilosSumadores[10];
    pthread_t hilosRestadores[10];
    

    for(int i = 0; i < 10; i++) {
        pthread_create(&hilosSumadores[i], NULL,(void *) increment, NULL);
        pthread_create(&hilosRestadores[i], NULL,(void *) decrement, NULL);
    
        pthread_join(hilosSumadores[i], NULL);
        pthread_join(hilosRestadores[i], NULL);
    }
    printf("%d \n", v);
  return 0;
}

