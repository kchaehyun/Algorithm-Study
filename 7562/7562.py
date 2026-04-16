import sys
from collections import deque
input = sys.stdin.readline

def move(sx,sy,ex,ey, l) :
    dx = [1, 2, -1, -2, 1, 2, -1, -2]
    dy = [2, 1, 2, 1, -2, -1, -2, -1]
    visited[sy][sx] = True
    queue = deque([(sx,sy,0)])
    while queue:
        x, y, m = queue.popleft()
        if x == ex and y == ey :
            return m
        for i in range(8) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < l and 0 <= ny < l and not visited[ny][nx] :
                visited[ny][nx] = True
                queue.append((nx,ny,m+1))



T = int(input())
for _ in range(T) :
    chessboard = int(input())
    start_x, start_y = map(int,input().split())
    end_x, end_y = map(int,input().split())
    visited = [[False]*chessboard for _ in range(chessboard)]
    print(move(start_x,start_y,end_x,end_y,chessboard))