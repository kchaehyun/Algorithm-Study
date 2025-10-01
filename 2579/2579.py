import sys
input = sys.stdin.readline

stairs = int(input())
scores = [int(input()) for _ in range(stairs)]
dp = [0] * stairs
if stairs == 1:
    print(scores[0])
elif stairs == 2:
    print(scores[0] + scores[1])
    
else:
    dp[0] = scores[0]
    dp[1] = dp[0] + scores[1]
    dp[2] = max(scores[0], scores[1]) + scores[2]
    for i in range(3, stairs):
        dp[i] = max(dp[i-2]+scores[i], dp[i-3]+scores[i-1]+scores[i])
        
    print(dp[stairs-1])
    

# while i < stairs:
#     if i == stairs-1 :
#         print(score)
#         break
#     next = max(scores[i+1], scores[i+2])
#     if next == scores[i+1]:
#         score += scores[i+1] + scores[i+3]
#         i += 3
#     else:
#         score += scores[i+2]
#         i += 2