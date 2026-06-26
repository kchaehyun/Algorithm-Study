# BOJ 1764 - 듣보잡

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1764)
- 듣도 못한 사람의 명단과 보도 못한 사람의 명단이 주어질 때, 두 명단에 모두 포함된 사람(듣보잡)을 구하는 문제이다.

## 아이디어
- 두 명단을 각각 `set`으로 저장한다.
- 두 집합의 교집합을 구한다.
- 교집합을 사전순으로 정렬하여 출력한다.

## 시간복잡도
- 명단 `N, M`에 대해 각각 `set`을 생성하는 데 `O(N + M)`.
- 교집합 계산에 `O(min(N, M))`.
- 정렬에 `O(K log K)` (K는 교집합의 크기).
- 전체적으로 `O(N + M + K log K)`이다.

## 풀이 과정
1. `N`과 `M`을 입력받는다.
2. `N`명의 듣도 못한 사람 이름을 입력받아 `listen` 집합에 저장한다.
3. `M`명의 보도 못한 사람 이름을 입력받아 `seen` 집합에 저장한다.
4. 두 집합의 교집합(`listen & seen`)을 구한다.
5. 교집합 결과를 리스트로 변환하고 사전순으로 정렬한다.
6. 결과의 개수와 명단을 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
listen = set(input().strip() for _ in range(N))
seen = set(input().strip() for _ in range(M))

ans = sorted(listen & seen)

print(len(ans))
print('\n'.join(ans))
```
- `set` 자료형을 사용하여 중복을 제거하고 교집합 연산을 효율적으로 수행한다.
- `sorted()`는 리스트를 반환하므로 정렬된 결과를 바로 활용할 수 있다.
