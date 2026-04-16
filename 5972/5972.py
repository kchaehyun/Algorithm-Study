import sys
import heapq
input = sys.stdin.readline

N, M = map(int, input().split())

g = [[] for _ in range(N+1)]
dist = [float('inf')] * (N+1)

for _ in range(M) :
    a, b, c = map(int, input().split())
    g[a].append((b,c))
    g[b].append((a,c))

dist[1] = 0
h = [(0, 1)]
while h :
    cost, now = heapq.heappop(h)
    if dist[now] < cost :
        continue
    for (next, cow) in g[now] :
        if dist[next] > cost+cow:
            dist[next] = cost+cow
            heapq.heappush(h, (cost+cow,next))

print(dist[N])