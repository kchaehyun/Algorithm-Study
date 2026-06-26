import sys
input = sys.stdin.readline

def dfs(start):
    global ans
    visited[start] = True
    for g in graph[start]:
        if not visited[g]:
            ans += 1
            dfs(g)

computer = int(input())
connected = int(input())
ans = 0
visited = [False] * (computer+1)
graph = [[] for _ in range(computer+1)]

for _ in range(connected):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
dfs(1)
print(ans)