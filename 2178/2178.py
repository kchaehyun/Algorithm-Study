import sys
from collections import deque
input = sys.stdin.readline

def bfs(n, m, graph):
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    queue = deque([(0, 0, 1)])
    visited[0][0] = True
    while queue:
        x, y, dist = queue.popleft()
        if x == n-1 and y == m-1:
            print(dist)
            return
        for i in range(4):
            if 0 <= x+dx[i] <= (n-1) and 0 <= y+dy[i] <= (m-1) :
                if graph[x+dx[i]][y+dy[i]] == 1 and not visited[x+dx[i]][y+dy[i]]:
                    queue.append((x+dx[i], y+dy[i], dist+1))
                    visited[x+dx[i]][y+dy[i]] = True

N, M = map(int, input().split())
graph = [list(map(int, input().strip())) for _ in range(N)]

visited = [[False] * M for _ in range(N)]
bfs(N, M, graph)