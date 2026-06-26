# BOJ 1026 - 보물

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1026)
- 두 수열 A, B가 주어진다.
- A의 원소는 자유롭게 재배열할 수 있지만, B의 원소는 재배열하지 않고 원래 순서를 유지해야 한다.
- ∑ A[i] × B[i] 의 최솟값을 구하는 문제.

---

## 아이디어
- A는 정렬이 가능하므로, 가장 작은 수를 가장 큰 수와 곱해주면 합이 최소화된다.
- 즉, **작은 A × 큰 B** 매칭 전략이 필요하다.
- 하지만 문제에서 "B는 재배열하지 않는다" 조건이 있으므로 B를 직접 정렬해서 쓰면 안 된다.
- 따라서 **B에서 가장 큰 값을 찾아 A의 가장 작은 값과 곱해주는 방식**으로 구현해야 한다.

---

## 풀이 과정
1. N 입력받기.
2. 배열 A, B 입력받기.
3. A는 오름차순 정렬.
4. B는 원래 순서를 유지하면서, 가장 큰 원소를 골라 A의 가장 작은 값과 곱한다.
5. 선택된 B 원소는 다시 사용하지 않도록 표시.
6. 모든 A, B를 사용한 뒤 최솟값을 출력.

---

## 코드 설명
### 풀이 1) B를 정렬한 경우
```python
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
B.sort(reverse=True)  # B를 정렬 (조건 위반)
ans = 0

for i in range(N):
    ans += A[i] * B[i]

print(ans)
```
- 이 풀이도 “작은 A × 큰 B” 전략을 직접 구현하긴 했지만, B를 정렬해버렸기 때문에 원래 B의 순서가 보존되지 않아 조건 위반이 된다.

### 풀이 2) B를 정렬하지 않는 경우
```python
import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

A.sort()
ans = 0

for i in range(N):
    max_b = max(B)              # 현재 남은 B 중 가장 큰 값
    ans += A[i] * max_b
    B[B.index(max_b)] = -1      # 사용한 값은 다시 못 쓰게 표시

print(ans)
```
- A는 정렬했지만, B는 원래 순서를 유지.

- max(B)로 가장 큰 값을 찾아 매칭.

- B.index(max_b)로 해당 원소를 찾아 -1로 변경해 중복 사용 방지.