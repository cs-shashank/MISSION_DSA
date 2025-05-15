#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'acmTeam' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts STRING_ARRAY topic as parameter.
#

def acmTeam(topic):
    # Write your code here
    n = len(topic)
    m = len(topic[0])
    maxt = 0
    c = 0
    for i in range(n):
        for j in range(i + 1, n):
            t = bin(int(topic[i], 2) | int(topic[j], 2)).count('1')
            
            if t > maxt:
                maxt= t
                c = 1
            elif t== maxt:
                c += 1
    
    return maxt, c

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    m = int(first_multiple_input[1])

    topic = []

    for _ in range(n):
        topic_item = input()
        topic.append(topic_item)

    result = acmTeam(topic)

    fptr.write('\n'.join(map(str, result)))
    fptr.write('\n')

    fptr.close()
