# BOJ 18429 - 근손실

## 문제 설명
- [문제 링크](https://www.acmicpc.net/problem/18429)
- N일 동안 N개의 다른 운동 키트를 하루에 하나씩 사용한다.
- 운동 키트마다 중량이 증가하는 양이 다르다. 하루가 지날 때마다 중량은 K만큼 감소한다.
- 운동 기간동안 항상 중량이 500 이상이 되도록 하는 운동 키트 사용 순서의 경우의 수를 구하는 문제이다.

## 아이디어
- **깊이 우선 탐색(DFS)**과 **백트래킹(Backtracking)**을 사용한다.
- N일 동안 운동 키트를 사용하는 모든 순서를 탐색해야 하므로, 순열을 구하는 것과 같다.
- DFS를 이용해 가능한 모든 운동 키트 순서를 탐색한다.
- 재귀 함수는 `(현재 중량, 남은 운동 일수)`를 인자로 받는다.
- 탐색 도중 중량이 500 미만으로 떨어지면, 해당 경로는 더 이상 탐색하지 않고 돌아간다(백트래킹).

## 시간복잡도
- O(N!): N개의 운동 키트를 나열하는 모든 순열의 경우의 수를 탐색해야 하므로 시간 복잡도는 O(N!)이다. N이 최대 8로 작기 때문에 시간 내에 해결 가능하다.

## 풀이 과정
1. `dfs` 함수를 `(현재 중량, 남은 일수)`를 인자로 하여 정의한다.
2. `dfs` 함수 내에서, 남은 일수가 0이 되면 N일 동안 성공적으로 운동을 마친 것이므로, 경우의 수 `ans`를 1 증가시키고 재귀를 종료한다.
3. 0부터 N-1까지의 모든 운동 키트에 대해 반복한다.
4. 아직 사용하지 않은 운동 키트(`visited[i] == False`)이고, 해당 키트를 사용했을 때 중량이 500 이상(`weight - K + A[i] >= 500`)이라면,
   - 해당 키트를 사용 처리(`visited[i] = True`)한다.
   - `dfs(현재 중량 - K + A[i], 남은 일수 - 1)`를 재귀 호출한다.
   - 재귀 호출이 끝나면, 다음 경우의 수를 위해 사용 처리를 해제(`visited[i] = False`)한다.
5. 초기 `dfs` 호출은 `(500, N)`으로 시작한다.

## 코드 설명
```python
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
```
- `dfs(weight, day)`: `day`일이 남았고 현재 중량이 `weight`일 때, 가능한 경우의 수를 탐색하는 함수.
- `ans`: 조건을 만족하는 경우의 수를 저장하는 전역 변수.
- `visited`: 각 운동 키트의 사용 여부를 기록하는 리스트.
- `if day == 0`: N일이 모두 지났으면 성공적인 경우이므로 `ans`를 1 증가시킨다.
- `if not visited[i] and weight - K + A[i] >= 500`: 아직 i번째 키트를 사용하지 않았고, 사용 후에도 중량이 500 이상인지를 확인하는 백트래킹 조건.
- `visited[i] = True`와 `visited[i] = False`: 재귀 호출 전후로 `visited` 상태를 변경하여, 다른 경로에서 해당 키트를 다시 사용할 수 있도록 한다.
