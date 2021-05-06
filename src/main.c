
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

static pthread_mutex_t s_mux = PTHREAD_MUTEX_INITIALIZER;

static int getValue(void) {
    pthread_mutex_lock(&s_mux);
    static int v = 0;
    int rv = v++;
    pthread_mutex_unlock(&s_mux);
    return rv;
}

static void *routine(void *arg) {
    const int cnt = (int)arg;
    for (int i = 0; i < cnt; ++i) {
        getValue();
    }
    return NULL;
}

int main(int argc, char **argv) {
    for (int i = 0; i < 5; ++i) {
        pthread_t tid;
        pthread_create(&tid, NULL, routine, (void*)10000);
    }
    usleep(1e5);
    printf("%d\n", getValue());
	return 0;
}
