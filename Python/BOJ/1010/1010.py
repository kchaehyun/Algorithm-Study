import sys
input = sys.stdin.readline

def factorial(num) :
    idx = 1
    fac = 1
    while idx < num:
        fac *= (idx+1)
        idx += 1
    return fac

T = int(input())

for i in range(T):
    N, M = map(int, input().split())
    print(factorial(M)//(factorial(N) * factorial(M-N)))