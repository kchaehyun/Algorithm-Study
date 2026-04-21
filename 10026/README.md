# BOJ 10026 - 적록색약

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/10026)
- `N x N` 크기의 그림이 주어졌을 때, 같은 색으로 이루어진 구역의 개수를 구하는 문제이다.
- 일반 사람이 보는 경우와 적록색약인 사람이 보는 경우의 구역 수를 각각 출력한다.
- 적록색약인 사람은 빨간색(`R`)과 초록색(`G`)을 같은 색으로 본다.

## 아이디어
- 같은 색으로 상하좌우 연결된 칸들을 하나의 구역으로 본다.
- 일반 그림에서 DFS를 수행해 구역 수를 먼저 구한다.
- 이후 `G`를 `R`로 바꾼 그림을 만들어 적록색약 기준의 구역 수를 다시 구한다.
- 두 경우 모두 같은 DFS 함수를 사용할 수 있다.

## 시간복잡도
- 일반 그림과 적록색약 그림을 각각 한 번씩 탐색한다.
- 각 탐색에서 모든 칸을 최대 한 번 방문하므로 시간복잡도는 `O(N^2)`이다.

## 풀이 과정
1. `N`과 그림 정보를 입력받는다.
2. 방문 배열 `visited`를 만들고, 원본 그림의 모든 칸을 순회한다.
3. 아직 방문하지 않은 칸을 발견하면 새로운 구역이므로 `ans_1`을 1 증가시키고 DFS를 수행한다.
4. 원본 그림에서 `G`를 `R`로 바꾼 `weak_picture`를 만든다.
5. 방문 배열을 다시 초기화한다.
6. `weak_picture`를 같은 방식으로 탐색해 적록색약 기준 구역 수 `ans_2`를 구한다.
7. `ans_1`과 `ans_2`를 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

def dfs(r,c,graph) :
    visited[r][c] = True
    rgb = graph[r][c]
    stack = [(r,c)]
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    while stack :
        r,c = stack.pop()
        for i in range(4) :
            nr = r + dr[i]
            nc = c + dc[i]
            if 0 <= nr < N and 0 <= nc < len(graph[0]) and not visited[nr][nc] :
                if graph[nr][nc] == rgb :
                    visited[nr][nc] = True
                    stack.append((nr,nc))

N = int(input())
picture = []
for _ in range(N) :
    picture.append(input().strip())

visited = [[False]*len(picture[0]) for _ in range(N)]
ans_1 = 0
for i in range(N) :
    for j in range(len(picture[0])) :
        if not visited[i][j]:
            ans_1 += 1
            dfs(i,j,picture)

visited = [[False]*len(picture[0]) for _ in range(N)]
ans_2 = 0
weak_picture = [r.replace('G', 'R') for r in picture]
for i in range(N) :
    for j in range(len(weak_picture[0])) :
        if not visited[i][j]:
            ans_2 += 1
            dfs(i,j,weak_picture)

print(ans_1, ans_2)
```
- `dfs`는 시작 칸의 색을 `rgb`에 저장하고, 같은 색인 인접 칸만 방문한다.
- `stack`을 사용해 DFS를 반복문으로 구현한다.
- 일반 기준에서는 원본 `picture`를 탐색한다.
- 적록색약 기준에서는 `replace('G', 'R')`로 초록색을 빨간색으로 바꾼 뒤 같은 방식으로 탐색한다.
- 두 탐색은 서로 독립적이므로 두 번째 탐색 전에 `visited`를 다시 초기화한다.
