# BOJ 1065 - 한수

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1065)
- 어떤 양의 정수가 각 자리가 등차수열을 이루면 그 수를 "한수"라고 한다.
- N 이하의 한수의 개수를 구하는 문제.

## 아이디어
- **1~99까지는 모두 한수** → 두 자리 수까지는 무조건 등차수열 성립.
- **100 이상부터**는 백의 자리, 십의 자리, 일의 자리를 분리해서  
  `(hundred - ten) == (ten - one)` 조건이 맞는지 확인.
- 100부터 N까지 순회하며 조건을 만족하면 카운트.

## 풀이 과정
1. N을 입력받음.
2. N < 100 → 답은 그냥 N.
3. N ≥ 100 → 기본으로 99개(1~99) 포함.
4. 100부터 N까지 순회:
   - 백, 십, 일의 자리 분리
   - 등차 조건 맞으면 카운트 증가
5. 결과 출력.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N = int(input())
ans = N
if N >= 100:
    ans = 99
    idx = 100
    while idx <= N:
        hundred = idx // 100
        ten = (idx // 10) % 10
        one = idx % 10
        if hundred - ten == ten - one:
            ans += 1
        idx += 1
print(ans)
```
- hundred, ten, one: 각 자리수 분리

- (hundred - ten) == (ten - one) → 등차수열 조건

- while문으로 100부터 N까지 순회하면서 카운트
