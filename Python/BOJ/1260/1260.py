import sys
from collections import deque
input = sys.stdin.readline

def dfs(num) :
    d.append(num)
    visited[num] = True
    for g in graph[num]:
        if not visited[g]:
            dfs(g)
            
def bfs(graph, num) :
    b = []
    queue = deque([num])
    visited[num] = True
    while queue:
        n = queue.popleft()
        b.append(n)
        for g in graph[n]:
            if not visited[g] :
                queue.append(g)
                visited[g] = True
    return b

N, M, V = map(int, input().split())
graph = [[] for _ in range(N+1)]
for i in range(M) :
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
for g in graph:
    g.sort()

visited = [False] * (N+1)
d = []
dfs(V)
print(*d)

visited = [False] * (N+1)
b = bfs(graph, V)
print(*b)