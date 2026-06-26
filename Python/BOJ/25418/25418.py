import sys
from collections import deque
input = sys.stdin.readline

def bfs(start, target):
    queue = deque([(start, oper)])
    visited[start] = True
    while queue : 
        s, o = queue.popleft()
        if s+1 <= target and not visited[s+1]:
            visited[s+1] = True
            queue.append((s+1, o+1))
        if s*2 <= target and not visited[s*2]:
            visited[s*2] = True
            queue.append((s*2, o+1))
        if s == target:
            print(o)
            return

A, K = map(int, input().split())
visited = [False] * (K+2)
oper = 0
bfs(A, K)