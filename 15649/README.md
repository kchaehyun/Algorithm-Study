# BOJ 15649 - N과 M (1)
- [문제 링크](https://www.acmicpc.net/problem/15649)
- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하는 프로그램을 작성하시오.

## 아이디어
- 1부터 N까지의 숫자 중에서 M개를 뽑아 나열하는 순열(Permutation)을 구하는 문제이다.
- Python의 `itertools` 라이브러리에 있는 `permutations` 함수를 사용하면 간단하게 해결할 수 있다.
- 또는, 백트래킹(Backtracking) 알고리즘을 사용하여 직접 순열을 구현할 수도 있다.

## 풀이 과정
### 1. `itertools.permutations` 사용
1. 1부터 N까지의 숫자를 담은 리스트를 생성한다.
2. `permutations` 함수에 이 리스트와 M을 인자로 넘겨 모든 순열을 구한다.
3. 결과를 반복하면서 형식에 맞게 출력한다.

### 2. 백트래킹 사용
1. 현재 수열을 저장할 리스트와 숫자의 사용 여부를 체크할 `visited` 배열을 준비한다.
2. 재귀 함수를 정의한다.
    a. 만약 현재 수열의 길이가 M과 같다면, 수열을 출력하고 함수를 종료한다.
    b. 1부터 N까지의 숫자를 순회한다.
    c. 아직 사용하지 않은 숫자라면, 수열에 추가하고 `visited`를 `True`로 변경한 후 재귀 호출한다.
    d. 재귀 호출이 끝나면, 다음 경우의 수를 위해 수열에서 숫자를 다시 빼고 `visited`를 `False`로 되돌려 놓는다 (백트래킹).

## 코드 설명
```python
import sys
from itertools import permutations
input = sys.stdin.readline

N, M = map(int, input().split())
arr = []
for i in range(1,N+1):
    arr.append(i)

nPr = list(permutations(arr, M))
for a in nPr:
    print(' '.join(map(str,a)))
```
- 이 코드는 `itertools.permutations`를 사용하는 방법이다.
- 1부터 N까지의 숫자를 `arr` 리스트에 저장한다.
- `permutations(arr, M)`을 호출하여 `arr`에서 M개의 원소로 이루어진 모든 순열을 생성한다.
- `nPr`에 저장된 각 순열(튜플 형태)을 `map(str, a)`를 통해 문자열로 변환하고, `' '.join()`을 사용하여 공백으로 구분된 문자열로 만들어 출력한다.
