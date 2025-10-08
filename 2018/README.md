# BOJ 2018 - 수들의 합 5

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2018)
- 자연수 N이 주어졌을 때, 연속된 자연수의 합으로 N을 나타내는 경우의 수를 구하는 문제이다.

## 아이디어
- **투 포인터(Two Pointers)** 알고리즘을 사용한다.
- `start`와 `end` 두 개의 포인터를 사용하여 연속된 자연수의 범위를 나타낸다.
- `start`부터 `end`까지의 합 `sum`을 N과 비교하면서 포인터를 이동시킨다.
  - `sum < N`: 합이 N보다 작으므로 `end`를 1 증가시켜 합에 더해준다.
  - `sum > N`: 합이 N보다 크므로 `start`를 1 증가시켜 합에서 빼준다.
  - `sum == N`: 경우의 수를 1 증가시키고, 다음 경우를 찾기 위해 `end`를 1 증가시킨다.

## 시간복잡도
- O(N): `start`와 `end` 포인터가 각각 1부터 N까지 순차적으로 한 번씩만 이동하므로, 전체 시간 복잡도는 O(N)이다.

## 풀이 과정
1. `start`, `end` 포인터와 현재 합 `sum`을 1로 초기화한다.
2. 경우의 수를 저장할 `ans` 변수를 0으로 초기화한다.
3. `start` 포인터가 N에 도달할 때까지 아래 과정을 반복한다.
4. 현재 합 `sum`이 N보다 작으면, `end`를 1 증가시키고 `sum`에 더한다.
5. 현재 합 `sum`이 N보다 크면, `sum`에서 `start` 값을 빼고 `start`를 1 증가시킨다.
6. 현재 합 `sum`이 N과 같으면, `ans`를 1 증가시키고, 다음 경우를 탐색하기 위해 `end`를 1 증가시키고 `sum`에 더한다.
7. 반복이 끝나면 `ans`를 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N = int(input())

start, end, sum = 1, 1, 1
ans = 0
while start <= N:
    if sum < N :
        end += 1
        sum += end
    elif sum > N :
        sum -= start
        start += 1
    elif sum == N :
        ans += 1
        end += 1
        sum += end
        
print(ans)
```
- `start`, `end`: 연속된 자연수 범위의 시작과 끝을 나타내는 포인터.
- `sum`: `start`부터 `end`까지의 합.
- `ans`: N을 만들 수 있는 경우의 수.
- `while start <= N`: `start` 포인터가 N을 넘어가면 더 이상 N을 만들 수 없으므로 반복을 종료한다. 
- `sum`과 `N`을 비교하여 세 가지 경우로 나누어 포인터를 효율적으로 이동시키며 모든 경우를 탐색한다.
