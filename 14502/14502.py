import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline

def bfs(lab) :
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    queue = deque()

    for i in range(N) :
        for j in range(M) :
            if lab[i][j] == 2 :
                queue.append((i,j))

    while queue :
        r, c = queue.popleft()
        for i in range(4) :
            n_r = r + dr[i]
            n_c = c + dc[i]
            if 0 <= n_r < N and 0 <= n_c < M:
                if lab[n_r][n_c] == 0 :
                    lab[n_r][n_c] = 2
                    queue.append((n_r,n_c))


N, M = map(int, input().split())
arr = []
empty = []
for _ in range(N) :
    arr.append(list(map(int, input().split())))

for i in range(N) :
    for j in range(M) :
        if arr[i][j] == 0:
            empty.append((i,j))

ans = 0

for comb in combinations(empty,3) :
    # tmp_arr = arr 이렇게 하면 복사 안됨!
    tmp_arr = [r[:] for r in arr] # 이렇게 해야 복사
    for (i,j) in comb :
        tmp_arr[i][j] = 1

    bfs(tmp_arr)

    safe = 0
    for i in range(N) :
        for j in range(M) :
            if tmp_arr[i][j] == 0 :
                safe += 1
    ans = max(ans, safe)

print(ans)