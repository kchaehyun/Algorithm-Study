import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph,r,c) :
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    graph[r][c] = 1
    area = 1
    q = deque([(r,c)])
    while q :
        row, col = q.popleft()
        for i in range(4) :
            nr = row + dr[i]
            nc = col + dc[i]
            if 0 <= nr < M and 0 <= nc < N and graph[nr][nc] == 0 :
                graph[nr][nc] = 1
                area += 1
                q.append((nr,nc))
    return area



M, N, K = map(int, input().split())
coords = [list(map(int, input().split())) for _ in range(K)]

g = [[0]*N for _ in range(M)]
for x1, y1, x2, y2 in coords :
    for i in range(y1,y2) :
        for j in range(x1,x2) :
            g[i][j] = 1

num = 0
area_arr = []
for i in range(M) :
    for j in range(N) :
        if g[i][j] == 0 :
            num += 1
            zone = bfs(g,i,j)
            area_arr.append(zone)

print(num)
print(*sorted(area_arr))