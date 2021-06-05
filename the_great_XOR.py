#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'theGreatXor' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER x as parameter.
#
def decimal_to_binary(x,dec_num):

    if(x > 1):
        decimal_to_binary(x // 2,dec_num);
    dec_num.append(x % 2);
    return dec_num;

def theGreatXor(x):
    dec_num = [];
    dec_num = decimal_to_binary(x,dec_num);
    
    sum_val = 0;
    shift = 0;
    
    for itr in reversed(dec_num):
        if itr == 0:
            sum_val += (1 << shift);
        shift = shift + 1;
    
    return sum_val;

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        x = int(input().strip())

        result = theGreatXor(x)

        fptr.write(str(result) + '\n')

    fptr.close()
