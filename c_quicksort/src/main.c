#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "quicksort.h"
#include "utils.h"
#include "gen_random.h"

int main(int argc, const char * argv[]){
    uint64_t sizes[] = {100, 1000, 10000, 100000};
    double sum_elapsed_times = 0;
    double elapsed = 0;
    int num_trials = 10;

    for(int i = 0; i < 4; i++){
        uint64_t *test_list = malloc (sizeof (uint64_t) * sizes[i]);
        printf("**********************************************************\n\n");
        printf("Unordered List:\n");
        for(int j = 0; j < num_trials; j++){
            gen_random(test_list, sizes[i]);
            // if (j == 0){
            //     print_list(test_list, sizes[i]);
            //     printf("\n\n");
            // }
            clock_t start = clock();
            quicksort(test_list, 0, sizes[i]);
            clock_t end = clock();
            elapsed = end - start;
            printf("Trial %d -> \tElapsed: %f seconds\n", j, elapsed / CLOCKS_PER_SEC);

            sum_elapsed_times += elapsed / CLOCKS_PER_SEC;
        }
        printf("\n");
        printf("Average Elapsed: %f seconds\n", sum_elapsed_times / num_trials);
        printf("Size of array: %llu\n\n", sizes[i]);

        // printf("Ordered List:\n");
        // print_list(test_list, sizes[i]);
        // printf("\n\n");

        free(test_list);
    }
    return 0;
}
