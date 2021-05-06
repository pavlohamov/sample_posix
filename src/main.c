
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static void *routine(void *arg) {
    for (int i = 0; i < 5; ++i) {
        printf("loop %d\n", i);
    }
    return NULL;
}

int main(int argc, char **argv) {
    pthread_t tid;
    pthread_create(&tid, NULL, routine, NULL);
    sleep(10);
	return 0;
}
