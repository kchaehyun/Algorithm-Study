# BOJ 1260 - DFS와 BFS
- [문제 링크](https://www.acmicpc.net/problem/1260)
- 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램을 작성하시오. 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우에 종료한다. 정점 번호는 1번부터 N번까지이다.

## 아이디어
- DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색) 알고리즘을 구현하여 그래프를 순회한다.
- DFS는 재귀 함수를 사용하여 구현하고, BFS는 큐(Queue) 자료구조를 사용하여 구현한다.
- 정점 번호가 작은 것을 먼저 방문해야 하므로, 각 정점의 인접 리스트를 오름차순으로 정렬한다.

## 풀이 과정
1. 입력을 받아 인접 리스트 형태로 그래프를 만든다.
2. 각 정점의 인접 리스트를 오름차순으로 정렬한다.
3. DFS를 수행하기 위해 `visited` 배열을 초기화하고, 시작 정점 `V`부터 DFS를 시작하여 결과를 출력한다.
4. BFS를 수행하기 위해 `visited` 배열을 다시 초기화하고, 시작 정점 `V`부터 BFS를 시작하여 결과를 출력한다.

## 코드 설명
```python
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
```
- `dfs` 함수는 재귀적으로 호출되며, 현재 노드를 방문 처리하고 인접한 노드를 방문하지 않았다면 다시 `dfs` 함수를 호출한다.
- `bfs` 함수는 큐를 사용하여 구현한다. 큐에서 노드를 하나 꺼내 방문하고, 인접한 노드 중 방문하지 않은 노드를 큐에 넣고 방문 처리한다. 이 과정을 큐가 빌 때까지 반복한다.
- 두 탐색을 수행하기 전에 각 정점의 인접 리스트(`graph`)를 `sort()`를 통해 정렬하여 문제의 조건(정점 번호가 작은 것부터 방문)을 만족시킨다.
- `dfs`와 `bfs`를 각각 수행하기 전에 `visited` 배열을 `False`로 초기화해준다.
