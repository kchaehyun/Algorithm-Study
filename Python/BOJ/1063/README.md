# BOJ 1063 - 킹

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/1063)
- 8x8 체스판 위에 킹과 돌이 있다.
- 주어진 명령에 따라 킹을 움직이는데, 킹이 돌이 있는 칸으로 이동하면 돌도 같은 방향으로 한 칸 밀려난다.
- 판 범위를 벗어나는 이동은 무시된다.
- 최종적인 킹과 돌의 위치를 출력한다.

## 아이디어
- 체스판의 좌표(`A1` 등)를 행렬의 인덱스(`0~7`)로 변환한다.
- 8가지 방향에 대한 행, 열 변화량을 정의한다.
- 킹의 이동 후 위치가 판 안인지 확인하고, 돌과 겹치면 돌의 이동 후 위치도 확인한다.

## 시간복잡도
- 명령의 개수 `N`만큼 반복문을 수행하므로 `O(N)`이다. `N`은 최대 50이다.

## 풀이 과정
1. 킹의 위치, 돌의 위치, 명령 횟수 `N`을 입력받는다.
2. 열(`A-H`)을 숫자로 변환하기 위한 딕셔너리를 생성한다.
3. 킹과 돌의 초기 위치를 인덱스(`row, col`)로 계산한다. 체스판의 행은 아래에서 위로 `1-8`이므로 `8 - int(pos[1])`로 변환한다.
4. 8방향 이동(`R, L, B, T...`)에 따른 `dr, dc` 배열을 설정한다.
5. 명령을 하나씩 읽으며:
   - 킹의 다음 위치 `king_nr, king_nc`를 계산한다.
   - 킹이 판 밖으로 나가지 않는지 확인한다.
   - 킹이 돌의 위치와 겹치면 돌의 다음 위치 `rock_nr, rock_nc`를 계산한다.
   - 돌도 판 밖으로 나가지 않는지 확인한다.
   - 모든 조건이 만족될 때만 킹(과 돌)의 위치를 갱신한다.
6. 인덱스를 다시 체스판 좌표 형식으로 변환하여 출력한다.

## 코드 설명
```python
import sys
input = sys.stdin.readline

king, rock, N = map(str, input().split())

col_alphabet = ['A','B','C','D','E','F','G','H']
col_dict = {}
for i,k in enumerate(col_alphabet) :
    col_dict[k] = i

king_row = 8 - int(king[1])
king_col = col_dict[king[0]]
rock_row = 8 - int(rock[1])
rock_col = col_dict[rock[0]]

move = ['R','L','B','T','RT','LT','RB','LB']
dr = [0,0,1,-1,-1,-1,1,1]
dc = [1,-1,0,0,1,-1,1,-1]

move_dict = {}
for i,k in enumerate(move) :
    move_dict[k] = i

for i in range(int(N)) :
    m = str(input().strip())

    king_nr = king_row + dr[move_dict[m]]
    king_nc = king_col + dc[move_dict[m]]
    if 0 <= king_nr < 8 and 0 <= king_nc < 8 :
        if king_nr == rock_row and king_nc == rock_col :
            rock_nr = rock_row + dr[move_dict[m]]
            rock_nc = rock_col + dc[move_dict[m]]
            if 0 <= rock_nr < 8 and 0 <= rock_nc < 8 :
                rock_row = rock_nr
                rock_col = rock_nc
            else :
                continue
        king_row = king_nr
        king_col = king_nc
    else :
        continue

for k,v in col_dict.items() :
    if v == king_col :
        king_col = k
    if v == rock_col :
        rock_col = k

king_row = 8 - king_row
rock_row = 8 - rock_row

print("".join([king_col,str(king_row)]))
print("".join([rock_col,str(rock_row)]))
```
- `col_dict`는 열 알파벳을 인덱스로, 다시 인덱스를 알파벳으로 바꿀 때 사용한다.
- 킹이 이동할 칸에 돌이 있다면, 돌의 이동 가능 여부를 먼저 체크하는 로직이 핵심이다.
