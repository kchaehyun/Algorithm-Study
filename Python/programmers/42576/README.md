# Programmers 42576 - 완주하지 못한 선수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42576)
- 마라톤에 참여한 선수 배열 `participant`와 완주한 선수 배열 `completion`이 주어진다.
- 완주하지 못한 선수 1명의 이름을 찾아 반환한다.

## 아이디어
- 두 배열을 정렬하면 같은 이름끼리 같은 인덱스에 오게 된다.
- 처음으로 값이 다른 인덱스의 `participant[i]`가 완주하지 못한 선수이다.
- 끝까지 모두 같다면 마지막 참가자가 미완주자이다.

## 시간복잡도
- 정렬이 지배적이므로 O(N log N)

## 풀이 과정
1. `participant`, `completion`을 각각 정렬한다.
2. `completion` 길이만큼 순회하며 같은 인덱스 값을 비교한다.
3. 값이 다르면 해당 `participant[i]`를 즉시 반환한다.
4. 반복문에서 반환되지 않았다면 `participant[-1]`을 반환한다.

## 코드 설명
```python
def solution(participant, completion):
    participant.sort()
    completion.sort()
    for i in range(len(completion)) :
        if participant[i] != completion[i] :
            return participant[i]
            
    return participant[-1]
```
- 정렬 후 인덱스 비교만으로 미완주자를 찾는다.
- 동명이인이 있어도 정렬 후 순차 비교로 정확히 처리할 수 있다.
