import sys
input = sys.stdin.readline

def dfs(graph,r,c) :
    visited[r][c] = True
    dr = [1,0,-1,0,1,1,-1,-1]
    dc = [0,1,0,-1,1,-1,1,-1]
    land = [(r,c)]
    while land :
        row,col = land.pop()
        for i in range(8) :
            nr = row + dr[i]
            nc = col + dc[i]
            if 0 <= nr < h and 0 <= nc < w and not visited[nr][nc] :
                if graph[nr][nc] == 1 :
                    land.append((nr,nc))
                    visited[nr][nc] = True


while True :
    w, h = map(int, input().split())
    if w == 0 and h == 0 :
        break
    land_map = []
    for i in range(h) :
        land_map.append(list(map(int, input().split())))
    visited = [[False]*w for _ in range(h)]
    ans = 0
    for i in range(h) :
        for j in range(w) :
            if land_map[i][j] == 1 and not visited[i][j] :
                ans += 1
                dfs(land_map,i,j)
    print(ans)