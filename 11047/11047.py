import sys
input = sys.stdin.readline

N, K = map(int, input().split())
coins = []
ans = 0

for i in range(N) : 
    coins.append(int(input()))
coins.sort(reverse=True)

for coin in coins:
    ans += K // coin
    K %= coin
        
print(ans)