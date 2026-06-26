import sys
from collections import deque
input = sys.stdin.readline

def bfs(row,column):
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    visited[row][column] = True
    queue = deque([(row, column)])
    while queue:
        r, c = queue.popleft()
        for i in range(4) :
            next_row = r + dx[i]
            next_column = c + dy[i]
            if 0 <= next_row < N and 0 <= next_column < M :
                if graph[next_row][next_column] == 1 and not visited[next_row][next_column] :
                    visited[next_row][next_column] = True
                    queue.append((next_row, next_column))
    
    
T = int(input())
for _ in range(T) :
    M, N, K = map(int, input().split())
    graph = [[0]*M for _ in range(N)]
    visited = [[False]*M for _ in range(N)]
    for _ in range(K) :
        X, Y = map(int, input().split())
        graph[Y][X] = 1
    answer = 0
    for y in range(N):
        for x in range(M) :
            if graph[y][x] == 1 and not visited[y][x]:
                bfs(y,x)
                answer += 1
    print(answer)