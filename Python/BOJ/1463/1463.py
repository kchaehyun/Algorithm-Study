import sys
input = sys.stdin.readline

N = int(input())
dp = [0] * (N+1)

for i in range(2, N+1):
    dp[i] = 1+dp[i-1]
    if i%2 == 0:
        dp[i] = min(1+dp[i//2], dp[i])
    if i%3 == 0:
        dp[i] = min(1+dp[i//3], dp[i])

print(dp[N])

# 3의 배수 -> 1+dp[n//3]
# 2의 배수 -> 1+dp[n//2]
# 둘 다 아니면 -> 1+dp[n-1]