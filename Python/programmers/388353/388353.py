from collections import deque

def access(board) :
    R = len(board)
    C = len(board[0])
    dr = [1,0,-1,0]
    dc = [0,1,0,-1]
    visited = [[False]*C for _ in range(R)]
    visited[0][0] = True
    q = deque([(0,0)])
    while q :
        row, col = q.popleft()
        for i in range(4) :
            n_r = row + dr[i]
            n_c = col + dc[i]
            if 0 <= n_r < R and 0 <= n_c < C :
                if board[n_r][n_c] == '0' and not visited[n_r][n_c] :
                    visited[n_r][n_c] = True
                    q.append((n_r,n_c))
    return visited
        

def solution(storage, requests):
    r = len(storage)
    c = len(storage[0])
    answer = r*c
    containers = [list('0'*(c+2))]
    for i in range(r) :
        containers.append(list('0' + storage[i] + '0'))
    containers.append(list('0'*(c+2)))
    
    for req in requests :
        
        if len(req) == 1 : #지게차
            access_list = access(containers)
            remove = []
            for i in range(1,r+1) :
                for j in range(1,c+1) :
                    if containers[i][j] == req :
                        for d_r,d_c in [(0,1),(1,0),(0,-1),(-1,0)] :
                            if access_list[i+d_r][j+d_c] :
                                remove.append((i,j))
                                break
            for i,j in remove :
                containers[i][j] = '0'
                answer -= 1
        
        else : # 크레인
            alphabet = req[0]
            for i in range(r+2) :
                for j in range(c+2) :
                    if containers[i][j] == alphabet :
                        containers[i][j] = '0'
                        answer -= 1
                        
    return answer

print(solution(["HAH", "HBH", "HHH", "HAH", "HBH"],["C", "B", "B", "B", "B", "H"]))