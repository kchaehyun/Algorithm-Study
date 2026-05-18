# Programmers 154540 - 무인도 여행

## 문제 설명
[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/154540)

지도의 각 칸에는 'X' 또는 숫자가 적혀 있습니다. 숫자는 해당 칸에 있는 식량의 양을 나타내며, 상하좌우로 연결된 숫자 칸들은 하나의 무인도를 이룹니다. 각 무인도에서 머물 수 있는 최대 일수(식량의 총합)를 구해 오름차순으로 정렬하여 반환하는 문제입니다. 무인도가 없다면 -1을 반환합니다.

## 아이디어
- 지도를 순회하며 숫자가 있고 아직 방문하지 않은 칸을 발견하면, 해당 칸을 시작점으로 **DFS** 또는 **BFS**를 수행하여 연결된 모든 숫자 칸을 찾습니다.
- 탐색 과정에서 방문한 칸의 숫자를 모두 더해 해당 무인도의 총 식량(머물 수 있는 일수)을 계산합니다.

## 시간복잡도
- 지도의 행 크기를 $R$, 열 크기를 $C$라고 할 때, 전체 칸의 개수는 $N = R \times C$입니다.
- 각 칸은 최대 한 번씩 방문하므로 시간복잡도는 $O(R \times C)$입니다.
- $R, C \le 100$이므로 최대 10,000번의 연산으로 매우 빠르게 해결 가능합니다.

## 풀이 과정
1. 방문 여부를 체크할 `visited` 배열을 초기화합니다.
2. 지도의 모든 칸을 순회하며 다음을 확인합니다:
    - 해당 칸이 'X'가 아니고, 아직 방문하지 않았다면 새로운 무인도 탐색을 시작합니다.
3. 스택을 이용한 DFS로 연결된 모든 땅을 방문합니다:
    - 상하좌우 네 방향을 확인하여 범위 내에 있고, 'X'가 아니며, 방문하지 않은 칸을 스택에 넣고 방문 처리합니다.
    - 방문하는 각 칸의 숫자를 `day` 변수에 누적합니다.
4. 탐색이 종료되면 `day`를 결과 리스트에 추가합니다.
5. 모든 칸의 순회가 끝나면 결과 리스트를 오름차순으로 정렬합니다. 리스트가 비어있다면 `[-1]`을 반환합니다.

## 코드 설명
```python
def solution(maps):
    answer = []
    row = len(maps)
    col = len(maps[0])
    visited = [[False]*col for _ in range(row)]
    
    for r in range(row) :
        for c in range(col) :
            # 바다가 아니고 방문하지 않은 땅 발견
            if maps[r][c] != 'X' and not visited[r][c] :
                s = [(r, c)]
                visited[r][c] = True
                day = int(maps[r][c])
                # DFS 탐색 시작
                while s :
                    now_r, now_c = s.pop()
                    for dr, dc in [(0, 1), (1, 0), (-1, 0), (0, -1)] :
                        nr = now_r + dr
                        nc = now_c + dc
                        if 0 <= nr < row and 0 <= nc < col :
                            if maps[nr][nc] != 'X' and not visited[nr][nc] :
                                s.append((nr, nc))
                                visited[nr][nc] = True
                                day += int(maps[nr][nc])
                answer.append(day)
    
    if not answer :
        return [-1]
                                
    return sorted(answer)
```
