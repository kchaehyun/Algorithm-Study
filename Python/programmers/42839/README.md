# Programmers 42839 - 소수 찾기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42839)
- 문자열 `numbers`의 각 자릿수를 조합해 만들 수 있는 모든 수 중 소수의 개수를 구한다.
- 같은 숫자가 중복 생성될 수 있으므로 중복 제거가 필요하다.

## 아이디어
- `itertools.permutations`로 길이 1부터 전체 길이까지 모든 순열을 생성한다.
- 생성한 값을 `set`에 넣어 중복을 제거한다.
- 각 수에 대해 제곱근까지만 나누어 소수 여부를 판별한다.

## 시간복잡도
- 가능한 모든 순열을 생성하므로 입력 길이를 `n`이라 할 때 대략 O(n! * n) 수준이다.
- 각 수에 대한 소수 판별은 최대 O(sqrt(m)) (`m`은 생성된 수의 크기)이다.

## 풀이 과정
1. `numbers`를 문자 리스트로 변환한다.
2. 길이 1~n에 대해 모든 순열을 만들고 정수로 변환해 `set`에 저장한다.
3. `set`의 각 값에 대해 소수 판별 함수를 실행한다.
4. 소수인 경우 개수를 증가시켜 최종 반환한다.

## 코드 설명
```python
from math import sqrt
from itertools import permutations

def is_prime(num) :
    if num == 0 or num == 1 :
        return False
    for i in range(2, int(sqrt(num)) + 1) :
        if num % i == 0:
            return False
    return True

def solution(numbers):
    answer = 0
    numbers = list(map(str,numbers))
    arr = set()
    for i in range(len(numbers)) :
        for p in permutations(numbers,i+1) :
            arr.add(int(''.join(p)))
    for x in arr :
        if is_prime(x) :
            answer += 1
    return answer
```
- `arr` 집합으로 중복 숫자를 제거한다.
- `is_prime`은 0, 1을 제외하고 `sqrt(num)`까지만 검사해 효율적으로 소수 여부를 판단한다.
