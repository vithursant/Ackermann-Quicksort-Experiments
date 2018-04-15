# !/usr/bin/env python
# -*- coding: utf-8 -*-

import time

def ackermann(m, n):
    # Ackermann
    if m == 0:
        ans = n + 1
    elif n == 0:
        # Ackermann
        ans = ackermann(m - 1, 1)
    else:
        # Ackermann (x > 0, y > 0)
        ans = ackermann(m - 1, ackermann(m, n - 1))

    return ans

if __name__ == '__main__':
    m = [1, 2, 3]
    n = 6
    n_trials = 10

    for i in range(len(m)):
        elapsed_times = []
        print("**********************************************************\n")
        print("Ackermann({},{})\n".format(m[i], n))
        for j in range(n_trials):
            start = time.time()
            ans = ackermann(m[i], n)
            end = time.time()
            elapsed = end - start
            print("Trial {} -> \tElapsed: {} seconds".format(j+1, elapsed))

            elapsed_times.append(elapsed)

        print("\n")
        print("Average Elapsed: {} seconds".format( sum(elapsed_times)/n_trials))
        print("Ackermann({},{}) = {}\n".format(m[i], n, ans))
