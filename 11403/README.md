# BOJ 11403 - 경로 찾기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/11403)
- 가중치 없는 방향 그래프가 인접 행렬로 주어진다.
- 모든 정점 쌍 `(i, j)`에 대해 `i`에서 `j`로 가는 경로가 있는지 구하는 문제이다.
- 경로가 있으면 `1`, 없으면 `0`을 출력한다.

## 아이디어
- 인접 행렬을 인접 리스트로 바꾼 뒤, 각 정점을 시작점으로 DFS를 수행한다.
- 시작 정점에서 DFS로 도달할 수 있는 정점들을 `visited` 배열에 표시한다.
- DFS 결과를 이용해 정답 행렬의 해당 행을 채운다.
- 모든 정점에서 한 번씩 탐색하면 전체 경로 존재 여부를 구할 수 있다.

## 시간복잡도
- 각 정점마다 DFS를 한 번씩 수행한다.
- 인접 리스트 기준으로 DFS 한 번은 `O(N + E)`이고, 이를 `N`번 반복한다.
- 따라서 시간복잡도는 `O(N * (N + E))`이다.
- 인접 행렬을 확인해 인접 리스트를 만드는 과정은 `O(N^2)`이다.

## 풀이 과정
1. 정점의 개수 `N`을 입력받는다.
2. `N x N` 인접 행렬을 입력받는다.
3. 행렬에서 값이 `1`인 위치를 확인해 인접 리스트 `g`를 만든다.
4. 각 정점 `node`를 시작점으로 DFS를 수행한다.
5. DFS 결과로 반환된 `visited` 배열을 확인해, 도달 가능한 정점은 정답 행렬에 `1`로 표시한다.
6. 모든 시작점에 대한 탐색이 끝나면 정답 행렬을 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

def dfs(start,graph) :
    visited = [False] * (N+1)
    stack = [start]
    while stack :
        s = stack.pop()
        for n in graph[s] :
            if not visited[n] :
                visited[n] = True
                stack.append(n)
    return visited


N = int(input())
arr = []
for i in range(N) :
    arr.append(list(map(int, input().split())))

g = [[] for _ in range(N+1)]
for i in range(N) :
    for j in range(N) :
        if arr[i][j] == 1 :
            g[i+1].append(j+1)
            
ans = [[0]*N for _ in range(N)]
for node in range(1,N+1) :
    v = dfs(node,g)
    for i in range(N) :
        if v[i+1] :
            ans[node-1][i] = 1
for i in range(N) :
    print(*ans[i])
```
- 입력은 0번 인덱스 행렬로 들어오지만, 인접 리스트 `g`는 정점을 1번부터 사용하도록 만든다.
- `dfs(start, graph)`는 시작 정점에서 도달 가능한 정점들을 `visited`에 표시해 반환한다.
- `stack`을 사용해 DFS를 반복문으로 구현한다.
- 각 시작 정점마다 반환된 방문 정보를 정답 행렬 `ans`의 한 행에 반영한다.
