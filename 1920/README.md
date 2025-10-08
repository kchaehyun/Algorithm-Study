# BOJ 1920 - 수 찾기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1920)
- N개의 정수로 이루어진 배열 A가 주어졌을 때, M개의 다른 수들이 각각 배열 A 안에 존재하는지 알아내는 문제이다. 존재하면 1, 존재하지 않으면 0을 출력한다.

## 아이디어
- **이분 탐색(Binary Search)**: 배열 A를 정렬한 후, M개의 각 수에 대해 이분 탐색을 수행하여 존재 여부를 확인한다. 이분 탐색은 시간 복잡도가 O(log N)이므로 효율적이다.
- **해시(Hash Set)**: Python의 `set` 자료구조를 사용한다. 배열 A를 `set`으로 변환하면, 특정 원소의 존재 여부를 평균 O(1)의 시간 복잡도로 확인할 수 있다. 이 방법이 일반적으로 더 빠르고 코드가 간결하다.

## 시간복잡도
- **이분 탐색**: O((N+M) log N) - 배열 정렬에 O(N log N), M개의 수에 대한 이분 탐색에 O(M log N)이 소요된다.
- **해시(Set)**: O(N + M) - N개의 수를 set에 넣는데 O(N), M개의 수를 탐색하는데 O(M)이 소요된다.

## 풀이 과정
### 1. 이분 탐색을 이용한 풀이
1. N개의 정수를 입력받아 리스트 `A_N`에 저장하고 정렬한다.
2. M개의 정수를 입력받아 리스트 `X_N`에 저장한다.
3. `X_N`의 각 원소 `x`에 대해 `A_N`에서 이분 탐색을 수행한다.
4. `bisect_left`를 사용하여 `x`가 `A_N`에 삽입될 위치를 찾는다.
5. 해당 위치에 있는 값이 `x`와 일치하는지 확인하여 존재 여부를 판단하고 1 또는 0을 출력한다.

### 2. 해시(Set)를 이용한 풀이
1. N개의 정수를 입력받아 `set` 자료구조 `A_N`에 저장한다.
2. M개의 정수를 입력받아 리스트 `X_N`에 저장한다.
3. `X_N`의 각 원소 `x`가 `set` `A_N`에 존재하는지 (`x in A_N`) 확인한다.
4. 존재하면 1, 존재하지 않으면 0을 출력한다.

## 코드 설명
### 1. 이분 탐색 코드
```python
import sys
from bisect import bisect_left
input = sys.stdin.readline

N = int(input())
A_N = sorted(map(int, input().split()))
M = int(input())
X_N = list(map(int, input().split()))

for x in X_N :
    i = bisect_left(A_N, x) # x가 들어갈 위치
    if i < N and x == A_N[i] : # 그 자리에 x가 있는 경우
        print(1)
    else:
        print(0)
```
- `bisect_left` 함수는 정렬된 리스트에서 특정 원소가 삽입될 가장 왼쪽 인덱스를 반환한다.
- 이분 탐색을 통해 찾은 인덱스 `i`가 리스트 범위 내에 있고, `A_N[i]`의 값이 `x`와 같은지를 검사하여 `x`의 존재 유무를 최종적으로 확인한다.

### 2. 해시(Set) 코드
```python
import sys
input = sys.stdin.readline

N = int(input())
# 파이썬의 set은 해시 탐색이라 평균 시간복잡도 O(1)
A_N = set(map(int, input().split()))
M = int(input())
X_N = list(map(int, input().split()))

for x in X_N :
    if x in A_N :
        print(1)
    else:
        print(0)
```
- 입력받은 첫 번째 숫자 리스트를 `set`으로 변환하여 탐색 시간을 줄인다.
- `in` 연산자를 사용하여 `set`에 각 숫자가 존재하는지 O(1)의 평균 시간 복잡도로 확인한다.
