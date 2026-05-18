from collections import deque
  
def solution(land):
    row = len(land)
    col = len(land[0])
    col_size = [0] * col
    
    for r in range(row) :
        for c in range(col) :
            if land[r][c] == 1:
                cols = set([c])
                now_size = 1
                q = deque([(r,c)])            
                land[r][c] = 0
                while q :
                    now_r, now_c = q.popleft()
                    for dr,dc in [(1,0),(0,1),(-1,0),(0,-1)] :
                        nr = now_r + dr
                        nc = now_c + dc
                        if 0 <= nr < row and 0 <= nc < col :
                            if land[nr][nc] == 1 :
                                cols.add(nc)
                                land[nr][nc] = 0
                                now_size += 1
                                q.append((nr,nc))
                for C in cols :
                    col_size[C] += now_size                                
                
    return max(col_size)

print(solution([[0, 0, 0, 1, 1, 1, 0, 0], [0, 0, 0, 0, 1, 1, 0, 0], [1, 1, 0, 0, 0, 1, 1, 0], [1, 1, 1, 0, 0, 0, 0, 0], [1, 1, 1, 0, 0, 0, 1, 1]]))