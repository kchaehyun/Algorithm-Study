# BOJ 5568 - 카드 놓기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/5568)
- n장의 카드 중에서 k장을 선택해 일렬로 놓을 때, 만들 수 있는 서로 다른 정수의 개수를 구하는 문제.
- 예를 들어, 카드가 [1, 2, 12]이고 k=2라면 만들 수 있는 수는 {112, 121, 212}와 같이 중복 없는 개수를 세야 한다.

## 아이디어
- 단순 조합이 아니라 **순열(permutation)** 문제 → 순서가 다르면 다른 수로 취급.
- 같은 숫자가 카드에 있을 수도 있으므로, 중복을 없애기 위해 `set`을 사용.
- 각 순열을 문자열로 이어붙여 정수처럼 처리.

## 풀이 과정
1. n, k 입력받기.
2. n장의 카드를 리스트에 저장.
3. itertools의 `permutations`를 사용해 k개를 고른 순열 생성.
4. 순열을 문자열로 합친 뒤 set에 넣어 중복 제거.
5. 최종적으로 set의 크기를 출력.

## 코드 설명
```python
import sys
from itertools import permutations
input = sys.stdin.readline

n = int(input())
k = int(input())
cards = [int(input()) for _ in range(n)]
comb = set()
    
for i in permutations(cards, k):
    comb.add(''.join(map(str, i)))
    
print(len(comb))
```
- permutations(cards, k) → 카드 중 k장을 선택해 나열한 모든 경우 생성.

- map(str, i) → 정수형 카드를 문자열로 변환 후 이어붙임.

- set에 넣어 중복 제거.

- len(comb) → 서로 다른 정수 개수 출력.