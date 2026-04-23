import sys
input = sys.stdin.readline

def check_bingo(graph) :
    cnt = 0
    for i in range(5) : # 가로
        is_bingo = True
        for j in range(5) :
            if graph[i][j] != 0 :
                is_bingo = False
                break
        if is_bingo :
            cnt += 1

    for j in range(5) : # 세로
        is_bingo = True
        for i in range(5) :
            if graph[i][j] != 0 :
                is_bingo = False
                break
        if is_bingo :
            cnt += 1
    
    # 대각선
    is_bingo = True
    for i in range(5) :
        if graph[i][i] != 0 :
            is_bingo = False
            break
    if is_bingo :
        cnt += 1
    
    is_bingo = True
    for i in range(5) :
        if graph[i][4-i] != 0 :
            is_bingo = False
            break
    if is_bingo :
        cnt += 1
    
    return cnt

            
bingo = [list(map(int,input().split())) for _ in range(5)]
numbers = [list(map(int,input().split())) for _ in range(5)]

pos = {}
for i in range(5) :
    for j in range(5) :
        pos[bingo[i][j]] = (i,j)

now_num = 0
is_three = False
for r in range(5) :
    for c in range(5) :
        bingo_r, bingo_c = pos[numbers[r][c]]
        bingo[bingo_r][bingo_c] = 0
        now_num += 1
        if now_num >= 5:
            if check_bingo(bingo) >= 3 :
                is_three = True
                break
    if is_three :
        print(now_num)
        break