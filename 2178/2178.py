import sys
from collections import deque
input = sys.stdin.readline

def bfs(n, m, graph):
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    queue = deque([(0, 0, 1)])
    visited[0][0] = True
    while queue:
        a, b, dist = queue.popleft()
        if a == n-1 and b == m-1:
            print(dist)
            return
        for i in range(4):
            if 0 <= a+dy[i] <= (n-1) and 0 <= b+dx[i] <= (m-1) :
                if graph[a+dy[i]][b+dx[i]] == 1 and not visited[a+dy[i]][b+dx[i]]:
                    queue.append((a+dy[i], b+dx[i], dist+1))
                    visited[a+dy[i]][b+dx[i]] = True

N, M = map(int, input().split())
graph = []
for i in range(N) :
    graph.append(list(map(int, input().strip())))

visited = [[False] * M for _ in range(N)]
bfs(N, M, graph)