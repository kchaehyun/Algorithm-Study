import sys
from collections import deque
input = sys.stdin.readline

def bfs(num, target):
    time = 0
    visited[num] = True
    queue = deque([(num, 0)])
    while queue:
        n, time = queue.popleft()
        if n == target :
            print(time)
            return
        next = [n-1, n+1, 2*n]
        for i in range(3):
            if 0 <= next[i] < len(visited) and not visited[next[i]] :
                queue.append((next[i], time+1))
                visited[next[i]] = True
        

N, K = map(int, input().split())
visited = [False] * 100001
bfs(N, K)