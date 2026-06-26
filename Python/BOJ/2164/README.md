# BOJ 2164 - 카드2

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2164)
- 1번부터 N번까지 카드가 순서대로 쌓여 있을 때, 카드가 한 장 남을 때까지 다음 동작을 반복한다.
  1. 맨 위 카드를 버린다.
  2. 그다음 맨 위 카드를 맨 아래로 옮긴다.
- 마지막에 남는 카드 번호를 구하는 문제이다.

## 아이디어
- 맨 앞에서 카드를 빼고(`popleft`), 다시 맨 뒤에 넣는(`append`) 작업이 반복된다.
- 이런 앞/뒤 연산이 많은 경우에는 리스트보다 `deque`가 효율적이다.
- 따라서 카드를 `deque(1..N)`으로 만들고, 카드가 1장 남을 때까지 시뮬레이션하면 된다.

## 풀이 과정
1. `deque`에 1부터 N까지 카드를 순서대로 넣는다.
2. 큐의 길이가 1보다 큰 동안 반복한다.
3. 맨 위 카드를 한 장 버린다 (`popleft`).
4. 다음 맨 위 카드를 꺼내 맨 아래로 보낸다 (`append(popleft())`).
5. 반복이 끝나면 남은 한 장의 카드를 출력한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
queue = deque(range(1, N + 1))

while len(queue) > 1:
    queue.popleft()
    queue.append(queue.popleft())

print(queue[0])
```
- `queue = deque(range(1, N + 1))`로 초기 카드 더미를 생성한다.
- 반복문에서 첫 번째 `popleft()`는 카드 버리기 동작이다.
- `queue.append(queue.popleft())`는 다음 카드를 맨 아래로 이동시키는 동작이다.
- 마지막에 `queue[0]`이 정답이다.
