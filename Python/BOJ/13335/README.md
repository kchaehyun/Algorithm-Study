# BOJ 13335 - 트럭

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/13335)
- 강을 가로지르는 하나의 차선이 있는 다리를 모든 트럭이 건너는 데 걸리는 최소 시간을 구하는 문제이다.
- 다리에는 최대 `w`대의 트럭이 올라갈 수 있으며, 다리의 길이는 `w` 단위 길이이다.
- 다리 위에 올라가 있는 트럭들의 무게 합은 다리의 최대 하중 `L`보다 작거나 같아야 한다.

## 아이디어
- 다리의 상태를 `w` 크기의 큐(Queue)로 모델링한다. 초기 상태는 모두 0으로 채워진 리스트이다.
- 매 초마다 다리 위에서 한 칸씩 이동하며, 맨 앞(다리를 다 건넌) 트럭의 무게를 현재 다리 위 총 무게에서 뺀다.
- 대기 중인 트럭이 있고, 새 트럭이 들어왔을 때 하중 `L`을 초과하지 않는다면 트럭을 다리에 올린다.
- 하중을 초과한다면 트럭 대신 0을 다리에 올려 빈 공간으로 보낸다.

## 시간복잡도
- 각 트럭은 다리에 올라가서 건너는 데 `w`만큼의 시간이 걸린다.
- 전체 트럭의 수가 `n`일 때, 최악의 경우에도 각 트럭이 다리에 머무는 시간과 대기 시간을 고려하면 충분히 제한 시간 내에 해결 가능하다.

## 풀이 과정
1. 트럭 수 `n`, 다리 길이 `w`, 최대 하중 `L`을 입력받는다.
2. 트럭들의 무게를 `deque`에 저장한다.
3. 다리를 의미하는 `queue`를 `[0] * w`로 초기화한다.
4. `trucks`가 남아있거나 `weights`(다리 위 총 무게)가 0보다 클 동안 반복한다.
5. `time`을 1씩 증가시킨다.
6. 다리의 가장 왼쪽 값을 `popleft()`하여 무게 합에서 뺀다.
7. 다음 트럭이 올라올 수 있으면 (`weights + trucks[0] <= L`):
    - 트럭을 `append()`하고 무게 합에 더한다.
8. 올라올 수 없으면 0을 `append()`한다.
9. 최종 `time`을 출력한다.

## 코드 설명
```python
import sys
from collections import deque
input = sys.stdin.readline

n, w, L = map(int, input().split())
trucks = deque(list(map(int, input().split())))
queue = deque([0] * w)
time = 0
weights = 0
while trucks or weights > 0:
    time += 1
    weights -= queue.popleft()
    if trucks and weights + trucks[0] <= L :
        queue.append(trucks[0])
        weights += trucks[0]
        trucks.popleft()
    else :
        queue.append(0)

print(time)
```
- `weights` 변수를 따로 관리하여 매번 `sum(queue)`를 계산하는 오버헤드를 줄였다.
- `deque`를 사용하여 `popleft()` 연산을 `O(1)`로 처리했다.
