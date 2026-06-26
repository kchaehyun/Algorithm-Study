# Programmers 169199 - 리코쳇 로봇

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/169199)
- 로봇 `R`은 상하좌우 중 한 방향으로 움직이면 장애물 `D` 또는 경계에 부딪힐 때까지 미끄러진다.
- 목표지점 `G`까지 도달하기 위한 최소 이동 횟수를 구한다.
- 도달할 수 없으면 `-1`을 반환한다.

## 아이디어
- 각 정지 가능한 칸을 노드로 보고 BFS를 수행한다.
- 한 번의 이동은 "한 방향으로 끝까지 미끄러지는 동작" 1회다.
- BFS로 처음 `G`를 만났을 때의 이동 횟수가 최소값이다.

## 시간복잡도
- 각 칸에서 4방향 슬라이딩을 시도: 대략 O(R*C*(R+C))

## 풀이 과정
1. 보드를 순회해 시작점 `R`과 목표점 `G` 좌표를 찾는다.
2. BFS 큐에 시작 위치를 넣고 방문 처리한다.
3. 현재 위치에서 4방향으로 경계/장애물 직전까지 이동한 칸을 다음 상태로 넣는다.
4. `G`에 도달하면 이동 횟수를 반환하고, 끝까지 못 가면 `-1`을 반환한다.

## 코드 설명
```python
from collections import deque        

def solution(board):
    answer = 0
    row = len(board)
    column = len(board[0])
    for r in range(row) :
        for c in range(column) :
            if board[r][c] == "R" :
                R_x = c
                R_y = r
            if board[r][c] == "G" :
                G_x = c
                G_y = r
    visited = [[False]*column for _ in range(row)]
    def bfs(robot_y,robot_x,move):
        dx = [0,1,0,-1]
        dy = [1,0,-1,0]

        queue = deque([(robot_y,robot_x,0)])
        visited[robot_y][robot_x] = True
        while queue:
            y,x,m = queue.popleft()
            if y == G_y and x == G_x :
                return m
            for i in range(4) :
                n_y = y
                n_x = x
                while True :
                    n_y += dy[i]
                    n_x += dx[i]
                    if n_y < 0 or n_x < 0 or n_y >= row or n_x >= column or board[n_y][n_x] == "D" :
                        n_y -= dy[i]
                        n_x -= dx[i]
                        break
                if not visited[n_y][n_x] :
                    visited[n_y][n_x] = True
                    queue.append((n_y,n_x,m+1))
        return -1
    answer = bfs(R_y,R_x,0)
    return answer
```
- 한 방향으로 이동할 때 `while True`로 끝까지 미끄러진 뒤 마지막 유효 좌표를 사용한다.
- 방문 배열로 중복 상태 탐색을 막아 BFS를 효율적으로 수행한다.
