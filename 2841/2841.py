import sys
input = sys.stdin.readline

N, P = map(int, input().split())
stacks = [[] for _ in range(7)]
ans = 0
for i in range(N) :
    line, fret = map(int, input().split())
    while stacks[line] :
        if stacks[line][-1] <= fret :
            break
        stacks[line].pop()
        ans += 1
    if stacks[line] and fret == stacks[line][-1] :
        continue
    stacks[line].append(fret)
    ans += 1

print(ans)
