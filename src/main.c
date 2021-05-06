
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

static sem_t s_sem;

static void *gpioISR(void *arg) {
    sem_t *pSem = arg;
    for (int i = 0; i < 10; ++i) {
        usleep(5e5);
        sem_post(pSem);
    }
    return NULL;
}

int main(int argc, char **argv) {
    sem_init(&s_sem, 0, 0);
    pthread_t tid;
    pthread_create(&tid, NULL, gpioISR, &s_sem);
    while (1) {
        sem_wait(&s_sem);
        printf("Received\n");
    }
	return 0;
}
