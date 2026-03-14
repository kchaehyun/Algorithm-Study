from collections import deque

def solution(maps):
    answer = 0
    n = len(maps[0]) # 행
    m = len(maps) # 열
    visited = [[False]*n for _ in range(m)]
    def bfs(x,y,dis) :
        dx = [1, 0, -1, 0]
        dy = [0, 1, 0, -1]
        queue = deque([(x,y,1)])
        visited[y][x] = True
        while queue :
            column, row, d = queue.popleft()
            if row == m-1 and column == n-1 :
                return d

            for i in range(4) :
                next_row = row + dx[i]
                next_column = column + dy[i]
                if 0 <= next_row < m and 0 <= next_column < n :
                    if not visited[next_row][next_column] and maps[next_row][next_column] == 1 :
                        queue.append((next_column,next_row,d+1))
                        visited[next_row][next_column] = True
        return -1
    answer = bfs(0,0,1)
    
    return answer