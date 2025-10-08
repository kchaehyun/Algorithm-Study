# BOJ 14889 - 스타트와 링크

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/14889)
- N명의 사람을 N/2명씩 두 팀(스타트 팀, 링크 팀)으로 나누려고 한다.
- 각 사람의 능력치 Sij가 주어졌을 때, 두 팀의 능력치 차이를 최소로 만드는 문제이다.

## 아이디어
- N명의 사람 중 N/2명을 뽑아 스타트 팀을 구성하는 모든 조합을 찾는다.
- N의 범위가 20으로 작기 때문에, **깊이 우선 탐색(DFS)**을 이용한 백트래킹이나 `itertools.combinations`를 사용한 완전 탐색으로 해결할 수 있다.
- 한 팀이 정해지면 나머지 팀은 자동으로 정해진다.

## 시간복잡도
- O(C(N, N/2)): N명 중 N/2명을 뽑는 조합의 수에 비례한다. N=20일 때, C(20, 10)은 약 18만으로, 시간 내에 충분히 계산 가능하다.

## 풀이 과정
### 1. DFS를 이용한 풀이
1. `dfs` 함수를 `(현재 인덱스, 현재까지 팀에 포함된 멤버 리스트)`를 인자로 하여 정의한다.
2. 팀 멤버 수가 N/2가 되면, 스타트 팀 구성이 완료된 것이다.
3. 스타트 팀에 포함되지 않은 나머지 멤버들로 링크 팀을 구성한다.
4. 각 팀의 능력치를 계산한다. 팀 능력치는 팀에 속한 모든 쌍 (i, j)에 대해 S[i][j]의 합이다. (문제에서는 S[i][j]와 S[j][i]를 모두 더하라고 명시되어 있지 않지만, 일반적으로 S[i][j] + S[j][i]를 더하는 방식으로 구현한다. 코드에서는 S[i][j]만 더하고 있으나, S[i][j]와 S[j][i]가 대칭이 아닐 수 있으므로 문제의 정의를 정확히 따라야 한다. 주어진 코드는 S[i][j]만 더하고 있다.)
5. 두 팀의 능력치 차이의 절댓값을 구해 최솟값을 갱신한다.
6. 재귀 호출은 현재 인덱스의 사람을 팀에 포함하는 경우와 포함하지 않는 경우로 나누어 진행한다.

### 2. `itertools.combinations`를 이용한 풀이
1. `itertools.combinations`를 사용하여 전체 N명 중 N/2명을 뽑는 모든 조합(스타트 팀)을 구한다.
2. 각 조합에 대해, 해당 조합에 포함되지 않은 나머지 멤버들로 링크 팀을 구성한다.
3. 위와 동일하게 각 팀의 능력치를 계산하고, 능력치 차이의 최솟값을 갱신한다.

## 코드 설명
### 1. DFS 코드
```python
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
```
- `dfs(idx, start_team)`: `idx`번째 선수를 `start_team`에 포함시킬지 여부를 결정하며 모든 팀 조합을 탐색한다.
- `len(start_team) == N//2`: 팀 구성이 완료되면 능력치를 계산하고 최솟값 `diff`를 갱신한다.
- `dfs(idx+1, start_team + [idx])`: `idx` 선수를 팀에 포함.
- `dfs(idx+1, start_team)`: `idx` 선수를 팀에 미포함.

### 2. `itertools.combinations` 코드
```python
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
```
- `combinations(players, N//2)`를 통해 N/2명의 스타트 팀으로 가능한 모든 조합을 생성한다.
- 각 조합에 대해 반복문을 돌며 능력치 차이를 계산하고 최솟값을 찾는다.
