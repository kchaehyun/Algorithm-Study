# BOJ 14502 - 연구소

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/14502)
- N x M 크기의 연구소가 주어지고, 빈 칸에는 벽을 3개 세울 수 있다.
- 바이러스는 상하좌우로 인접한 빈 칸으로 퍼진다.
- 벽을 정확히 3개 세웠을 때, 바이러스가 퍼진 뒤 남는 안전 영역의 최대 크기를 구하는 문제이다.

## 아이디어
- 빈 칸 중에서 벽을 세울 3개의 위치를 모두 선택한다.
- 각 경우마다 연구소 배열을 복사한 뒤, 선택한 위치에 벽을 세운다.
- 바이러스 위치에서 BFS를 수행해 바이러스를 퍼뜨린다.
- BFS가 끝난 뒤 남아 있는 빈 칸의 개수를 세고, 그중 최댓값을 답으로 갱신한다.

## 시간복잡도
- 빈 칸의 개수를 E라고 하면, 벽을 세우는 경우의 수는 `C(E, 3)`이다.
- 각 경우마다 배열 복사와 BFS, 안전 영역 계산에 `O(N * M)`이 걸린다.
- 따라서 전체 시간복잡도는 `O(C(E, 3) * N * M)`이다.
- 문제의 제한에서 N, M이 최대 8이므로 모든 조합을 확인해도 충분히 해결할 수 있다.

## 풀이 과정
1. 연구소 정보를 입력받아 `arr`에 저장한다.
2. 값이 0인 칸, 즉 빈 칸의 좌표를 `empty` 리스트에 저장한다.
3. `combinations(empty, 3)`을 이용해 벽을 세울 수 있는 모든 3개 조합을 만든다.
4. 각 조합마다 원본 배열을 깊은 복사한 `tmp_arr`를 만든다.
5. 선택된 3개의 빈 칸을 벽으로 바꾼다.
6. `bfs(tmp_arr)`를 실행해 바이러스를 퍼뜨린다.
7. `tmp_arr`에 남아 있는 0의 개수를 세어 안전 영역 크기를 구한다.
8. 안전 영역 크기의 최댓값을 `ans`에 저장하고 마지막에 출력한다.

## 코드 설명
```python
import sys
from collections import deque
from itertools import combinations
input = sys.stdin.readline

def bfs(lab):
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    queue = deque()

    for i in range(N):
        for j in range(M):
            if lab[i][j] == 2:
                queue.append((i, j))

    while queue:
        r, c = queue.popleft()
        for i in range(4):
            n_r = r + dr[i]
            n_c = c + dc[i]
            if 0 <= n_r < N and 0 <= n_c < M:
                if lab[n_r][n_c] == 0:
                    lab[n_r][n_c] = 2
                    queue.append((n_r, n_c))


N, M = map(int, input().split())
arr = []
empty = []

for _ in range(N):
    arr.append(list(map(int, input().split())))

for i in range(N):
    for j in range(M):
        if arr[i][j] == 0:
            empty.append((i, j))

ans = 0

for comb in combinations(empty, 3):
    tmp_arr = [r[:] for r in arr]

    for i, j in comb:
        tmp_arr[i][j] = 1

    bfs(tmp_arr)

    safe = 0
    for i in range(N):
        for j in range(M):
            if tmp_arr[i][j] == 0:
                safe += 1

    ans = max(ans, safe)

print(ans)
```

- `empty`: 벽을 세울 수 있는 빈 칸의 좌표를 저장한다.
- `combinations(empty, 3)`: 빈 칸 중 벽 3개를 세울 모든 경우를 만든다.
- `tmp_arr = [r[:] for r in arr]`: 원본 배열이 바뀌지 않도록 2차원 배열을 복사한다.
- `bfs(tmp_arr)`: 모든 바이러스 위치를 큐에 넣고, 상하좌우로 바이러스를 퍼뜨린다.
- `safe`: 바이러스가 모두 퍼진 뒤에도 값이 0인 칸의 개수이다.
- `ans`: 가능한 모든 벽 배치 중 안전 영역의 최대 크기이다.
