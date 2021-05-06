
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static int getValue(void) {
    static int v = 0;
    return v++;
}

static void *routine(void *arg) {
    const int cnt = (int)arg;
    for (int i = 0; i < cnt; ++i) {
        getValue();
    }
    return NULL;
}

int main(int argc, char **argv) {
    for (int i = 0; i < 1; ++i) {
        pthread_t tid;
        pthread_create(&tid, NULL, routine, (void*)10000);
    }
    usleep(1e5);
    printf("%d\n", getValue());
	return 0;
}
