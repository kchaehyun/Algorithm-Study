# BOJ 2606 - 바이러스

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2606)
- 네트워크 상에서 1번 컴퓨터가 바이러스에 감염되었을 때,  
  1번과 연결된 모든 컴퓨터가 감염된다.
- 감염되는 컴퓨터의 수를 출력하는 문제. (1번 제외)

## 아이디어
- **그래프 탐색 문제** → 컴퓨터를 노드, 네트워크 연결을 간선으로 본다.
- 1번 컴퓨터에서 시작하여 DFS로 모든 연결된 노드를 탐색.
- 방문하지 않은 노드를 방문할 때마다 `ans`를 증가.
- 최종적으로 `ans`가 감염된 컴퓨터 수.

## 풀이 과정
1. 컴퓨터 수(N)와 간선 수(M)를 입력받는다.
2. 양방향 연결이므로, 간선 입력 시 `graph[a].append(b)`와 `graph[b].append(a)`로 저장.
3. DFS 함수를 구현:
   - 현재 노드 방문 처리.
   - 인접 노드를 순회하며 방문하지 않았다면 `ans` 증가 후 재귀 호출.
4. 1번 노드에서 DFS 시작.
5. `ans` 출력.

## 코드 설명
```python
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

graph = [[] for _ in range(computer+1)]
visited = [False] * (computer+1)
ans = 0

for _ in range(connected):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

dfs(1)
print(ans)
```
- graph → 인접 리스트 (각 컴퓨터와 연결된 컴퓨터 목록).

- visited → 방문 여부 체크.

- dfs(1) → 1번 컴퓨터부터 탐색 시작.

- ans → 1번을 제외하고 감염된 컴퓨터 수.

- DFS/BFS 모두 가능하지만, 단순히 연결된 컴퓨터 수만 구하면 되므로 DFS로 간단히 해결 가능.
