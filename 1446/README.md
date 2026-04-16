# BOJ 1446 - 지름길

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1446)
- 고속도로의 길이 `D`와 여러 지름길 정보가 주어진다.
- 0번 위치에서 D번 위치까지 이동할 때, 지름길을 적절히 사용해서 갈 수 있는 최소 거리를 구하는 문제이다.

## 아이디어
- 기본적으로 현재 위치에서 다음 위치로 1만큼 이동할 수 있다.
- 지름길은 특정 시작 위치에서 특정 도착 위치까지 더 짧은 거리로 이동할 수 있는 간선으로 볼 수 있다.
- 각 위치를 정점으로 보고, 일반 도로 이동과 지름길 이동을 함께 고려하면 최단 거리 문제로 바뀐다.
- 모든 이동 거리가 음수가 아니므로 우선순위 큐를 이용한 다익스트라 알고리즘을 사용할 수 있다.

## 풀이 과정
1. 지름길의 개수 `n`과 고속도로의 길이 `d`를 입력받는다.
2. 시작 위치별로 지름길을 저장할 `shortcuts` 리스트를 만든다.
3. 지름길 정보 `(s, e, l)`을 입력받는다.
4. 지름길의 길이 `l`이 일반 도로 거리 `e - s`보다 짧고, 도착 위치 `e`가 `d` 이하인 경우만 저장한다.
5. 각 위치까지의 최소 거리를 저장할 `dist` 배열을 만들고, 시작점인 0번 위치의 거리를 0으로 둔다.
6. 우선순위 큐에 `(현재까지의 거리, 현재 위치)` 형태로 값을 넣는다.
7. 큐에서 현재까지의 거리가 가장 짧은 위치를 꺼낸다.
8. 현재 위치에서 `now + 1`로 1칸 이동하는 경우를 확인해 더 짧으면 갱신한다.
9. 현재 위치에서 시작하는 지름길이 있다면, 지름길을 이용하는 경우도 확인해 더 짧으면 갱신한다.
10. 최종적으로 `dist[d]`를 출력한다.

## 코드 설명
```python
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
```
- `shortcuts[s]`에는 `s` 위치에서 사용할 수 있는 지름길 `(도착 위치, 길이)`를 저장한다.
- `e-s > l` 조건을 통해 일반 도로보다 짧은 지름길만 저장한다.
- `dist[i]`는 0번 위치에서 i번 위치까지 가는 최소 거리를 의미한다.
- 힙에는 `(cost, now)` 형태로 저장하므로, 현재까지의 거리가 짧은 위치부터 탐색된다.
- 일반 도로로 1칸 이동하는 경우와 지름길을 이용하는 경우를 모두 비교하면서 `dist`를 갱신한다.

