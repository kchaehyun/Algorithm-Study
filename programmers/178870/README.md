# Programmers 178870 - 연속된 부분 수열의 합

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/178870)
- 수열 `sequence`에서 합이 `k`인 연속 부분 수열을 찾는다.
- 길이가 가장 짧은 구간의 시작/끝 인덱스를 반환한다.

## 아이디어
- 원소가 양수이므로 투 포인터(슬라이딩 윈도우)로 합을 관리할 수 있다.
- 오른쪽 포인터를 확장하며 합이 `k`를 넘으면 왼쪽 포인터를 이동해 줄인다.
- 합이 `k`일 때 길이가 더 짧은 구간을 정답으로 갱신한다.

## 시간복잡도
- O(N)

## 풀이 과정
1. `left`, `current_sum`을 0으로 두고 `right`를 증가시키며 순회한다.
2. `current_sum > k`면 `left`를 이동해 합을 줄인다.
3. `current_sum == k`면 최소 길이인지 확인 후 정답을 갱신한다.
4. 순회가 끝나면 저장된 인덱스 구간을 반환한다.

## 코드 설명
```python
def solution(sequence, k):
    answer = []
    left = 0
    min_len = float('inf')
    current_sum = 0
    for right in range(len(sequence)) :
        current_sum += sequence[right]
        while current_sum > k :
            current_sum -= sequence[left]
            left += 1
        if current_sum == k and right-left < min_len:
            answer = [left, right]
            min_len = right-left  
            
    return answer
```
- `right-left`를 길이 비교 기준으로 사용해 가장 짧은 구간을 유지한다.
- 합 관리를 통해 모든 구간을 직접 계산하지 않고 선형 시간에 해결한다.
