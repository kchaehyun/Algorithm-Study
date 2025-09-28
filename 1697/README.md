# BOJ 1697 - 숨바꼭질

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1697)
- 수빈이가 점 N에 있고 동생이 점 K에 있을 때, 동생을 찾는 가장 빠른 시간을 구하는 문제이다.
- 수빈이는 X-1, X+1, 2*X 위치로 이동할 수 있으며, 각 이동은 1초가 걸린다.

## 아이디어
- 최단 시간을 찾는 문제이므로 너비 우선 탐색(BFS)을 사용한다.
- 각 위치를 하나의 정점으로 보고, 이동 가능한 관계를 간선으로 보는 그래프 탐색 문제로 모델링할 수 있다.

## 시간복잡도
- BFS의 시간 복잡도는 O(V + E)이다.
- 이 문제에서 정점(V)의 개수는 방문할 수 있는 위치의 수(약 100,000개)이고, 각 정점에서 나가는 간선(E)의 개수는 최대 3개이다.
- 따라서 시간 복잡도는 O(N)으로 볼 수 있다. (N은 수빈이와 동생의 최대 위치)

## 풀이 과정
1. BFS를 위한 큐(queue)와 방문 여부를 확인할 배열 `visited`를 생성한다.
2. 큐에 시작 위치와 시간(0초)을 튜플로 넣어준다.
3. 큐가 빌 때까지 다음을 반복한다.
    - 큐에서 현재 위치와 시간을 꺼낸다.
    - 만약 현재 위치가 동생의 위치와 같다면, 현재 시간을 출력하고 탐색을 종료한다.
    - 현재 위치에서 이동할 수 있는 다음 위치들(n-1, n+1, 2*n)을 탐색한다.
    - 각 다음 위치가 유효한 범위 내에 있고 아직 방문하지 않았다면, 큐에 (다음 위치, 현재 시간 + 1)을 추가하고 방문 표시를 한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def bfs(num, target):
    time = 0
    visited[num] = True
    queue = deque([(num, 0)])
    while queue:
        n, time = queue.popleft()
        if n == target :
            print(time)
            return
        next = [n-1, n+1, 2*n]
        for i in range(3):
            if 0 <= next[i] < len(visited) and not visited[next[i]] :
                queue.append((next[i], time+1))
                visited[next[i]] = True
        

N, K = map(int, input().split())
visited = [False] * 100001
bfs(N, K)
```
- `bfs` 함수를 통해 너비 우선 탐색을 수행한다.
- `visited` 배열을 통해 한 번 방문한 위치는 다시 방문하지 않도록 하여 시간 복잡도를 줄인다.
- `deque`를 사용하여 큐를 구현하였고, (위치, 시간)을 함께 저장하여 최단 시간을 계산한다.
