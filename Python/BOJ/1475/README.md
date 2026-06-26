# BOJ 1475 - 방 번호

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1475)
- 방 번호를 만들기 위해 필요한 숫자 세트(0-9)의 최소 개수를 구하는 문제이다.
- 단, 6과 9는 서로 뒤집어서 사용할 수 있다.

## 아이디어
- 각 숫자의 개수를 센다.
- 6과 9는 합쳐서 계산한 뒤 2로 나눈다 (올림 처리).
- 가장 많이 필요한 숫자의 개수가 곧 필요한 세트의 수이다.

## 시간복잡도
- 방 번호의 길이를 `L`이라 할 때, `O(L)`이다.

## 풀이 과정
1. 방 번호 `N`을 입력받는다.
2. `collections.Counter`를 사용하여 각 숫자의 빈도를 계산한다.
3. 6과 9의 빈도를 합쳐 `six_nine`에 저장한다.
4. `(six_nine + 1) // 2`를 통해 6과 9를 충당하기 위해 필요한 세트 수를 구하고, 이를 `c['6']`에 업데이트한다. (`c['9']`는 0으로 만든다)
5. `Counter` 객체의 값들 중 최대값을 출력한다.

## 코드 설명
```python
import sys
from collections import Counter
input = sys.stdin.readline

N = input().strip()
c = Counter(N)

six_nine = c['6'] + c['9']

c['6'] = (six_nine + 1) // 2
c['9'] = 0

print(max(c.values()))
```
- 6과 9를 하나의 숫자로 취급하여 세트 수를 계산하는 것이 핵심이다.
- `(total + 1) // 2`는 `math.ceil(total / 2)`와 같은 결과를 낸다.
