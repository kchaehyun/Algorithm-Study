# BOJ 1213 - 팰린드롬 만들기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1213)
- 주어진 문자열의 알파벳들을 재배열하여 팰린드롬을 만들 수 있는지 확인하는 문제.
- 팰린드롬이 가능하다면, 사전 순으로 가장 앞서는 팰린드롬을 출력해야 한다.
- 만들 수 없다면 `"I'm Sorry Hansoo"`를 출력한다.

## 아이디어
- 팰린드롬의 특성:
  - 문자열 길이가 **짝수** → 모든 문자의 빈도가 짝수여야 함.
  - 문자열 길이가 **홀수** → 한 문자만 홀수 빈도를 가지며, 나머지는 모두 짝수여야 함.
- 따라서:
  1. 각 문자 개수를 센다.
  2. 홀수 개수 조건을 만족하는지 검사.
  3. 조건을 만족하면 반쪽(`half`)을 만든 뒤 뒤집어서 붙인다.
  4. 홀수 길이의 경우 가운데(`middle`)에 홀수 문자를 추가한다.
- **사전 순 정렬**을 위해 `sorted(counter.keys())` 순서대로 처리.

## 풀이 과정
1. 문자열 입력받기.
2. `collections.Counter`를 사용해 알파벳 개수를 센다.
3. 문자열 길이에 따라 조건 분기:
   - 짝수 길이 → 홀수 빈도가 있으면 불가능.
   - 홀수 길이 → 홀수 빈도가 2개 이상이면 불가능.
4. 반쪽 문자열(`half`)을 만들어 나머지 절반을 뒤집어 붙인다.
5. 홀수 길이인 경우 `middle` 문자를 가운데에 추가.
6. 팰린드롬 출력, 불가능하면 `"I'm Sorry Hansoo"` 출력.

## 코드 설명
```python
import sys
from collections import Counter
input = sys.stdin.readline

name = str(input()).rstrip()
counter = Counter(name)
half = []
possible = True

if len(name) % 2 == 0: 
    for k in sorted(counter.keys()):
        if counter[k] % 2 == 1:
            possible = False
            break
        half.append(k * (counter[k]//2))
    if possible:
        half = ''.join(half)
        print(half + half[::-1])
    else:
        print("I'm Sorry Hansoo")
else:
    odd = 0
    for k in sorted(counter.keys()):
        if counter[k] % 2 == 1:
            odd += 1
            middle = k
        if odd > 1:
            possible = False
            break
        half.append(k * (counter[k]//2))
    if possible:
        half = ''.join(half)
        print(half + middle + half[::-1])
    else:
        print("I'm Sorry Hansoo")
```
- Counter(name) → 문자별 개수 카운트.

- sorted(counter.keys()) → 사전 순 정렬 보장.

- 짝수/홀수 길이 분기 처리.

- half + half[::-1] → 팰린드롬 완성.