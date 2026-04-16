import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(v,graph) :
    visited[v] = True
    for vertex in graph[v] :
        if not visited[vertex] :
            dfs(vertex,graph)

N, M = map(int, input().split())
g = [[] for _ in range(N+1)]

for _ in range(M) :
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
visited = [False]*(N+1)

ans = 0
for n in range(1,N+1) :
    if not visited[n] :
        ans += 1
        dfs(n, g)

print(ans)