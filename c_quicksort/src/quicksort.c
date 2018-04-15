#include <stdio.h>
#include <stdlib.h>
#include "quicksort.h"
#include "utils.h"

void quicksort(uint64_t *unordered_list, uint64_t low, uint64_t high){

    int p = 0;
    int i, j = 0;

    if(low < high){
        p = low;
        i = low;
        j = high;

        while(i < j){
            while(unordered_list[i] <= unordered_list[p] && i < high){
                i++;
            }

            while(unordered_list[j] > unordered_list[p]){
                j--;
            }

            if (i < j) {
                swap(&unordered_list[j], &unordered_list[i]);
            }
        }

        swap(&unordered_list[j], &unordered_list[p]);

        quicksort(unordered_list, low, j-1);
        quicksort(unordered_list, j+1, high);
    }
}
