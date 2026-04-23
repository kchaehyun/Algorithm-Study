# BOJ 1181 - 단어 정렬

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1181)
- 알파벳 소문자로 이루어진 `N`개의 단어가 주어질 때, 다음 조건에 따라 정렬하는 문제이다.
  1. 길이가 짧은 것부터
  2. 길이가 같으면 사전 순으로
- 단, 중복된 단어는 하나만 남기고 제거해야 한다.

## 아이디어
- 입력받은 단어들을 `set`을 사용하여 중복을 제거한다.
- `sorted()` 함수의 `key` 파라미터를 사용하여 정렬 기준을 설정한다.
- `lambda` 식을 활용해 `(len(x), x)` 순으로 정렬 기준을 부여한다.

## 시간복잡도
- 단어의 개수 `N`이 최대 20,000이다.
- 중복 제거 및 정렬 과정이 주를 이루며, 정렬의 시간복잡도는 `O(N log N)`이다.

## 풀이 과정
1. 단어의 개수 `N`을 입력받는다.
2. `N`개의 단어를 입력받아 리스트에 저장한다.
3. `set(words)`를 통해 중복된 단어를 제거한 뒤 다시 리스트로 변환한다.
4. `sorted(words, key=lambda x: (len(x), x))`를 수행하여 길이 순, 사전 순으로 정렬한다.
5. 정렬된 결과를 한 줄씩 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N = int(input())
words = [input().strip() for _ in range(N)]
words = list(set(words)) # 중복 제거
words = sorted(words, key=lambda x: (len(x), x)) # 길이 순, 사전 순 정렬
for word in words:
    print(word)
```
- `sys.stdin.readline`을 사용하여 입력 속도를 높였다.
- `set` 자료형으로 중복을 효율적으로 제거했다.
- `sorted`의 `key` 인자에 튜플을 반환하는 람다 함수를 전달하여 다중 정렬 조건을 구현했다.
