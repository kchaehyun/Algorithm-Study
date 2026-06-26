# BOJ 9372 - 상근이의 여행

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/9372)
- n개의 국가와 m개의 비행기가 주어진다.
- 어떤 나라에서든 다른 나라로 이동할 수 있다.
- 모든 국가를 여행하기 위해 필요한 비행기 종류의 최소 개수를 구하는 문제.

## 아이디어
- **트리 성질**을 이용하는 문제.
- n개의 노드를 모두 연결하는 데 필요한 간선(비행기)의 최소 개수는 항상 `n-1`.
- 입력된 그래프가 연결 그래프라는 조건이 있으므로, DFS나 BFS로 탐색해도 결국 답은 `n-1`.
- 따라서 실제 그래프 탐색 없이 바로 `n-1`을 출력해도 된다.

## 풀이 과정
1. 테스트케이스 T 입력.
2. 각 테스트케이스에 대해 n, m 입력.
3. m개의 간선(비행기) 입력은 사실상 필요 없음.
4. 답은 항상 `n-1`.

## 코드 설명
```python
import sys
input = sys.stdin.readline

def dfs(node):
    global ans
    visited[node] = True
    for g in graph[node]:
        if not visited[g]:
            ans += 1
            dfs(g)
    
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    graph = [[] for _ in range(n+1)]
    visited = [False] * (n+1)
    for _ in range(m):
        a, b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
    ans = 0
    dfs(1)
    print(ans)
```
- DFS로 방문한 간선 수를 카운트해서 답을 구한 풀이.

- 하지만 실제로는 입력 무시하고 print(n-1) 하면 충분하다.

