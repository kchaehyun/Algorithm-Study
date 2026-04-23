# BOJ 2583 - 영역 구하기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2583)
- `M x N` 크기의 모눈종이 위에 `K`개의 직사각형을 그릴 때, 직사각형이 그려지지 않은 나머지 영역의 개수와 각 영역의 넓이를 구하는 문제이다.

## 아이디어
- 2차원 배열을 0으로 초기화하고, 직사각형이 차지하는 영역을 1로 채운다.
- 배열의 모든 칸을 순회하며 값이 0인 칸을 만나면 BFS(너비 우선 탐색)를 시작한다.
- 한 번의 BFS로 연결된 모든 0인 칸을 방문하며 넓이를 계산한다.

## 시간복잡도
- 격자의 모든 칸을 확인하고 방문하므로 전체 시간복잡도는 `O(M * N)`이다.

## 풀이 과정
1. `M`, `N`, `K`를 입력받고 `M x N` 크기의 격자 `g`를 0으로 초기화한다.
2. `K`개의 직사각형 좌표를 입력받아 해당 영역을 `g[i][j] = 1`로 설정한다.
3. 이중 반복문으로 격자를 순회하며 `g[i][j] == 0`인 칸을 찾는다.
4. 해당 칸에서 BFS를 호출하여 영역의 개수 `num`을 1 증가시키고, 반환된 넓이를 `area_arr`에 저장한다.
5. 모든 탐색이 끝나면 `num`과 오름차순 정렬된 `area_arr`를 출력한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def bfs(graph,r,c) :
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    graph[r][c] = 1
    area = 1
    q = deque([(r,c)])
    while q :
        row, col = q.popleft()
        for i in range(4) :
            nr = row + dr[i]
            nc = col + dc[i]
            if 0 <= nr < M and 0 <= nc < N and graph[nr][nc] == 0 :
                graph[nr][nc] = 1
                area += 1
                q.append((nr,nc))
    return area

M, N, K = map(int, input().split())
coords = [list(map(int, input().split())) for _ in range(K)]

g = [[0]*N for _ in range(M)]
for x1, y1, x2, y2 in coords :
    for i in range(y1,y2) :
        for j in range(x1,x2) :
            g[i][j] = 1

num = 0
area_arr = []
for i in range(M) :
    for j in range(N) :
        if g[i][j] == 0 :
            num += 1
            zone = bfs(g,i,j)
            area_arr.append(zone)

print(num)
print(*sorted(area_arr))
```
- `bfs` 함수는 큐를 사용하여 인접한 0인 칸을 방문하고 방문 처리(1로 변경)하며 영역의 크기를 누적한다.
- 문제의 (x, y) 좌표를 행렬의 인덱스 `g[y][x]`에 맞춰 직사각형을 채우는 것이 중요하다.
- `deque`를 사용하여 BFS의 효율성을 높였다.
