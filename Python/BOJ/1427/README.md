# BOJ 1427 - 소트인사이드

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1427)
- 주어지는 수의 각 자릿수를 내림차순으로 정렬하는 문제이다.

## 아이디어
- 입력받은 숫자를 문자열로 취급하여 각 문자를 리스트로 만든다.
- 리스트를 내림차순 정렬한 뒤 다시 합쳐서 출력한다.

## 시간복잡도
- 숫자의 길이를 `L`이라 할 때, 정렬 시 `O(L log L)`이 소요된다.
- `L`은 최대 10이므로 매우 빠르다.

## 풀이 과정
1. 숫자를 문자열로 입력받는다.
2. `sorted()` 함수를 사용하여 내림차순(`reverse=True` 또는 `-int(x)`)으로 정렬한다.
3. 정렬된 문자들을 `join`하여 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N = str(input().strip())
print(''.join(sorted(N, key=lambda x:-int(x))))
```
- `sorted(N, key=lambda x:-int(x))`를 통해 각 문자를 정수로 변환한 값의 부호를 바꿔 내림차순 정렬 효과를 낸다.
- `reverse=True` 옵션을 사용하는 것과 동일하다.
