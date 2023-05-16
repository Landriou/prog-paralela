#include <stdio.h>
#include <pthread.h>

int total = 0;
struct numbers{
    int first;
    int second;
};
void multitiplicar(void *received_struct) {
    struct numbers *numbersObject = (struct numbers*) received_struct;
    total = total + numbersObject->first * numbersObject->second;
    pthread_exit(NULL);
}


int main(void) {
    int vector1[3] = {1,2,3};
    int vector2[3] = {1,2,3}; 
    struct numbers numbersObject[3];
    pthread_t hilos[3];
    for(int i = 0; i < 3; i++) {
        numbersObject[i].first = vector1[i];
        numbersObject[i].second = vector2[i];
        pthread_create(&hilos[i], NULL,(void *) multitiplicar, (void *) &numbersObject[i]);
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(hilos[i], NULL);
    }

    printf("total %d", total);
  return 0;
}

