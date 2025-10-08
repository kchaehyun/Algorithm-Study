# BOJ 14235 - 크리스마스 선물

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/14235)
- 아이들을 만나면 가장 가치가 큰 선물을 주고, 거점에서는 선물을 충전한다.
- 입력 `a`가 0이면 아이를 만난 것이고, 0이 아니면 거점에서 `a`개의 선물을 충전하는 것이다.
- 아이에게 줄 선물이 없으면 -1을 출력한다.

## 아이디어
- **우선순위 큐(Priority Queue)**를 사용하여 해결한다.
- 선물의 가치를 저장하고, 항상 가장 가치가 큰 선물을 꺼내야 하므로 최대 힙(Max Heap)을 사용해야 한다.
- Python의 `heapq`는 최소 힙(Min Heap)이므로, 선물의 가치에 음수를 붙여 저장함으로써 최대 힙처럼 동작하게 만든다. 값을 꺼낼 때 다시 음수를 붙여 원래 값으로 되돌린다.

## 시간복잡도
- O(N log K): N은 방문 횟수, K는 힙에 있는 선물의 최대 개수이다.
- 힙에 원소를 추가하거나 삭제하는 연산은 O(log K)의 시간이 걸린다. N번의 방문 동안 연산을 수행하므로 총 시간 복잡도는 O(N log K)가 된다.

## 풀이 과정
1. 우선순위 큐로 사용할 리스트 `heap`을 생성한다.
2. N번의 입력을 받으며 반복한다.
3. 입력 `a`가 0인 경우:
   - `heap`이 비어있으면 -1을 출력한다.
   - 비어있지 않으면 `heapq.heappop(heap)`으로 가장 작은 값(원래는 가장 큰 값)을 꺼내고, -1을 곱하여 원래의 가장 큰 선물 가치를 출력한다.
4. 입력 `a`가 0이 아닌 경우:
   - 함께 입력된 `a`개의 선물 가치들을 각각 음수로 바꾸어 `heap`에 `heapq.heappush`로 추가한다.

## 코드 설명
```python
import sys, heapq
input = sys.stdin.readline

n = int(input())
heap = []

for i in range(n) :
    a = list(map(int, input().split()))
    if a == [0] :
        if heap :
            print(-heapq.heappop(heap))
        else :
            print(-1)
    else :
        gift = a[1:]
        for g in gift:
            heapq.heappush(heap, -g)
```
- `heapq` 모듈을 import하여 우선순위 큐를 사용한다.
- `heap` 리스트가 우선순위 큐의 역할을 한다.
- `a == [0]`으로 아이를 만난 경우를 확인한다. `heap`이 비어있는지(`if heap`) 확인 후 선물을 주거나 -1을 출력한다.
- 선물을 충전할 때는(`else`), 입력받은 선물 가치 `g`에 음수를 붙여 `heapq.heappush(heap, -g)`로 최대 힙에 추가한다.
- 선물을 줄 때는 `heapq.heappop(heap)`으로 꺼낸 값에 다시 음수를 붙여 원래의 최댓값으로 만들어 출력한다.
