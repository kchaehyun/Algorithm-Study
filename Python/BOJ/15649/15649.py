import sys
from itertools import permutations
input = sys.stdin.readline

def dfs(arr, pick) :
    if pick == 0:
        print(*result)
        return
    for a in arr:
        if not visited[a]:
            result.append(a)
            visited[a] = True
            dfs(arr, pick-1)
            result.pop()
            visited[a] = False

N, M = map(int, input().split())
arr = []
result = []
for i in range(1,N+1):
    arr.append(i)

visited = [False] * (N+1)
dfs(arr, M)