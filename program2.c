#include<stdlib.h>
#include <stdio.h>
#include <omp.h>

int main(int argc, char* argv[]) {
    int n, i;

    if (argc != 2) {
        printf("Usage: %s <number_of_iterations>\n", argv[0]);
        return 1;
    }

    n = atoi(argv[1]);  // Number of iterations

    printf("Total Iterations: %d\n", n);

    #pragma omp parallel for schedule(static,2)
    for (i = 0; i < n; i++) {
        int tid = omp_get_thread_num();
        printf("Thread %d executes iteration %d\n", tid, i);
    }

    return 0;
}
