import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, start_row, start_col):
    dx = [1, 0]
    dy = [0, 1]
    queue = deque([(start_row, start_col)])
    visited[start_row][start_col] = True
    
    while queue:
        r, c = queue.popleft()
        if graph[r][c] == -1:
            print("HaruHaru")
            return
        for i in range(2):
            next_row = r + dx[i] * graph[r][c]
            next_col = c + dy[i] * graph[r][c]
            if 0 <= next_row < N and 0 <= next_col < N:
                if visited[next_row][next_col] == False:
                    visited[next_row][next_col] = True
                    queue.append((next_row, next_col))
    print("Hing")
     

N = int(input())
graph = [list(map(int,input().split())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]

bfs(graph, 0, 0)