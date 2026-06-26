# BOJ 2178 - 미로 탐색

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2178)
- N×M 크기의 배열로 표현되는 미로가 주어졌을 때, (1, 1)에서 출발하여 (N, M)의 위치로 이동하기 위해 지나야 하는 최소의 칸 수를 구하는 문제이다.

## 아이디어
- 그래프에서 최단 거리를 구하는 문제와 동일하므로, 너비 우선 탐색(BFS)을 사용하여 해결한다.
- 미로의 각 칸을 정점(vertex)으로 생각하고, 인접한 칸으로의 이동을 간선(edge)으로 생각할 수 있다.

## 시간복잡도
- BFS의 시간 복잡도는 O(V + E)이다.
- 이 문제에서 정점(V)의 개수는 N * M이고, 각 정점에서 나가는 간선(E)의 개수는 최대 4개이다.
- 따라서 시간 복잡도는 O(N * M)이다.

## 풀이 과정
1. 미로 정보를 입력받아 2차원 리스트 `graph`에 저장한다.
2. BFS를 위한 큐(queue)와 방문 여부를 확인할 2차원 리스트 `visited`를 생성한다.
3. 큐에 시작점 (0, 0)과 이동 거리(1)를 튜플로 넣어준다.
4. 큐가 빌 때까지 다음을 반복한다.
    - 큐에서 현재 위치 (y, x)와 이동 거리 `dist`를 꺼낸다.
    - 만약 현재 위치가 도착점 (N-1, M-1)이라면, `dist`를 출력하고 탐색을 종료한다.
    - 상, 하, 좌, 우 네 방향으로 이동할 수 있는 다음 위치를 탐색한다.
    - 각 다음 위치가 미로 범위 내에 있고, 이동할 수 있는 칸(1)이며, 아직 방문하지 않았다면 큐에 (다음 위치, dist + 1)을 추가하고 방문 표시를 한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def bfs(n, m, graph):
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    queue = deque([(0, 0, 1)])
    visited[0][0] = True
    while queue:
        a, b, dist = queue.popleft()
        if a == n-1 and b == m-1:
            print(dist)
            return
        for i in range(4):
            if 0 <= a+dy[i] <= (n-1) and 0 <= b+dx[i] <= (m-1) :
                if graph[a+dy[i]][b+dx[i]] == 1 and not visited[a+dy[i]][b+dx[i]]:
                    queue.append((a+dy[i], b+dx[i], dist+1))
                    visited[a+dy[i]][b+dx[i]] = True

N, M = map(int, input().split())
graph = []
for i in range(N) :
    graph.append(list(map(int, input().strip())))

visited = [[False] * M for _ in range(N)]
bfs(N, M, graph)
```
- `bfs` 함수를 통해 너비 우선 탐색을 수행한다.
- `dx`, `dy` 배열을 사용하여 상, 하, 좌, 우 네 방향을 효율적으로 탐색한다.
- `visited` 배열을 통해 이미 방문한 칸은 다시 방문하지 않도록 하여 무한 루프를 방지하고 효율성을 높인다.
- 큐에 (y좌표, x좌표, 이동 거리)를 함께 저장하여 도착점까지의 최단 거리를 계산한다.
