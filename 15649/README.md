# BOJ 15649 - N과 M (1)

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/15649)
- 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열을 모두 구하는 문제이다.

## 아이디어
- 백트래킹을 사용하여 해결한다.
- 재귀 함수를 이용하여 모든 경우의 수를 탐색한다.

## 풀이 과정
1. 1부터 N까지의 자연수를 배열에 담는다.
2. 방문 여부를 체크하는 배열 `visited`를 만든다.
3. 재귀 함수 `dfs`를 통해 수열을 만든다.
4. `dfs` 함수에서는 `pick` 개수만큼 숫자를 고른다.
5. 숫자를 고를 때마다 `visited` 배열에 방문 표시를 한다.
6. `pick`이 0이 되면 수열을 출력하고, 이전 상태로 돌아가기 위해 마지막에 추가한 숫자를 빼고 `visited` 배열도 원래대로 돌린다.

## 코드 설명
```python
import sys
from itertools import permutations
input = sys.stdin.readline

def dfs(arr, pick) :
    if pick == 0:
        print(*result)
        return
    for a in arr:
        if not visited[a]:
            result.append(a)
            visited[a] = True
            dfs(arr, pick-1)
            result.pop()
            visited[a] = False

N, M = map(int, input().split())
arr = []
result = []
for i in range(1,N+1):
    arr.append(i)

visited = [False] * (N+1)
dfs(arr, M)
```
- `dfs` 함수를 통해 백트래킹을 구현하여 모든 경우의 수를 탐색한다.
- `visited` 배열을 통해 이미 사용한 숫자인지 확인한다.