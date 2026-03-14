from collections import deque        

def solution(board):
    answer = 0
    row = len(board)
    column = len(board[0])
    for r in range(row) :
        for c in range(column) :
            if board[r][c] == "R" :
                R_x = c
                R_y = r
            if board[r][c] == "G" :
                G_x = c
                G_y = r
    visited = [[False]*column for _ in range(row)]
    def bfs(robot_y,robot_x,move):
        dx = [0,1,0,-1]
        dy = [1,0,-1,0]

        queue = deque([(robot_y,robot_x,0)])
        visited[robot_y][robot_x] = True
        while queue:
            y,x,m = queue.popleft()
            if y == G_y and x == G_x :
                return m
            for i in range(4) :
                n_y = y
                n_x = x
                while True :
                    n_y += dy[i]
                    n_x += dx[i]
                    if n_y < 0 or n_x < 0 or n_y >= row or n_x >= column or board[n_y][n_x] == "D" :
                        n_y -= dy[i]
                        n_x -= dx[i]
                        break
                if not visited[n_y][n_x] :
                    visited[n_y][n_x] = True
                    queue.append((n_y,n_x,m+1))
        return -1
    answer = bfs(R_y,R_x,0)
    return answer