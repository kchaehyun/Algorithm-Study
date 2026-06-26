# BOJ 11399 - ATM

## 📝 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/11399)
- N명의 사람이 줄을 서서 돈을 인출하려 한다.
- i번째 사람이 돈을 인출하는 데 걸리는 시간이 주어질 때, **모든 사람이 돈을 인출하는 데 필요한 시간의 합의 최솟값**을 구하는 문제.

## 💡 아이디어
- 앞사람이 늦게 걸리면 뒤사람 모두에게 영향을 준다.
- 따라서 시간이 작은 사람부터 먼저 처리하는 게 최적이다 → **그리디 알고리즘**.
- 정렬 후, 각 사람이 걸린 시간의 누적합을 더하면 된다.

## 🔑 풀이 과정
1. N 입력.
2. 인출 시간 배열 입력 후 오름차순 정렬.
3. 각 사람의 대기 시간을 누적합 배열(`arr2`)에 저장.
4. 누적합의 총합을 계산해 출력.

## 🐍 코드 설명
```python
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()
arr2 = [0 for _ in range(N)]
sum = 0

for i in range(N):
    for j in range(i+1):
        arr2[i] += arr[j]

for i in range(N):
    sum += arr2[i]
print(sum)
```
- arr.sort() → 시간이 작은 사람부터 인출.

- arr2[i] → i번째 사람이 걸린 누적 시간.

- 최종적으로 모든 누적 시간을 합산.

- 이중 for문 대신, prefix_sum 변수를 하나 두고 바로 누적하면 O(N)으로 해결 가능.
### 개선된 코드
```python
import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr.sort()

total, prefix = 0, 0
for t in arr:
    prefix += t
    total += prefix
print(total)
```