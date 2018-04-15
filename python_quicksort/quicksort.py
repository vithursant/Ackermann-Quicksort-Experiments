# !/usr/bin/env python
# -*- coding: utf-8 -*-

import time
import random
random.seed(a=1)

def partition(unordered_list, low, high):
    pivot = unordered_list[high];
    i = low-1;
    j = low;

    for j in range(low, high):
        if (unordered_list[j] <= pivot):
            i += 1
            unordered_list[i], unordered_list[j] = unordered_list[j], unordered_list[i]
    unordered_list[i+1], unordered_list[high] = unordered_list[high], unordered_list[i+1]

    return i+1

def quicksort(unordered_list, low, high):
    if (low < high):
        q = partition(unordered_list, low, high)
        quicksort(unordered_list, low, q-1)
        quicksort(unordered_list, q + 1, high)
    return unordered_list

if __name__ == '__main__':
    sizes = [100, 1000, 10000, 100000]
    n_trials = 10

    for idx, size in enumerate(sizes):
        elapsed_times = []
        print("**********************************************************\n")
        print("Unordered List:")
        for i in range(n_trials):
            unordered_list = random.sample(range(1000000), size)
            # if i == 0:
            #     print(unordered_list)
            #     print("\n")
            start = time.time()
            quicksort(unordered_list, 0, len(unordered_list)-1)
            end = time.time()
            elapsed = end - start
            print("Trial {} -> \tElapsed: {} seconds".format(i, elapsed))

            elapsed_times.append(elapsed)

        print("Average execution time: {} seconds".format(sum(elapsed_times)/n_trials))
        print("Size of array: {}\n".format(size))

        # print("Ordered List:")
        # print(unordered_list)
        # print("\n")
