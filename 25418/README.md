# BOJ 25418 - 정수 a를 k로 만들기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/25418)
- 정수 A를 시작점으로 하여 K를 만들고자 한다.
- 사용할 수 있는 연산
  1. 현재 수에 +1을 한다.
  2. 현재 수에 ×2를 한다.
- 최소 연산 횟수를 출력하는 문제.

## 아이디어
- **최단 경로 문제**이므로 BFS를 사용한다.
- 시작점 A에서 출발하여 두 가지 연산을 통해 K에 도달할 때까지 탐색한다.
- BFS는 레벨 단위로 탐색하므로 처음 K에 도달한 순간이 최소 연산 횟수이다.

## 풀이 과정
1. 입력으로 A, K를 받는다.
2. `visited` 배열을 만들어 이미 방문한 수는 다시 탐색하지 않도록 한다.
3. BFS 큐에는 `(현재 값, 연산 횟수)`를 저장한다.
4. 큐에서 원소를 꺼내 현재 값이 K와 같으면 연산 횟수를 출력하고 종료한다.
5. 현재 값에서:
   - `+1` 한 값이 K 이하이고 아직 방문하지 않았다면 큐에 추가하고 방문 처리한다.
   - `*2` 한 값이 K 이하이고 아직 방문하지 않았다면 큐에 추가하고 방문 처리한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

def bfs(start, target):
    queue = deque([(start, oper)])
    visited[start] = True
    while queue : 
        s, o = queue.popleft()
        if s == target:
            print(o)
            return
        if s+1 <= target and not visited[s+1]:
            visited[s+1] = True
            queue.append((s+1, o+1))
        if s*2 <= target and not visited[s*2]:
            visited[s*2] = True
            queue.append((s*2, o+1))

A, K = map(int, input().split())
visited = [False] * (K+2)
oper = 0
bfs(A, K)
```
- `bfs(start, target)`: 시작점 `start`에서 목표 `target`까지의 최소 연산 횟수를 찾는 함수.
- `queue = deque([(start, oper)])`: BFS를 위한 큐. `(현재 값, 연산 횟수)`를 쌍으로 저장.
- `visited`: 이미 방문한 숫자를 다시 방문하지 않도록 체크하는 배열.
- `s+1`, `s*2`: 두 가지 연산을 각각 수행하고, 결과값이 목표값 `K` 이하이고 아직 방문하지 않은 경우에만 큐에 추가.
- `s == target`: 현재 값이 목표 값과 같아지면, 그때의 연산 횟수 `o`를 출력하고 함수를 종료.