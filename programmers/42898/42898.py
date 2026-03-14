def solution(m, n, puddles):
    answer = 0
    dp = [[0]*m for _ in range(n)]
    dp[0][0] = 1
    p = {(x-1,y-1) for x,y in puddles}
    
    for y in range(n) :
        for x in range(m) :
            if (x,y) in p:
                continue
            if y > 0 :
                dp[y][x] += dp[y-1][x]
            if x > 0 :
                dp[y][x] += dp[y][x-1]
                
    answer = dp[n-1][m-1] % 1000000007
    return answer