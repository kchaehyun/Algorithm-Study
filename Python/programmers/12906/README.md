# Programmers 12906 - 같은 숫자는 싫어

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/12906)
- 정수 배열 `arr`에서 연속으로 나타나는 같은 숫자는 하나만 남기고 제거한다.
- 단, 숫자의 순서는 유지해야 한다.

## 아이디어
- 결과 배열의 마지막 값(또는 바로 이전 원소)과 현재 값을 비교한다.
- 현재 값이 이전 값과 다를 때만 결과 배열에 추가하면 된다.

## 시간복잡도
- O(N)

## 풀이 과정
1. 결과 배열 `answer`를 만들고 첫 번째 원소를 먼저 넣는다.
2. 두 번째 원소부터 끝까지 순회한다.
3. 현재 원소가 직전 원소와 다를 때만 `answer`에 추가한다.
4. 최종 `answer`를 반환한다.

## 코드 설명
```python
def solution(arr):
    answer = [arr[0]]
    for i in range(1, len(arr)):
        if arr[i] != arr[i-1] :
            answer.append(arr[i])
    return answer
```
- `answer`에는 연속 중복이 제거된 값만 순서대로 저장된다.
- `arr[i] != arr[i-1]` 조건으로 연속 중복 여부를 판별한다.
