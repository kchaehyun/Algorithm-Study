import sys
input = sys.stdin.readline

def dfs(weight, day):
    global ans
    if day == 0:
        ans += 1
        return
    for i in range(N) : 
        if not visited[i] and weight - K + A[i] >= 500:
            today_weight = weight - K + A[i]
            visited[i] = True
            dfs(today_weight, day-1)
            visited[i] = False
            

N, K = map(int, input().split())
A = list(map(int, input().split()))
visited = [False] * N
ans = 0

dfs(500, N)
print(ans)