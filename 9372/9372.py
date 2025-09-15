import sys
input = sys.stdin.readline

def dfs(node):
    global ans
    visited[node] = True
    for g in graph[node]:
        if not visited[g]:
            ans += 1
            dfs(g)
    
t = int(input())
for _ in range(t) :
    n, m = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    visited = [False] * (n+1)
    for _ in range(m) :
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    ans = 0
    dfs(1)
    print(ans)