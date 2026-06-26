# Programmers 1844 - 게임 맵 최단거리

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/1844)
- `(0,0)`에서 `(n-1,m-1)`까지 이동하는 최단거리를 구한다.
- `1`은 이동 가능, `0`은 벽이다.
- 도달할 수 없으면 `-1`을 반환한다.

## 아이디어
- 격자에서 최단거리 문제이므로 BFS를 사용한다.
- 큐에 좌표와 현재 거리 값을 함께 저장하며 레벨 순으로 확장한다.
- 목표 지점에 처음 도달한 거리 값이 정답이다.

## 시간복잡도
- O(R*C)

## 풀이 과정
1. 방문 배열을 준비하고 시작점 `(0,0)`을 큐에 넣는다.
2. 큐에서 좌표를 꺼내 4방향 이웃을 확인한다.
3. 범위 안이고 벽이 아니며 미방문이면 방문 처리 후 큐에 거리+1로 삽입한다.
4. 목표 지점 도달 시 거리를 반환하고, 끝까지 못 가면 `-1`을 반환한다.

## 코드 설명
```python
from collections import deque

def solution(maps):
    answer = 0
    n = len(maps[0]) # 행
    m = len(maps) # 열
    visited = [[False]*n for _ in range(m)]
    def bfs(x,y,dis) :
        dx = [1, 0, -1, 0]
        dy = [0, 1, 0, -1]
        queue = deque([(x,y,1)])
        visited[y][x] = True
        while queue :
            column, row, d = queue.popleft()
            if row == m-1 and column == n-1 :
                return d

            for i in range(4) :
                next_row = row + dx[i]
                next_column = column + dy[i]
                if 0 <= next_row < m and 0 <= next_column < n :
                    if not visited[next_row][next_column] and maps[next_row][next_column] == 1 :
                        queue.append((next_column,next_row,d+1))
                        visited[next_row][next_column] = True
        return -1
    answer = bfs(0,0,1)
    
    return answer
```
- BFS는 먼저 도착한 경로가 최단거리라는 성질을 이용한다.
- `visited`로 중복 탐색을 막아 시간 낭비를 줄인다.
