import sys
input = sys.stdin.readline

def dfs(r,c,graph) :
    visited[r][c] = True
    rgb = graph[r][c]
    stack = [(r,c)]
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    while stack :
        r,c = stack.pop()
        for i in range(4) :
            nr = r + dr[i]
            nc = c + dc[i]
            if 0 <= nr < N and 0 <= nc < len(graph[0]) and not visited[nr][nc] :
                if graph[nr][nc] == rgb :
                    visited[nr][nc] = True
                    stack.append((nr,nc))

N = int(input())
picture = []
for _ in range(N) :
    picture.append(input().strip())

visited = [[False]*len(picture[0]) for _ in range(N)]
ans_1 = 0
for i in range(N) : #행
    for j in range(len(picture[0])) : #열
        if not visited[i][j]:
            ans_1 += 1
            dfs(i,j,picture)

visited = [[False]*len(picture[0]) for _ in range(N)]
ans_2 = 0
weak_picture = [r.replace('G', 'R') for r in picture]
for i in range(N) :
    for j in range(len(weak_picture[0])) :
        if not visited[i][j]:
            ans_2 += 1
            dfs(i,j,weak_picture)

print(ans_1, ans_2)