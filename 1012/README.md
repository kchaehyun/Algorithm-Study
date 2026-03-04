# BOJ 1012 - 유기농 배추

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1012)
- 배추가 심어진 위치들이 주어질 때, 상하좌우로 인접한 배추들은 하나의 그룹으로 본다.
- 각 그룹마다 배추흰지렁이 1마리가 필요하므로, 전체 배추 그룹(연결 요소)의 개수를 구하면 된다.

## 아이디어
- 2차원 격자에서 연결 요소 개수를 구하는 전형적인 그래프 탐색 문제다.
- 배추가 있는 칸(값 1) 중 아직 방문하지 않은 칸에서 BFS를 시작하면, 같은 그룹의 배추를 한 번에 모두 방문 처리할 수 있다.
- BFS를 시작한 횟수를 세면 필요한 지렁이 수와 같다.

## 시간복잡도
- 테스트케이스 하나당 O(N x M)
- 각 칸을 최대 한 번씩만 방문한다.

## 풀이 과정
1. 테스트케이스 수 `T`를 입력받는다.
2. 각 테스트케이스마다 `M, N, K`를 입력받고, `N x M` 크기의 밭 배열(`graph`)을 만든다.
3. `K`개의 배추 좌표 `(X, Y)`를 입력받아 `graph[Y][X] = 1`로 표시한다.
4. 모든 칸을 순회하면서 배추가 있고 아직 방문하지 않은 칸이면 BFS를 수행한다.
5. BFS 한 번이 배추 그룹 하나이므로, BFS 호출마다 정답을 1 증가시킨다.
6. 순회가 끝나면 정답을 출력한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def bfs(row,column):
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    visited[row][column] = True
    queue = deque([(row, column)])
    while queue:
        r, c = queue.popleft()
        for i in range(4) :
            next_row = r + dx[i]
            next_column = c + dy[i]
            if 0 <= next_row < N and 0 <= next_column < M :
                if graph[next_row][next_column] == 1 and not visited[next_row][next_column] :
                    visited[next_row][next_column] = True
                    queue.append((next_row, next_column))
    
    
T = int(input())
for _ in range(T) :
    M, N, K = map(int, input().split())
    graph = [[0]*M for _ in range(N)]
    visited = [[False]*M for _ in range(N)]
    for _ in range(K) :
        X, Y = map(int, input().split())
        graph[Y][X] = 1
    answer = 0
    for y in range(N):
        for x in range(M) :
            if graph[y][x] == 1 and not visited[y][x]:
                bfs(y,x)
                answer = answer + 1
    print(answer)
```
- `graph[y][x]`는 해당 위치에 배추가 있는지 여부를 저장한다.
- `visited[y][x]`로 BFS 중복 탐색을 막는다.
- `bfs(y, x)`는 시작점과 연결된 모든 배추를 방문 처리한다.
- 전체 순회에서 BFS를 시작한 횟수(`answer`)가 최종 답이다.
