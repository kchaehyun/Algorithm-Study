# Programmers 159993 - 미로 탈출

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/159993)
- 시작점 `S`에서 레버 `L`을 먼저 당긴 뒤 출구 `E`까지 이동해야 한다.
- 벽 `X`는 지나갈 수 없으며, 상하좌우로만 이동 가능하다.
- 탈출이 불가능하면 `-1`을 반환한다.

## 아이디어
- 최단거리는 BFS로 구한다.
- `S -> L` 최단거리와 `L -> E` 최단거리를 각각 BFS로 계산한다.
- 두 구간 중 하나라도 도달 불가면 전체도 불가능하다.

## 시간복잡도
- BFS 2회 수행: O(R*C)

## 풀이 과정
1. 맵에서 `S`, `L` 위치를 찾는다.
2. BFS로 `S`에서 `L`까지 최단시간을 구한다.
3. 도달 불가(`-1`)면 바로 `-1` 반환.
4. BFS로 `L`에서 `E`까지 최단시간을 구해 반환한다.

## 코드 설명
```python
from collections import deque

def solution(maps):
    answer = 0
    rows = (len(maps))
    columns = len(maps[0])
    for r in range(rows) :
        for c in range(columns) :
            if maps[r][c] == "S" :
                start = (r,c)
            elif maps[r][c] == "L" :
                lever = (r,c)
    
    dx = [1,0,-1,0]
    dy = [0,1,0,-1]
    def bfs(start,time,target) :
        visited = [[False]*columns for _ in range(rows)]
        visited[start[0]][start[1]] = True
        queue = deque([(start[0],start[1],time)])
        while queue :
            r, c, t = queue.popleft()
            if maps[r][c] == target :
                return t
            for i in range(4) :
                n_r = r + dx[i]
                n_c = c + dy[i]
                if 0 <= n_r < rows and 0 <= n_c < columns :
                    if not visited[n_r][n_c] and maps[n_r][n_c] != "X":
                        visited[n_r][n_c] = True
                        queue.append((n_r,n_c,t+1))
        return -1
    
    tmp_time = bfs(start,0,"L")
    if tmp_time == -1 :
        return -1
    
    answer = bfs(lever,tmp_time,"E")
    return answer
```
- 목표 문자(`L` 또는 `E`)를 매개변수로 받아 BFS를 재사용한다.
- 두 BFS 결과를 이어서 사용해 총 이동 시간을 계산한다.
