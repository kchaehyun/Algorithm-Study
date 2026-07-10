from collections import deque

def solution(x, y, n):
    q = deque([(x,0)])
    visited = [False]*(y+1)
    visited[x] = True
    while q:
        num, op = q.popleft()
        if num == y:
            return op
        if num + n <= y and not visited[num+n] :
            visited[num+n] = True
            q.append((num+n,op+1))
        if num * 2 <= y and not visited[num*2] :
            visited[num*2] = True
            q.append((num*2,op+1))
        if num * 3 <= y and not visited[num*3] :
            visited[num*3] = True
            q.append((num*3,op+1))
    return -1