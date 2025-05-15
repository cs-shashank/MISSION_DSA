#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'solve' function below.
#
# The function is expected to return a STRING.
# The function accepts INTEGER n as parameter.
#
from collections import deque
def solve(n):
    # Write your code here
    queue=deque()
    v=set()
    queue.append("9")
    while queue:
        cur=queue.popleft()
        cur_num=int(cur)
        if cur_num%n==0:
            return cur
        next1=cur+"0"
        next2=cur+"9"
        if cur_num % n not in v:
            v.add(cur_num % n)
            queue.append(next1)
            queue.append(next2)

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        result = solve(n)

        fptr.write(result + '\n')

    fptr.close()
