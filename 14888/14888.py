import sys
input = sys.stdin.readline

def dfs(idx, add, sub, mul, div, res) :
    global max_val, min_val
    if idx == N:
        if max_val is None and min_val is None :
            max_val = res
            min_val = res
        max_val = max(max_val, res)
        min_val = min(min_val, res)
        return
    if add:
        dfs(idx+1, add-1, sub, mul, div, res + A_N[idx])
    if sub :
        dfs(idx+1, add, sub-1, mul, div, res - A_N[idx])
    if mul :
        dfs(idx+1, add, sub, mul-1, div, res * A_N[idx])
    if div :
        if res >= 0:
            dfs(idx+1, add, sub, mul, div-1, res // A_N[idx])
        else :
            dfs(idx+1, add, sub, mul, div-1, -(-res // A_N[idx]))
                

N = int(input())
A_N = list(map(int, input().split()))
oper = list(map(int, input().split()))
max_val, min_val = None, None

dfs(1, oper[0], oper[1], oper[2], oper[3], A_N[0])

print(max_val)
print(min_val)