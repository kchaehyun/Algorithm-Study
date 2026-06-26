from collections import deque

def solution(maps):
    answer = 0
    rows = (len(maps))
    columns = len(maps[0])
    for r in range(rows) :
        for c in range(columns) :
            if maps[r][c] == "S" :
                start = (r,c)
            elif maps[r][c] == "L" :
                lever = (r,c)
    
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    def bfs(start,time,target) :
        visited = [[False]*columns for _ in range(rows)]
        visited[start[0]][start[1]] = True
        queue = deque([(start[0],start[1],time)])
        while queue :
            r, c, t = queue.popleft()
            if maps[r][c] == target :
                return t
            for i in range(4) :
                n_r = r + dx[i]
                n_c = c + dy[i]
                if 0 <= n_r < rows and 0 <= n_c < columns :
                    if not visited[n_r][n_c] and maps[n_r][n_c] != "X":
                        visited[n_r][n_c] = True
                        queue.append((n_r,n_c,t+1))
        return -1
    
    tmp_time = bfs(start,0,"L")
    if tmp_time == -1 :
        return -1
    
    answer = bfs(lever,tmp_time,"E")
    return answer

print(solution(["SOOOL","XXXXO","OOOOO","OXXXX","OOOOE"]))