# BOJ 2579 - 계단 오르기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2579)
- 계단 오르기 게임은 각 계단에 쓰여 있는 점수를 얻으며 꼭대기까지 오르는 게임이다.
- 계단 오르기 규칙은 다음과 같다.
    1. 계단은 한 번에 한 계단 또는 두 계단씩 오를 수 있다.
    2. 연속된 세 개의 계단을 모두 밟아서는 안 된다. (시작점은 계단에 포함되지 않음)
    3. 마지막 도착 계단은 반드시 밟아야 한다.
- 얻을 수 있는 총 점수의 최댓값을 구하는 프로그램을 작성한다.

## 아이디어
- 다이나믹 프로그래밍(Dynamic Programming)을 이용하여 문제를 해결한다.
- `dp[i]`를 `i`번째 계단까지 올랐을 때의 최대 점수로 정의한다.
- `i`번째 계단을 밟는 경우는 두 가지로 나눌 수 있다.
    1. `i-2`번째 계단을 밟고 `i`번째 계단을 밟는 경우 (`dp[i-2] + scores[i]`)
    2. `i-3`번째 계단을 밟고 `i-1`번째 계단을 밟은 후 `i`번째 계단을 밟는 경우 (`dp[i-3] + scores[i-1] + scores[i]`)
- 위 두 경우의 점수 중 더 큰 값을 `dp[i]`에 저장한다.

## 시간복잡도
- O(N)

## 풀이 과정
1. 계단의 개수와 각 계단의 점수를 입력받는다.
2. `dp` 배열을 계단의 개수만큼 생성한다.
3. 계단의 개수가 3보다 작을 경우를 예외 처리한다.
4. 점화식을 이용하여 `dp` 배열을 채운다.
   - `dp[0] = scores[0]`
   - `dp[1] = scores[0] + scores[1]`
   - `dp[2] = max(scores[0] + scores[2], scores[1] + scores[2])`
   - `dp[i] = max(dp[i-2] + scores[i], dp[i-3] + scores[i-1] + scores[i])`
5. `dp` 배열의 마지막 값을 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

stairs = int(input())
scores = [int(input()) for _ in range(stairs)]
dp = [0] * stairs
if stairs == 1:
    print(scores[0])
elif stairs == 2:
    print(scores[0] + scores[1])
    
else:
    dp[0] = scores[0]
    dp[1] = dp[0] + scores[1]
    dp[2] = max(scores[0], scores[1]) + scores[2]
    for i in range(3, stairs):
        dp[i] = max(dp[i-2]+scores[i], dp[i-3]+scores[i-1]+scores[i])
        
    print(dp[stairs-1])
```
- `dp[i]`는 `i`번째 계단까지의 최대 점수를 저장한다.
- `i`번째 계단에 도달하는 방법은 `i-2`에서 오거나, `i-1`에서 오는 경우 2가지이다.
- 단, 3개의 계단을 연속으로 밟을 수 없으므로 `i-1`에서 오는 경우는 `i-2`를 밟지 않아야 한다. 즉, `i-3 -> i-1 -> i` 순서로 밟아야 한다.
- 따라서 `i`번째 계단의 최대 점수는 `(i-2번째 계단까지의 최대 점수 + i번째 계단 점수)`와 `(i-3번째 계단까지의 최대 점수 + i-1번째 계단 점수 + i번째 계단 점수)` 중 더 큰 값이 된다.
