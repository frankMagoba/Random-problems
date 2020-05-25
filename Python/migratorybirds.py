#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the migratoryBirds function below.


def migratoryBirds(arr):
    typecount = [0 for i in range(5)]
    for i in arr:
        typecount[i-1] += 1
    max_count = max(typecount)
    for i in range(5):
        if typecount[i] == max_count:
            return i+1


if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    arr_count = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    result = migratoryBirds(arr)

    fptr.write(str(result) + '\n')

    fptr.close()
