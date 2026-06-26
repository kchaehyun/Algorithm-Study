# BOJ 11724 - 연결 요소의 개수

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/11724)
- 방향 없는 그래프가 주어졌을 때, 연결 요소의 개수를 구하는 문제이다.
- 연결 요소란 서로 연결되어 있는 정점들의 묶음을 의미한다.

## 아이디어
- 아직 방문하지 않은 정점에서 DFS를 시작하면, 그 정점과 연결된 모든 정점을 한 번에 방문할 수 있다.
- DFS를 새로 시작해야 하는 횟수가 곧 연결 요소의 개수이다.
- 그래프는 무방향이므로 간선 `u v`가 주어지면 `u -> v`, `v -> u`를 모두 저장한다.

## 풀이 과정
1. 정점의 개수 `N`과 간선의 개수 `M`을 입력받는다.
2. 인접 리스트 `g`를 만들고, 모든 간선을 양방향으로 저장한다.
3. 방문 여부를 저장하는 `visited` 배열을 만든다.
4. 1번 정점부터 N번 정점까지 확인하면서 아직 방문하지 않은 정점을 찾는다.
5. 방문하지 않은 정점을 발견하면 연결 요소 개수를 1 증가시키고 DFS를 수행한다.
6. DFS가 끝나면 해당 연결 요소에 포함된 모든 정점이 방문 처리된다.
7. 최종 연결 요소 개수를 출력한다.

## 코드 설명
```python
import sys
sys.setrecursionlimit(10**6)
input = sys.stdin.readline

def dfs(v,graph) :
    visited[v] = True
    for vertex in graph[v] :
        if not visited[vertex] :
            dfs(vertex,graph)

N, M = map(int, input().split())
g = [[] for _ in range(N+1)]

for _ in range(M) :
    u, v = map(int, input().split())
    g[u].append(v)
    g[v].append(u)
visited = [False]*(N+1)

ans = 0
for n in range(1,N+1) :
    if not visited[n] :
        ans += 1
        dfs(n, g)

print(ans)
```
- `dfs` 함수는 현재 정점을 방문 처리한 뒤, 연결된 정점 중 아직 방문하지 않은 정점을 재귀적으로 방문한다.
- `sys.setrecursionlimit(10**6)`은 정점 수가 많을 때 재귀 깊이 제한으로 인한 오류를 막기 위해 사용한다.
- 반복문에서 방문하지 않은 정점을 만날 때마다 새로운 연결 요소가 시작되므로 `ans`를 증가시킨다.
- DFS를 수행하면 해당 정점과 같은 연결 요소에 속한 모든 정점이 방문 처리된다.

