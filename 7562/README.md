# BOJ 7562 - 나이트의 이동

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/7562)
- 체스판의 한 위치에서 다른 위치까지 나이트가 최소 몇 번 이동해야 하는지 구하는 문제이다.
- 나이트는 체스에서 이동하는 방식처럼 한 방향으로 2칸, 수직 방향으로 1칸 이동한다.

## 아이디어
- 모든 이동의 비용이 1로 동일하므로 BFS를 사용하면 최단 이동 횟수를 구할 수 있다.
- 큐에는 현재 위치와 지금까지 이동한 횟수를 함께 저장한다.
- 도착 위치를 처음 만나는 순간의 이동 횟수가 최소 이동 횟수이다.

## 풀이 과정
1. 테스트 케이스 개수 `T`를 입력받는다.
2. 각 테스트 케이스마다 체스판 크기, 시작 위치, 도착 위치를 입력받는다.
3. 방문 여부를 저장하는 `visited` 배열을 만든다.
4. 시작 위치를 방문 처리하고 큐에 `(x, y, 이동 횟수)` 형태로 넣는다.
5. 큐에서 위치를 하나씩 꺼내 도착 위치인지 확인한다.
6. 도착 위치라면 현재 이동 횟수를 반환한다.
7. 나이트가 이동할 수 있는 8가지 방향을 확인한다.
8. 체스판 범위 안이고 아직 방문하지 않은 위치라면 방문 처리 후 큐에 넣는다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def move(sx,sy,ex,ey, l) :
    dx = [1, 2, -1, -2, 1, 2, -1, -2]
    dy = [2, 1, 2, 1, -2, -1, -2, -1]
    visited[sy][sx] = True
    queue = deque([(sx,sy,0)])
    while queue:
        x, y, m = queue.popleft()
        if x == ex and y == ey :
            return m
        for i in range(8) :
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < l and 0 <= ny < l and not visited[ny][nx] :
                visited[ny][nx] = True
                queue.append((nx,ny,m+1))

T = int(input())
for _ in range(T) :
    chessboard = int(input())
    start_x, start_y = map(int,input().split())
    end_x, end_y = map(int,input().split())
    visited = [[False]*chessboard for _ in range(chessboard)]
    print(move(start_x,start_y,end_x,end_y,chessboard))
```
- `dx`, `dy` 배열은 나이트가 이동할 수 있는 8가지 방향을 나타낸다.
- `queue`에는 현재 좌표와 이동 횟수 `m`을 함께 저장한다.
- BFS는 가까운 위치부터 탐색하므로 도착점을 처음 발견했을 때의 `m`이 최소 이동 횟수이다.
- `visited[ny][nx]`를 통해 이미 확인한 위치를 다시 큐에 넣지 않는다.

