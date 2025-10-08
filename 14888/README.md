# BOJ 14888 - 연산자 끼워넣기

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/14888)
- N개의 수와 N-1개의 연산자가 주어졌을 때, 만들 수 있는 식의 결과가 최대인 것과 최소인 것을 구하는 문제이다.
- 수의 순서는 바꾸지 않고, 연산자의 순서만 바꾸어 모든 경우의 수를 탐색해야 한다.

## 아이디어
- **깊이 우선 탐색(DFS)**과 **백트래킹(Backtracking)**을 사용한다.
- DFS를 이용해 가능한 모든 연산자 순열을 탐색한다.
- 재귀 함수는 현재까지의 계산 결과(`res`)와 남은 연산자의 개수를 인자로 받는다.
- 모든 숫자를 다 사용했을 때(재귀 깊이가 N이 되었을 때), 계산된 결과값을 이용해 최댓값과 최솟값을 갱신한다.

## 시간복잡도
- O(N!): 연산자를 배치하는 모든 경우의 수를 탐색해야 한다. N이 최대 11로 작기 때문에 시간 내에 충분히 해결 가능하다.

## 풀이 과정
1. `dfs` 함수를 정의한다. 인자로 `(현재 인덱스, 남은 덧셈, 뺄셈, 곱셈, 나눗셈 개수, 현재까지의 결과)`를 받는다.
2. `dfs` 함수 내에서, 인덱스가 N에 도달하면 모든 숫자를 사용한 것이므로, 결과값을 `max_val`과 `min_val`과 비교하여 갱신하고 재귀를 종료한다.
3. 각 연산자에 대해 남은 개수가 1개 이상이면, 해당 연산을 수행하는 재귀 호출을 한다.
   - 재귀 호출 시, 인덱스를 1 증가시키고, 사용한 연산자의 개수를 1 감소시키고, 계산된 결과를 넘겨준다.
4. 나눗셈의 경우, 문제의 조건에 따라 음수를 양수로 바꾸어 몫을 취한 후 다시 음수로 바꾸는 방식으로 처리한다.
5. 초기 `dfs` 호출은 `(1, oper[0], oper[1], oper[2], oper[3], A_N[0])`로 시작한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

def dfs(idx, add, sub, mul, div, res) :
    global max_val, min_val
    if idx == N:
        if max_val is None and min_val is None :
            max_val = res
            min_val = res
        max_val = max(max_val, res)
        min_val = min(min_val, res)
        return
    if add:
        dfs(idx+1, add-1, sub, mul, div, res + A_N[idx])
    if sub :
        dfs(idx+1, add, sub-1, mul, div, res - A_N[idx])
    if mul :
        dfs(idx+1, add, sub, mul-1, div, res * A_N[idx])
    if div :
        if res >= 0:
            dfs(idx+1, add, sub, mul, div-1, res // A_N[idx])
        else :
            dfs(idx+1, add, sub, mul, div-1, -(-res // A_N[idx]))
                

N = int(input())
A_N = list(map(int, input().split()))
oper = list(map(int, input().split()))
max_val, min_val = None, None

dfs(1, oper[0], oper[1], oper[2], oper[3], A_N[0])

print(max_val)
print(min_val)
```
- `dfs(idx, add, sub, mul, div, res)`: 재귀적으로 모든 연산 순서를 탐색하는 함수.
- `idx`: 현재 계산할 숫자의 인덱스.
- `add, sub, mul, div`: 남은 연산자의 개수.
- `res`: `idx-1`번째 숫자까지 계산한 중간 결과.
- `max_val`, `min_val`: 최댓값과 최솟값을 저장하는 전역 변수. 초기값은 `None`으로 설정하여 첫 번째 결과값으로 초기화한다.
- `if idx == N`: 모든 연산을 마친 경우, 최댓값/최솟값을 갱신하고 종료.
- 각 연산자 개수가 남아있으면(`if add:` 등), 해당 연산을 적용하여 다음 `dfs`를 재귀 호출한다.
