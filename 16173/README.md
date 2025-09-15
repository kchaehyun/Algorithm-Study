# BOJ 16173 - 점프왕 쩰리 (Small)

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/16173)
- N×N 보드 위에서 (0, 0) 위치에서 출발한다.
- 각 칸에는 점프할 수 있는 칸 수가 적혀 있다.
- 오른쪽 또는 아래로만 이동할 수 있으며, **-1**이 적힌 칸에 도착하면 게임 성공.
- 보드 끝까지 도달하지 못하면 실패.

## 아이디어
- BFS(또는 DFS) 탐색 문제.
- 시작점 (0, 0)에서 오른쪽, 아래 두 방향으로 점프할 수 있다.
- 이미 방문한 칸은 다시 방문하지 않는다.
- 큐를 이용해 탐색하면서 `-1`에 도달하면 성공, 끝까지 못 가면 실패.

## 풀이 과정
1. 입력으로 N과 보드 상태를 받음.
2. visited 배열을 생성해 방문 체크.
3. BFS 실행:
   - 현재 위치의 값만큼 오른쪽/아래로 점프.
   - 점프한 위치가 보드 안에 있고 방문하지 않았다면 큐에 삽입.
   - 이동한 칸이 `-1`이면 "HaruHaru" 출력 후 종료.
4. 큐가 빌 때까지 `-1`을 못 찾으면 "Hing" 출력.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph, start_row, start_col):
    dx = [1, 0]  # 아래, 오른쪽
    dy = [0, 1]
    queue = deque([(start_row, start_col)])
    visited[start_row][start_col] = True
    
    while queue:
        r, c = queue.popleft()
        if graph[r][c] == -1:
            print("HaruHaru")
            return
        for i in range(2):
            next_row = r + dx[i] * graph[r][c]
            next_col = c + dy[i] * graph[r][c]
            if 0 <= next_row < N and 0 <= next_col < N:
                if not visited[next_row][next_col]:
                    visited[next_row][next_col] = True
                    queue.append((next_row, next_col))
    print("Hing")
     

N = int(input())
graph = [list(map(int, input().split())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]

bfs(graph, 0, 0)
```
- `dx, dy` → 아래, 오른쪽 방향 정의.

- `graph[r][c] == -1` → 도착 여부 체크.

- 방문 여부는 `visited` 배열로 관리.

