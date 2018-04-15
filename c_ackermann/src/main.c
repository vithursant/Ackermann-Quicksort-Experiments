#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ackermann.h"

int main(int argc, const char * argv[]){
    uint64_t m[] = {1, 2, 3};
    uint64_t len_m = sizeof(m) / sizeof(uint64_t);
    uint64_t n = 6;

    uint64_t num_trials = 10;

    for (int i = 0; i < len_m; i++){
        uint64_t answer = 0;
        double elapsed = 0;
        double sum_elapsed_times = 0;

        printf("**********************************************************\n\n");
        printf("Ackerman(%llu, %llu)\n\n", m[i], n);
        for (int j = 0; j < num_trials; j++){
            clock_t start = (double)clock();
            answer = ackermann(m[i],n);
            clock_t end = (double)clock();
            elapsed = end - start;
            printf("Trial %d -> \tElapsed: %.10g seconds\n", j+1, elapsed / (double)CLOCKS_PER_SEC);
            sum_elapsed_times += elapsed / (double)CLOCKS_PER_SEC;
        }
        printf("\n");
        printf("Average Elapsed: %.10g seconds\n", sum_elapsed_times / num_trials);
        printf("Ackerman(%llu, %llu) = %llu\n\n", m[i], n, answer);
    }
    return 0;
}
