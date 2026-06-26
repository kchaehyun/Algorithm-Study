import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
A_N = sorted(map(int, input().split()))
M = int(input())
X_N = list(map(int, input().split()))

for x in X_N :
    i = bisect_left(A_N, x) # x가 들어갈 위치
    if i < N and x == A_N[i] : # 그 자리에 x가 있는 경우
        print(1)
    else:
        print(0)

'''
import sys
input = sys.stdin.readline

N = int(input())
# A_N = list(map(int, input().split()))
# 파이썬의 set은 해시 탐색이라 평균 시간복잡도 O(1)
A_N = set(map(int, input().split()))
M = int(input())
X_N = list(map(int, input().split()))

for x in X_N :
    if x in A_N :
        print(1)
    else:
        print(0)
'''