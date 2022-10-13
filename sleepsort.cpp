#include <cstdio>
#include <unistd.h>
#include <cstdlib>

pid_t engage(unsigned int i) {
    pid_t pid = fork();

    if (pid == 0) {
        usleep(1000 * i);
        printf("%i\n", i);
    }
    return pid;
}

void sleepSort(unsigned int* A, unsigned int n) {
    int status;
    pid_t* pids = (pid_t *)malloc(n * sizeof(pid_t));
    pid_t pid;

    for (int i = 0; i < n; i++) {
        pid = engage(A[i]);
        if (pid == 0) {
            break;
        }
        pids[i] = pid;
    }

    if (pid == 0) {
        return;
    }

    for (int i = 0; i < n; i++) {
        waitpid(pids[i], &status, 0);
    }
}

int main() {
    unsigned int A[] = {5, 9, 2, 1, 0, 82, 17, 23, 12};
    int n = 9;

    sleepSort(A, n);

    return 0;
}
