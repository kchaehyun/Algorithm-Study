def solution(maps):
    answer = []
    row = len(maps)
    col = len(maps[0])
    visited = [[False]*col for _ in range(row)]
    for r in range(row) :
        for c in range(col) :
            if maps[r][c] != 'X' and not visited[r][c] :
                s = [(r,c)]
                visited[r][c] = True
                day = int(maps[r][c])
                while s :
                    now_r, now_c = s.pop()
                    for dr,dc in [(0,1), (1,0), (-1,0), (0,-1)] :
                        nr = now_r + dr
                        nc = now_c + dc
                        if 0 <= nr < row and 0 <= nc < col :
                            if maps[nr][nc] != 'X' and not visited[nr][nc] :
                                s.append((nr,nc))
                                visited[nr][nc] = True
                                day += int(maps[nr][nc])
                answer.append(day)
    if answer == [] :
        answer.append(-1)
                                
    return sorted(answer, key = lambda x : x)

print(solution(["X591X","X1X5X","X231X", "1XXX1"]))