# BOJ 5972 - 택배 배송

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/5972)
- 헛간 1번에서 N번 헛간까지 택배를 배송하려고 한다.
- 각 길마다 지나갈 때 필요한 소의 수가 주어질 때, 필요한 소의 수의 최솟값을 구하는 문제이다.

## 아이디어
- 헛간을 정점, 길을 간선, 필요한 소의 수를 가중치로 볼 수 있다.
- 1번 정점에서 N번 정점까지의 최단 거리를 구하면 된다.
- 간선의 가중치가 양수이므로 다익스트라 알고리즘을 사용할 수 있다.

## 풀이 과정
1. 헛간의 개수 `N`과 길의 개수 `M`을 입력받는다.
2. 인접 리스트 `g`를 만들고, 각 길을 양방향으로 저장한다.
3. 최단 거리 배열 `dist`를 무한대로 초기화하고, 시작점인 1번 헛간의 거리를 0으로 둔다.
4. 우선순위 큐에 `(0, 1)`을 넣고 탐색을 시작한다.
5. 큐에서 현재까지 비용이 가장 작은 헛간을 꺼낸다.
6. 이미 더 짧은 거리로 방문한 적이 있다면 넘어간다.
7. 인접한 헛간으로 이동했을 때 비용이 더 작아지면 `dist`를 갱신하고 큐에 넣는다.
8. `dist[N]`을 출력한다.

## 코드 설명
```python
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
```
- `g[a].append((b,c))`, `g[b].append((a,c))`로 양방향 그래프를 만든다.
- `dist[i]`는 1번 헛간에서 i번 헛간까지 가는 데 필요한 최소 비용이다.
- 우선순위 큐에는 `(현재까지의 비용, 현재 헛간)`을 저장한다.
- `dist[now] < cost`인 경우는 이미 더 좋은 경로가 발견된 상태이므로 처리하지 않는다.

