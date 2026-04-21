import sys
input = sys.stdin.readline

def dfs(start,graph) :
    visited = [False] * (N+1)
    stack = [start]
    while stack :
        s = stack.pop()
        for n in graph[s] :
            if not visited[n] :
                visited[n] = True
                stack.append(n)
    return visited


N = int(input())
arr = []
for i in range(N) :
    arr.append(list(map(int, input().split())))

g = [[] for _ in range(N+1)]
for i in range(N) :
    for j in range(N) :
        if arr[i][j] == 1 :
            g[i+1].append(j+1)
            
ans = [[0]*N for _ in range(N)]
for node in range(1,N+1) :
    v = dfs(node,g)
    for i in range(N) :
        if v[i+1] :
            ans[node-1][i] = 1
for i in range(N) :
    print(*ans[i])