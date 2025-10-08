'''
import sys
from itertools import combinations
input = sys.stdin.readline

N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]

players = [i for i in range(N)]
comb = list(combinations(players, N//2))

diff = 100

for start_team in comb :
    # link_team = []
    # for p in players:
    #     if p not in start_team:
    #         link_team.append(p)
    link_team = [p for p in players if p not in start_team]
            
    start_score, link_score = 0, 0
    
    for i in start_team :
        for j in start_team :
            start_score += S[i][j]
    for i in link_team :
        for j in link_team :
            link_score += S[i][j]
    
    diff = min(diff, abs(start_score - link_score))

print(diff)
'''

import sys
input = sys.stdin.readline

def dfs(idx, start_team) :
    global diff
    if len(start_team) == N//2 :
        start_score, link_score = 0, 0
        link_team = [p for p in players if p not in start_team]
        for i in start_team:
            for j in start_team:
                start_score += S[i][j]
        for i in link_team:
            for j in link_team:
                link_score += S[i][j]
        diff = min(diff, abs(start_score-link_score))
        return
        
    if idx >= N :
        return
        
    dfs(idx+1, start_team + [idx]) # idx번째 player를 넣는 경우
    dfs(idx+1, start_team) # idx번째 player를 안 넣는 경우

N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]

players = list(range(N))
diff = 100
dfs(0, [])
print(diff)
