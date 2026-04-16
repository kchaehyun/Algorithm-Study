# Programmers 43163 - 단어 변환

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43163)
- 시작 단어 `begin`에서 목표 단어 `target`으로 변환하려고 한다.
- 한 번에 한 글자만 바꿀 수 있고, 바꾼 단어는 `words` 안에 있어야 한다.
- 최소 몇 단계의 변환이 필요한지 구하는 문제이다.

## 아이디어
- 한 글자만 다른 단어끼리는 한 번의 변환으로 이동할 수 있다.
- 단어를 정점으로 보고, 한 글자만 다른 경우 간선이 있다고 생각할 수 있다.
- 최소 변환 횟수를 구해야 하므로 BFS를 사용한다.
- `target`에 도달할 수 없다면 0을 반환한다.

## 풀이 과정
1. 두 단어가 몇 글자 다른지 세는 `diff_cnt` 함수를 만든다.
2. BFS 큐에 시작 단어 `begin`과 현재 단계 0을 넣는다.
3. 큐에서 단어와 변환 횟수를 꺼낸다.
4. 현재 단어가 `target`이면 변환 횟수를 반환한다.
5. `words`를 순회하면서 현재 단어와 한 글자만 다른 단어를 찾는다.
6. 아직 방문하지 않은 단어라면 방문 처리 후 큐에 넣는다.
7. 큐가 빌 때까지 `target`에 도달하지 못하면 0을 반환한다.

## 코드 설명
```python
from collections import deque

def diff_cnt(a,b) :
    cnt = 0
    for i in range(len(a)) :
        if a[i] != b[i] :
            cnt += 1
    return cnt

def transform(begin,target,words):
    visited = [False]*len(words)
    queue = deque([(begin,0)])
    while queue :
        tmp, step = queue.popleft()
        if tmp == target :
            return step
        for i in range(len(words)) :
            if diff_cnt(tmp,words[i]) == 1 :
                if not visited[i] :
                    visited[i] = True
                    queue.append((words[i],step+1))
    return 0
                

def solution(begin, target, words):
    return transform(begin,target,words)
```
- `diff_cnt` 함수는 두 단어의 서로 다른 글자 수를 반환한다.
- 서로 다른 글자 수가 1이면 한 번의 변환으로 이동할 수 있다.
- `visited` 배열은 같은 단어를 반복해서 탐색하지 않기 위해 사용한다.
- BFS 특성상 `target`을 처음 만났을 때의 `step`이 최소 변환 횟수이다.

