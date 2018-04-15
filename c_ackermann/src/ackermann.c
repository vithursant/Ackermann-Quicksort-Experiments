#include <stdio.h>
#include <stdlib.h>

uint64_t ackermann(uint64_t i, uint64_t j)
{
    uint64_t ans;

    if(i == 0) {
        ans = j + 1;
    } else if(j == 0) {
        ans = ackermann(i - 1, 1);
    } else {
        ans = ackermann(i - 1, ackermann(i, j - 1));
    }

    return ans;
}
