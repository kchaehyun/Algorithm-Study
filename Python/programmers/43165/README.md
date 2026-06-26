# Programmers 43165 - 타겟 넘버

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43165)
- 숫자 배열 `numbers`의 각 원소 앞에 `+` 또는 `-`를 붙여 목표값 `target`을 만들 수 있는 경우의 수를 구한다.

## 아이디어
- 각 숫자마다 `+` 또는 `-` 두 선택지가 있으므로 완전탐색(DFS)이 가능하다.
- 인덱스를 하나씩 진행하며 현재 합을 누적한다.
- 끝까지 갔을 때 합이 `target`이면 경우의 수를 증가시킨다.

## 시간복잡도
- O(2^N)

## 풀이 과정
1. DFS 함수에 `(현재 합, 현재 인덱스)`를 전달한다.
2. 인덱스가 끝에 도달하면 현재 합이 `target`인지 확인한다.
3. 아니라면 다음 숫자에 대해 `-`, `+` 두 방향으로 재귀 호출한다.
4. 누적된 경우의 수를 반환한다.

## 코드 설명
```python
def solution(numbers, target):
    answer = 0
    def dfs(start,idx) :
        nonlocal answer
        if idx == len(numbers) :
            if start == target :
                answer += 1
            return
        dfs(start-numbers[idx],idx+1)
        dfs(start+numbers[idx],idx+1) 
    dfs(0,0)
    return answer
```
- 각 단계에서 두 갈래 재귀를 타며 가능한 모든 부호 조합을 탐색한다.
- `nonlocal answer`로 유효한 경우의 수를 누적한다.
