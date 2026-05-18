# Programmers 388353 - [PCCP 기출문제] 2번 / 지게차와 크레인

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/388353)
- 창고의 격자에 컨테이너가 쌓여 있다. 지게차나 크레인으로 컨테이너를 꺼낸다.
- 지게차 요청 (문자 1개): 외부와 연결된(가장자리에 있거나 외부 통로와 연결된) 해당 종류의 모든 컨테이너를 제거한다.
- 크레인 요청 (문자 2개): 외부 연결 여부와 상관없이 해당 종류의 모든 컨테이너를 제거한다.
- 모든 요청 수행 후 남은 컨테이너의 개수를 구한다.

## 아이디어
- 창고 바깥쪽에 한 칸씩 여유(빈 공간 '0')를 두어 "외부"를 정의한다.
- 지게차 요청 시, BFS를 통해 (0, 0)에서 접근 가능한 칸들을 찾는다.
- 접근 가능한 칸에 인접한 타겟 컨테이너들만 제거한다.
- 크레인 요청 시, 모든 격자를 순회하며 타겟 컨테이너를 제거한다.

## 시간복잡도
- O(Q * R * C), 여기서 Q는 요청 횟수, R/C는 행/열 수이다.

## 풀이 과정
1. 창고 배열을 상하좌우 한 칸씩 늘려 '0'으로 채운다. (외부 공간 확보)
2. 각 요청에 대해:
    - **크레인(길이 2):** 전체 격자를 돌며 해당 알파벳을 '0'으로 바꾼다.
    - **지게차(길이 1):**
        1. BFS를 통해 '0'인 칸들을 방문하며 `access_list`를 만든다. (외부 접근 가능 여부 판별)
        2. 격자를 돌며 해당 알파벳이 있는 칸 중, 인접한 네 칸 중 하나라도 `access_list`에 포함된 경우 제거 리스트에 담는다.
        3. 제거 리스트의 컨테이너들을 '0'으로 바꾼다.
3. 남은 컨테이너 개수를 계산한다.

## 코드 설명
```python
from collections import deque

def access(board) :
    R = len(board)
    C = len(board[0])
    dr = [1,0,-1,0]
    dc = [0,1,0,-1]
    visited = [[False]*C for _ in range(R)]
    visited[0][0] = True
    q = deque([(0,0)])
    while q :
        row, col = q.popleft()
        for i in range(4) :
            n_r = row + dr[i]
            n_c = col + dc[i]
            if 0 <= n_r < R and 0 <= n_c < C :
                if board[n_r][n_c] == '0' and not visited[n_r][n_c] :
                    visited[n_r][n_c] = True
                    q.append((n_r,n_c))
    return visited

def solution(storage, requests):
    r = len(storage)
    c = len(storage[0])
    answer = r*c
    # 외부 패딩 추가
    containers = [list('0'*(c+2))]
    for i in range(r) :
        containers.append(list('0' + storage[i] + '0'))
    containers.append(list('0'*(c+2)))
    
    for req in requests :
        if len(req) == 1 : # 지게차
            access_list = access(containers)
            remove = []
            for i in range(1,r+1) :
                for j in range(1,c+1) :
                    if containers[i][j] == req :
                        for d_r,d_c in [(0,1),(1,0),(0,-1),(-1,0)] :
                            if access_list[i+d_r][j+d_c] :
                                remove.append((i,j))
                                break
            for i,j in remove :
                containers[i][j] = '0'
                answer -= 1
        else : # 크레인
            alphabet = req[0]
            for i in range(r+2) :
                for j in range(c+2) :
                    if containers[i][j] == alphabet :
                        containers[i][j] = '0'
                        answer -= 1
    return answer
```
- `access` 함수(BFS)를 통해 매 지게차 요청마다 실시간으로 외부 접근 가능성을 판단한다.
- 격자 외부에 빈 공간을 두어 가장자리 처리 로직을 단순화한다.
