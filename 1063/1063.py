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