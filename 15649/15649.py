import sys
from itertools import permutations
input = sys.stdin.readline

N, M = map(int, input().split())
arr = []
for i in range(1,N+1):
    arr.append(i)

nPr = list(permutations(arr, M))
for a in nPr:
    print(' '.join(map(str,a)))