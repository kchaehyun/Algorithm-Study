import sys
input = sys.stdin.readline

N = int(input())
answer = 0
for _ in range(N) : 
    arr = input().strip()
    stack = []
    for a in arr :
        if stack and a == stack[-1] :
            stack.pop()
        else:
            stack.append(a)
    if not stack:
        answer += 1

print(answer)
