import sys
input = sys.stdin.readline

N = int(input())

start, end, sum = 1, 1, 1
ans = 0
while start <= N:
    if sum < N :
        end += 1
        sum += end
    elif sum > N :
        sum -= start
        start += 1
    elif sum == N :
        ans += 1
        end += 1
        sum += end
        
print(ans)