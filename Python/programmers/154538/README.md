# Programmers 154538 - 숫자 변환하기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/154538)
- 자연수 `x`, `y`, `n`이 주어진다.
- `x`에 `n`을 더하거나, 2를 곱하거나, 3을 곱하는 연산을 사용할 수 있다.
- `x`를 `y`로 만들기 위한 최소 연산 횟수를 반환한다.
- 만들 수 없다면 `-1`을 반환한다.

## 아이디어
- 모든 연산의 비용이 1로 같으므로 BFS를 사용하면 최소 횟수를 구할 수 있다.
- 현재 값에서 가능한 다음 값은 `num + n`, `num * 2`, `num * 3`이다.
- `y`보다 큰 값은 더 이상 볼 필요가 없다.
- 같은 값을 반복해서 방문하지 않도록 `visited` 배열을 사용한다.

## 시간복잡도
- `x`부터 `y`까지 가능한 값을 최대 한 번씩 방문하므로 O(Y)이다.

## 풀이 과정
1. 큐에 시작 값 `(x, 0)`을 넣는다.
2. `visited[x]`를 `True`로 표시한다.
3. 큐에서 현재 값과 연산 횟수를 꺼낸다.
4. 현재 값이 `y`라면 연산 횟수를 반환한다.
5. `num + n`, `num * 2`, `num * 3`이 `y` 이하이고 방문하지 않았다면 큐에 넣는다.
6. 큐가 빌 때까지 `y`를 만들지 못하면 `-1`을 반환한다.

## 코드 설명
```python
from collections import deque

def solution(x, y, n):
    q = deque([(x,0)])
    visited = [False]*(y+1)
    visited[x] = True
    while q:
        num, op = q.popleft()
        if num == y:
            return op
        if num + n <= y and not visited[num+n] :
            visited[num+n] = True
            q.append((num+n,op+1))
        if num * 2 <= y and not visited[num*2] :
            visited[num*2] = True
            q.append((num*2,op+1))
        if num * 3 <= y and not visited[num*3] :
            visited[num*3] = True
            q.append((num*3,op+1))
    return -1
```
- `q`에는 현재 숫자와 해당 숫자까지 도달하는 데 사용한 연산 횟수를 저장한다.
- `visited`는 이미 만든 숫자를 다시 큐에 넣지 않기 위해 사용한다.
- BFS는 가까운 연산 횟수부터 탐색하므로 처음 `y`를 만나는 순간이 최소 횟수이다.
