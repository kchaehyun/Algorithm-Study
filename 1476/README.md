# BOJ 1476 - 날짜 계산

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1476)
- 지구 E(1~15), 태양 S(1~28), 달 M(1~19) 세 개의 수가 주어짐.
- 이 주기는 각각 다르게 반복되며, E, S, M이 동시에 특정 값이 되는 가장 빠른 연도를 구하는 문제.

## 아이디어
- 단순 시뮬레이션으로 접근 가능.
- E, S, M 주기는 각각 15, 28, 19로 반복.
- year를 1씩 증가시키면서 e, s, m도 동시에 증가시키고, 주기를 넘으면 1로 리셋.
- e, s, m이 입력으로 주어진 값과 같아지면 종료.

## 풀이 과정
1. E, S, M 입력을 받음.
2. year, e, s, m 초기화.
3. while문을 돌면서:
   - e, s, m 각각 1씩 증가.
   - 각 값이 최대 주기를 넘어가면 1로 초기화.
   - year도 같이 증가.
4. (e, s, m) == (E, S, M)이 되면 반복 종료.
5. year 출력.

## 코드 설명
```python
import sys
input = sys.stdin.readline

E, S, M = map(int, input().split())
year = 0
e, s, m = 0, 0, 0

while True:
    e += 1
    s += 1
    m += 1
    if e == 16:
        e = 1
    if s == 29:
        s = 1
    if m == 20:
        m = 1
    year += 1
    if e == E and s == S and m == M:
        break

print(year)
```
- e, s, m은 각각 1~15, 1~28, 1~19 범위에서 반복.

- year를 1씩 증가시키며 세 값이 모두 주어진 값과 일치할 때까지 진행.
