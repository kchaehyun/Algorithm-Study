# BOJ 11047 - 동전 0

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/11047)
- N개의 동전 단위가 주어지고, 합이 K가 되도록 동전을 사용해야 한다.
- 필요한 동전 개수의 최소값을 구하는 문제.
- 주어지는 동전 단위는 항상 배수 관계를 만족한다. (즉, 그리디 알고리즘 적용 가능)

## 아이디어
- 그리디 알고리즘:
  - 큰 단위 동전부터 사용하면 항상 최적해를 구할 수 있음.
- 이유: 동전 단위가 배수 관계라서, 큰 단위를 쓰지 않고 작은 단위를 여러 개 쓰는 건 불필요한 낭비.

## 풀이 과정
1. N, K 입력.
2. N개의 동전 단위를 입력받아 배열에 저장.
3. 동전을 내림차순 정렬.
4. 큰 단위부터 차례대로, K를 나누어 동전 개수 카운트.
5. 남은 K는 나머지로 갱신.
6. 최종 개수 출력.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N, K = map(int, input().split())
coins = []
ans = 0

for i in range(N): 
    coins.append(int(input()))
coins.sort(reverse=True)

for coin in coins:
    ans += K // coin
    K %= coin
        
print(ans)
```
- coins.sort(reverse=True) → 큰 단위부터 사용하기 위함.

- K // coin → 해당 동전 개수.

- K %= coin → 남은 금액 갱신.