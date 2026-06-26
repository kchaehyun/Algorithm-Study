import sys
input = sys.stdin.readline

N, M = map(int, input().split())
r, c, d = map(int, input().split())
g = [list(map(int, input().split())) for _ in range(N)]
dr = [-1,0,1,0]
dc = [0,1,0,-1]
ans = 0
while True :
    if g[r][c] == 0 :
        g[r][c] = 2
        ans += 1
    move = False
    for _ in range(4) :
        d = (d+3)%4
        nr = r + dr[d]
        nc = c + dc[d]
        if 0 <= nr < N and 0 <= nc < M and g[nr][nc] == 0 :
            r = nr
            c = nc
            move = True
            break
    if not move :
        back = (d+2)%4
        nr = r + dr[back]
        nc = c + dc[back]
        if g[nr][nc] == 1:
            break
        else :
            r = nr
            c = nc

print(ans)