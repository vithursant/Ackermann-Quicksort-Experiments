#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gen_random.h"

uint64_t * gen_random(uint64_t *test_list, uint64_t size){
    srand(1);
    for (int i=0; i<size; i++){
        test_list[i] = rand() % 1000000 + 1;
    }

    return test_list;
}
