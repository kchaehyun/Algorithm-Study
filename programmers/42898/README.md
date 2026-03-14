# Programmers 42898 - 등굣길

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42898)
- `m x n` 격자에서 시작점 `(1,1)`에서 도착점 `(m,n)`까지 이동하는 경우의 수를 구한다.
- 물웅덩이 좌표는 지나갈 수 없다.
- 이동은 오른쪽 또는 아래쪽만 가능하며, 결과는 `1,000,000,007`로 나눈 나머지를 반환한다.

## 아이디어
- `dp[y][x]`를 해당 칸까지 오는 경로 수로 정의한다.
- 현재 칸 경로 수 = 위쪽 칸 경로 수 + 왼쪽 칸 경로 수.
- 물웅덩이 칸은 계산에서 제외한다.

## 시간복잡도
- O(m*n)

## 풀이 과정
1. `dp` 배열을 만들고 시작점을 1로 설정한다.
2. 물웅덩이 좌표를 0-index 집합으로 변환한다.
3. 격자를 순회하며 물웅덩이가 아닌 칸의 경로 수를 누적한다.
4. 도착점 값을 `1000000007`로 나눈 값을 반환한다.

## 코드 설명
```python
def solution(m, n, puddles):
    answer = 0
    dp = [[0]*m for _ in range(n)]
    dp[0][0] = 1
    p = {(x-1,y-1) for x,y in puddles}
    
    for y in range(n) :
        for x in range(m) :
            if (x,y) in p:
                continue
            if y > 0 :
                dp[y][x] += dp[y-1][x]
            if x > 0 :
                dp[y][x] += dp[y][x-1]
                
    answer = dp[n-1][m-1] % 1000000007
    return answer
```
- DP 누적으로 중복 경로 계산을 제거해 효율적으로 경우의 수를 구한다.
- 물웅덩이는 `continue`로 건너뛰어 자연스럽게 0경로를 유지한다.
