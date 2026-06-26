# Programmers 42626 - 더 맵게

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42626)
- 음식의 스코빌 지수 배열 `scoville`과 목표 지수 `K`가 주어진다.
- 가장 맵지 않은 두 음식을 섞어 새 음식을 만들며, 모든 음식의 스코빌 지수를 `K` 이상으로 만들기 위한 최소 횟수를 구한다.
- 새 음식의 스코빌 지수: `a + (b * 2)` (`a`는 최솟값, `b`는 두 번째 최솟값)
- 만들 수 없는 경우 `-1`을 반환한다.

## 아이디어
- 매번 가장 작은 두 값을 빠르게 꺼내야 하므로 최소 힙(min-heap)을 사용한다.
- 힙의 최솟값이 `K` 이상이 될 때까지 섞는 과정을 반복한다.

## 시간복잡도
- 힙 연산 기준으로 O(N log N)

## 풀이 과정
1. `heapq.heapify(scoville)`로 리스트를 최소 힙으로 변환한다.
2. 힙의 최솟값이 `K` 미만인 동안 반복한다.
3. 가장 작은 두 값을 꺼내 새 값을 만들어 다시 힙에 넣는다.
4. 섞은 횟수를 카운트한다.
5. 힙 길이가 1인데도 `K` 미만이면 `-1`을 반환한다.

## 코드 설명
```python
import heapq

def solution(scoville, K):
    answer = 0
    heapq.heapify(scoville)
    while scoville[0] < K :
        a = heapq.heappop(scoville)
        b = heapq.heappop(scoville)
        heapq.heappush(scoville, a+b*2)
        answer += 1
        if len(scoville) == 1 and scoville[0] < K :
            return -1
    return answer
```
- `heapq`로 최솟값 2개를 효율적으로 꺼내고 다시 삽입한다.
- 모든 원소가 `K` 이상이 되는 최소 혼합 횟수를 `answer`로 반환한다.
