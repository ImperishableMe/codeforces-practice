import io
import os
import sys
from io import BytesIO
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

t = int(input())
for _ in range(t) :
    a,b = map(int,input().split())
    if a % b == 0 : print('0')
    else :
        print(b - a % b)