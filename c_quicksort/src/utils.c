#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"

void swap(uint64_t *a, uint64_t *b){
   uint64_t t;
   t  = *b;
   *b = *a;
   *a = t;
}

void print_list(uint64_t test_list[], uint64_t size){
    for (int i=0; i<size; i++){
        printf("%llu", test_list[i]);
        if(i<size-1){
            printf(",");
        }
    }
}
