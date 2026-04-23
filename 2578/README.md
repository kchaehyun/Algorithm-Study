# BOJ 2578 - 빙고

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/2578)
- 5x5 크기의 빙고판에 1부터 25까지 숫자가 적혀 있다.
- 사회자가 숫자를 하나씩 부를 때마다 해당 숫자를 지워 나간다.
- 가로, 세로, 혹은 대각선으로 5개의 숫자가 모두 지워진 선이 3개 이상이 되는 순간 "빙고"를 외친다.
- 사회자가 몇 번째 숫자를 불렀을 때 빙고가 되는지 구하는 문제이다.

## 아이디어
- 5x5 배열에 빙고판 정보를 저장한다.
- 숫자가 불릴 때마다 해당 칸을 `0`으로 표시한다.
- 매번 혹은 숫자가 5개 이상 불린 시점부터 가로, 세로, 대각선을 검사하여 완성된 선의 개수를 센다.
- 선의 개수가 3개 이상이면 종료하고 현재까지 불린 숫자의 개수를 출력한다.

## 시간복잡도
- 빙고판의 크기가 5x5로 고정되어 있다.
- 숫자를 지우는 연산은 25번 이내이며, 매번 빙고 여부를 체크하더라도 상수 시간 내에 처리 가능하다.
- 전체 시간복잡도는 사실상 `O(1)`이다.

## 풀이 과정
1. 5x5 빙고판과 사회자가 부르는 숫자들을 입력받는다.
2. 빙고판 각 숫자의 위치(좌표)를 미리 딕셔너리(`pos`)에 저장해두면 숫자를 지울 때 빠르게 접근할 수 있다.
3. 사회자가 부르는 숫자를 하나씩 순회하며:
   - 빙고판에서 해당 숫자의 위치를 찾아 `0`으로 바꾼다.
   - 불린 숫자의 개수를 카운트한다.
   - 숫자가 5개 이상 불렸을 때부터 `check_bingo` 함수를 호출해 완성된 선의 개수를 확인한다.
   - 완성된 선이 3개 이상이면 현재 카운트를 출력하고 종료한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

def check_bingo(graph) :
    cnt = 0
    # 가로 검사
    for i in range(5) :
        if all(graph[i][j] == 0 for j in range(5)):
            cnt += 1
    # 세로 검사
    for j in range(5) :
        if all(graph[i][j] == 0 for i in range(5)):
            cnt += 1
    # 대각선 1 (\)
    if all(graph[i][i] == 0 for i in range(5)):
        cnt += 1
    # 대각선 2 (/)
    if all(graph[i][4-i] == 0 for i in range(5)):
        cnt += 1
    return cnt

bingo = [list(map(int,input().split())) for _ in range(5)]
numbers = [list(map(int,input().split())) for _ in range(5)]

# 숫자의 위치를 미리 저장
pos = {}
for i in range(5) :
    for j in range(5) :
        pos[bingo[i][j]] = (i,j)

now_num = 0
is_three = False
for r in range(5) :
    for c in range(5) :
        bingo_r, bingo_c = pos[numbers[r][c]]
        bingo[bingo_r][bingo_c] = 0 # 숫자 지우기
        now_num += 1
        if now_num >= 5: # 최소 5개는 불러야 1줄 가능
            if check_bingo(bingo) >= 3 :
                is_three = True
                break
    if is_three :
        print(now_num)
        break
```
- `check_bingo` 함수에서 가로, 세로, 대각선을 각각 순회하며 `0`으로만 채워진 줄의 개수를 반환한다.
- `pos` 딕셔너리를 사용하여 빙고판에서 특정 숫자를 찾는 시간을 단축했다.
