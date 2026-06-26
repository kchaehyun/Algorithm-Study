# Programmers 250136 - [PCCP 기출문제] 2번 / 석유 시추

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/250136)
- 직사각형 격자 형태의 땅에서 석유가 묻힌 구역을 찾아, 시추관을 하나 설치했을 때 얻을 수 있는 최대 석유량을 구한다.
- 시추관은 특정 열(column)을 따라 수직으로 깊게 뚫으며, 해당 열이 지나는 모든 석유 덩어리의 크기를 합산한다.

## 아이디어
- BFS 또는 DFS를 사용하여 석유 덩어리를 찾는다.
- 각 덩어리의 크기를 계산하면서, 해당 덩어리가 포함된 모든 **열(column)**의 인덱스를 저장한다.
- 각 열마다 얻을 수 있는 석유량의 합을 저장할 배열(`col_size`)을 만들고, 덩어리를 찾을 때마다 해당 덩어리가 걸쳐 있는 열들에 덩어리 크기를 더해준다.

## 시간복잡도
- O(N * M), 여기서 N은 행의 수, M은 열의 수이다. 모든 칸을 한 번씩 방문한다.

## 풀이 과정
1. `col_size` 배열을 0으로 초기화한다 (크기는 열의 개수).
2. 땅을 순회하면서 아직 방문하지 않은 석유(1)를 발견하면 BFS를 시작한다.
3. BFS 진행 중:
    - 덩어리의 크기(`now_size`)를 카운트한다.
    - 덩어리가 속한 열의 번호를 `set`에 저장하여 중복을 방지한다.
    - 방문한 칸은 0으로 바꿔 다시 방문하지 않게 한다.
4. BFS가 끝나면 `set`에 저장된 모든 열 인덱스에 대해 `col_size[C] += now_size`를 수행한다.
5. `col_size` 배열의 최댓값을 반환한다.

## 코드 설명
```python
from collections import deque
  
def solution(land):
    answer = 0
    row = len(land)
    col = len(land[0])
    col_size = [0] * col
    
    for r in range(row) :
        for c in range(col) :
            if land[r][c] == 1:
                cols = set([c])
                now_size = 1
                q = deque([(r,c)])            
                land[r][c] = 0
                while q :
                    now_r, now_c = q.popleft()
                    for dr,dc in [(1,0),(0,1),(-1,0),(0,-1)] :
                        nr = now_r + dr
                        nc = now_c + dc
                        if 0 <= nr < row and 0 <= nc < col :
                            if land[nr][nc] == 1 :
                                cols.add(nc)
                                land[nr][nc] = 0
                                now_size += 1
                                q.append((nr,nc))
                for C in cols :
                    col_size[C] += now_size                                
                
    return max(col_size)
```
- BFS를 통해 덩어리를 식별하고, 해당 덩어리가 영향을 주는 열들을 효율적으로 업데이트한다.
- `set`을 사용하여 하나의 덩어리가 같은 열에 여러 번 걸쳐 있어도 한 번만 더해지도록 처리한다.
