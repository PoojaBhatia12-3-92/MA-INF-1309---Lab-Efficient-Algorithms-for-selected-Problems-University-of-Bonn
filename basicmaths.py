import sys
from itertools import combinations
import math
n=sys.stdin.readline()
n=int(n)
matrix=[]
for i in range(0,n):
    matrix.append(list(map(int,sys.stdin.readline().split())))


def check(U,V,W):
    fac=[]
    val=[]
    b=min(V,110)
    for i in range(-(V+1), b+1):
        if i!=0 and V % i == 0:
            fac.append(i)
    if not fac or U<0 or V<0 or W<0:
        print ('empty set')

    else:
        for i in range(len(fac)):
            if((fac[i]**3)-(U*(fac[i]**2))+int(((U**2)-W)/2)* fac[i] - V==0):
                val.append(fac[i])
        if len(val)<3:
            print ('empty set')

        else:
            print(val[0],val[1],val[2])

for i in range(0,n):
    U=matrix[i][0]
    V=matrix[i][1]
    W=matrix[i][2]
    check(U,V,W)
