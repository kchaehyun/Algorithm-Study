import sys
import heapq
input = sys.stdin.readline

n, d = map(int, input().split())
shortcuts = [[] for _ in range(d+1)]
for _ in range(n) :
    s, e, l = map(int, input().split())
    if e-s > l and e <= d:
        shortcuts[s].append((e,l))

dist = [float('inf')]*(d+1)
dist[0] = 0
h = [(0,0)]
while h :
    cost, now = heapq.heappop(h)
    if now + 1 <= d :
        if dist[now+1] > cost+1 :
            dist[now+1] = cost+1
            heapq.heappush(h, (cost+1,now+1))
    for (end, length) in shortcuts[now]:
        if dist[end] > cost+length :
            dist[end] = cost+length
            heapq.heappush(h, (cost+length,end))

print(dist[d])