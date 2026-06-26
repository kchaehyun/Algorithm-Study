# BOJ 4963 - 섬의 개수

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/4963)
- 지도가 주어졌을 때, 섬의 개수를 구하는 문제이다.
- 가로, 세로, 대각선으로 연결된 땅은 하나의 섬으로 본다.
- 입력은 여러 테스트 케이스로 주어지며, `0 0`이 입력되면 종료한다.

## 아이디어
- 2차원 격자에서 연결 요소의 개수를 구하는 문제이다.
- 땅(`1`)이면서 아직 방문하지 않은 칸을 찾으면 새로운 섬을 발견한 것이므로 정답을 1 증가시킨다.
- 해당 위치에서 DFS를 수행해 8방향으로 연결된 모든 땅을 방문 처리한다.
- 한 번 방문한 땅은 다시 탐색하지 않으므로 섬 하나당 DFS가 한 번만 시작된다.

## 시간복잡도
- 각 테스트 케이스마다 모든 칸을 최대 한 번씩 방문한다.
- 따라서 시간복잡도는 `O(w * h)`이다.

## 풀이 과정
1. `w, h`를 입력받는다.
2. `w == 0`이고 `h == 0`이면 반복을 종료한다.
3. `h x w` 크기의 지도를 입력받고, 같은 크기의 `visited` 배열을 만든다.
4. 모든 칸을 순회하면서 땅이고 아직 방문하지 않은 칸을 찾는다.
5. 새로운 땅을 발견하면 섬의 개수 `ans`를 1 증가시키고 DFS를 수행한다.
6. DFS에서는 현재 칸과 8방향으로 연결된 모든 땅을 방문 처리한다.
7. 한 테스트 케이스의 탐색이 끝나면 `ans`를 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

def dfs(graph,r,c) :
    visited[r][c] = True
    dr = [1,0,-1,0,1,1,-1,-1]
    dc = [0,1,0,-1,1,-1,1,-1]
    land = [(r,c)]
    while land :
        row,col = land.pop()
        for i in range(8) :
            nr = row + dr[i]
            nc = col + dc[i]
            if 0 <= nr < h and 0 <= nc < w and not visited[nr][nc] :
                if graph[nr][nc] == 1 :
                    land.append((nr,nc))
                    visited[nr][nc] = True


while True :
    w, h = map(int, input().split())
    if w == 0 and h == 0 :
        break
    land_map = []
    for i in range(h) :
        land_map.append(list(map(int, input().split())))
    visited = [[False]*w for _ in range(h)]
    ans = 0
    for i in range(h) :
        for j in range(w) :
            if land_map[i][j] == 1 and not visited[i][j] :
                ans += 1
                dfs(land_map,i,j)
    print(ans)
```
- `dr`, `dc` 배열을 이용해 상하좌우와 대각선을 포함한 8방향을 탐색한다.
- `land` 리스트를 스택처럼 사용해 DFS를 반복문으로 구현한다.
- `visited` 배열로 이미 같은 섬에 포함된 땅을 다시 탐색하지 않도록 한다.
- DFS 호출 횟수가 곧 섬의 개수가 되므로, 새로운 시작점을 찾을 때마다 `ans`를 증가시킨다.
