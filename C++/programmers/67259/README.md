# Programmers 67259 - 경주로 건설

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/67259)
- 빈칸은 `0`, 벽은 `1`로 표시된 정사각형 격자 `board`가 주어진다.
- 왼쪽 위 `(0, 0)`에서 오른쪽 아래 `(N - 1, N - 1)`까지 벽을 피해 경주로를 건설한다.
- 상하좌우로 인접한 두 빈칸을 연결하는 직선 도로의 비용은 100원이며, 직각으로 방향을 바꾸면 코너 비용 500원이 추가된다.
- 출발점부터 도착점까지 경주로를 건설하는 데 필요한 최소 비용을 반환한다.

## 아이디어
- 이동 방향이 유지되면 100원, 방향이 바뀌면 600원이 필요하므로 비용이 작은 상태부터 탐색하는 다익스트라 알고리즘을 사용한다.
- 같은 칸에 도착하더라도 진입 방향에 따라 다음 이동에서 코너 비용이 발생하는지가 달라진다.
- 따라서 위치만으로 방문 여부를 관리하지 않고, `minCost[r][c][dir]`에 해당 칸에 특정 방향으로 도착한 최소 비용을 저장한다.
- 우선순위 큐에는 `(누적 비용, 행, 열, 이동 방향)`을 저장하고, 누적 비용이 가장 작은 상태를 먼저 꺼낸다.
- 출발점의 방향은 `-1`로 설정하여 첫 이동에는 코너 비용 없이 100원만 더한다.
- 모든 이동 비용이 양수이므로 도착점이 큐에서 처음 꺼내졌을 때의 비용이 정답이다.

## 시간 복잡도
- 격자의 한 변 길이를 `N`이라고 하면 위치와 방향을 합친 상태 수는 최대 `4N²`개이고, 각 상태에서 확인하는 다음 방향은 4개이다.
- 우선순위 큐를 사용하는 다익스트라 탐색의 시간 복잡도는 O(N² log N)이다.
- 방향별 최소 비용 배열과 우선순위 큐에 필요한 공간 복잡도는 O(N²)이다.

## 풀이 과정
1. 네 방향 이동을 위한 `dr`, `dc`와 최소 비용을 저장할 3차원 배열 `minCost`를 준비한다.
2. `minCost`를 충분히 큰 값으로 초기화하고, 출발 상태 `(0, 0, 0, -1)`을 우선순위 큐에 넣는다.
3. 큐에서 누적 비용이 가장 작은 상태를 꺼낸다.
4. 현재 위치가 도착점이면 누적 비용을 즉시 반환한다.
5. 네 방향의 다음 칸을 확인하고, 격자를 벗어나거나 벽인 칸은 건너뛴다.
6. 첫 이동이거나 이전 이동 방향과 같으면 100원, 방향이 달라지면 600원을 더한다.
7. 계산한 비용이 다음 칸의 해당 방향 최소 비용보다 작으면 값을 갱신하고 큐에 넣는다.
8. 탐색을 마칠 때까지 도착점에 도달하지 못하면 `-1`을 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> board) {
    priority_queue<
        tuple<int,int,int,int>,
        vector<tuple<int,int,int,int>>,
        greater<tuple<int,int,int,int>>
    > pq;
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    int R = board.size();
    int C = board[0].size();
    vector<vector<vector<int>>> minCost(
        R,
        vector<vector<int>>(C, vector<int>(4, 1e9))
    );

    pq.push({0,0,0,-1});
    while(!pq.empty()) {
        auto [cost,r,c,dir] = pq.top();
        pq.pop();
        if(r == R-1 && c == C-1) return cost;
        for(int nextDir = 0 ; nextDir < 4 ; ++nextDir) {
            int nr = r + dr[nextDir];
            int nc = c + dc[nextDir];
            if(nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if(board[nr][nc] == 1) continue;
            int nextCost;
            if(dir == -1 || dir == nextDir) nextCost = cost + 100;
            else nextCost = cost + 600;
            if(minCost[nr][nc][nextDir] > nextCost) {
                minCost[nr][nc][nextDir] = nextCost;
                pq.push({nextCost,nr,nc,nextDir});
            }
        }
    }

    return -1;
}
```
- `greater<tuple<int,int,int,int>>`는 튜플의 첫 번째 값인 비용이 작은 상태부터 꺼내도록 한다.
- `dr`, `dc`의 인덱스 `0`, `1`, `2`, `3`은 각각 오른쪽, 아래쪽, 왼쪽, 위쪽 이동을 나타낸다.
- `minCost[r][c][dir]`는 `(r, c)`에 `dir` 방향으로 이동해 도착한 최소 비용이다.
- `dir == -1`은 출발 상태를 의미하며, 첫 도로를 놓을 때 코너 비용이 추가되는 것을 막는다.
- `nextCost`는 직선 도로 비용 100원에 방향 변경 시 추가 비용 500원을 반영한다.
- `minCost[nr][nc][nextDir] > nextCost`일 때만 갱신하여 같은 위치와 방향에 더 비싼 비용으로 도착하는 경로를 추가하지 않는다.
- 도착 여부는 큐에 넣을 때가 아니라 최소 비용 상태를 꺼낼 때 검사하여 최솟값을 반환한다.
