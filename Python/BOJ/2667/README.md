# BOJ 2667 - 단지번호붙이기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2667)
- N*N 크기의 지도에서 1은 집이 있는 곳, 0은 집이 없는 곳을 의미한다.
- 연결된 집들의 모임인 '단지'를 찾아내고, 각 단지에 속한 집의 수를 오름차순으로 정렬하여 출력하는 문제이다.

## 아이디어
- 지도의 모든 칸을 순회하면서, 아직 방문하지 않은 집(1)을 발견하면 해당 집을 시작점으로 새로운 단지 탐색을 시작한다.
- 하나의 단지를 탐색하기 위해 너비 우선 탐색(BFS) 또는 깊이 우선 탐색(DFS)을 사용할 수 있다.
- BFS를 사용하여 한 단지에 속한 모든 집을 찾고, 그 수를 센다.

## 시간복잡도
- 지도의 모든 칸을 한 번씩 방문해야 하므로 기본적으로 O(N^2)의 시간이 걸린다.
- 각 칸에서 BFS/DFS 탐색을 시작하지만, `visited` 배열을 통해 이미 방문한(특정 단지에 속한) 칸은 다시 탐색하지 않는다.
- 결과적으로 모든 칸을 최대 한 번씩만 방문하므로, 총 시간 복잡도는 O(N^2)이다.

## 풀이 과정
1. 지도의 모든 칸(row, col)을 이중 for문으로 순회한다.
2. 만약 `graph[row][col]`이 1이고 아직 방문하지 않았다면(`visited[row][col]`가 False), 새로운 단지를 찾았으므로 다음을 수행한다.
    - 총 단지 수 `town`을 1 증가시킨다.
    - 해당 위치를 시작점으로 BFS 탐색을 시작하여, 연결된 모든 집을 찾고 그 수를 센다.
    - BFS가 반환한 집의 수를 `house` 리스트에 추가한다.
3. 모든 칸의 순회가 끝나면, `house` 리스트를 오름차순으로 정렬한다.
4. 총 단지 수와 정렬된 각 단지의 집 수를 출력한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def bfs(row, col) :
    dx = [0, 1, -1, 0]
    dy = [1, 0, 0, -1]
    house = 1
    visited[row][col] = True
    queue = deque([(row, col)])
    while queue :
        x, y = queue.popleft()
        for i in range(4):
            next_x = x+dx[i]
            next_y = y+dy[i]
            if 0 <= next_x < N and 0 <= next_y < N:
                if graph[next_x][next_y] == 1 and not visited[next_x][next_y]:
                    house += 1
                    queue.append((next_x, next_y))
                    visited[next_x][next_y] = True
    return house
        
        

N = int(input())
graph = [list(map(int, input().strip())) for _ in range(N)]
visited = [[False] * N for _ in range(N)]
house = []
town = 0

for row in range(N):
    for col in range(N) :
        if graph[row][col] == 1 and not visited[row][col]:
            town +=1
            house.append(bfs(row, col))

house.sort()
print(town)
print(*house, sep="\n")
```
- `bfs` 함수는 특정 시작점에서 연결된 단지의 집 수를 계산하여 반환한다.
- 이중 for문을 통해 지도의 모든 좌표를 확인하며, 아직 방문하지 않은 집을 찾을 때마다 새로운 `bfs`를 호출하여 단지를 찾는다.
- `visited` 배열을 통해 한 번 단지에 포함된 집은 다시 탐색하지 않도록 한다.
- `house` 리스트에 각 단지의 집 수를 저장한 뒤, 마지막에 정렬하여 출력 형식에 맞게 출력한다.
