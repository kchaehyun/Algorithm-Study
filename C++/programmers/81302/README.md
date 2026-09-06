# Programmers 81302 - 거리두기 확인하기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/81302)
- 5×5 크기의 대기실 5개가 주어지며, `P`는 응시자, `O`는 빈 테이블, `X`는 파티션을 의미한다.
- 두 응시자 사이의 맨해튼 거리가 2 이하라면 거리두기 위반이다. 단, 사이가 파티션으로 막혀 있으면 허용된다.
- 맨해튼 거리는 `|r1 - r2| + |c1 - c2|`로 계산한다.
- 각 대기실이 거리두기를 지키면 `1`, 지키지 않으면 `0`을 순서대로 반환한다.

## 아이디어
- 각 응시자의 위치에서 BFS를 수행하여 파티션을 통과하지 않고 두 칸 이내에 다른 응시자에게 도달할 수 있는지 확인한다.
- 인접한 칸에 응시자가 있거나, 빈 테이블을 한 번 거쳐 다른 응시자를 만나면 거리두기 위반이다.
- 빈 테이블인 `O`만 큐에 추가하므로 파티션인 `X`는 자연스럽게 탐색 경로에서 제외된다.
- 대각선에 있는 두 응시자는 두 개의 최단 경로 중 하나라도 열려 있으면 BFS로 발견된다. 두 경로가 모두 파티션으로 막혀 있으면 허용된다.
- 시작 위치를 방문 처리하여 출발한 응시자를 다른 응시자로 잘못 판단하지 않도록 한다.

## 시간복잡도
- 대기실 개수를 `K`라 하면 각 대기실의 25칸을 순회한다.
- 각 응시자에서 수행하는 BFS는 거리 2까지만 탐색하며, `visited`도 5×5 크기로 고정되어 있으므로 `O(1)`이다.
- 전체 시간복잡도는 `O(K × 25) = O(K)`이다. 문제에서는 대기실 개수도 5로 고정되어 있으므로 `O(1)`로 볼 수 있다.
- 방문 배열과 큐에 필요한 보조 공간은 `O(1)`이다.

## 풀이 과정
1. 각 대기실의 거리두기 준수 여부인 `isValid`를 `true`로 초기화한다.
2. 대기실을 순회하면서 응시자 `P`가 있는 위치마다 `check`를 호출한다.
3. 시작 위치와 거리 `0`을 큐에 넣고 방문 처리한다.
4. 큐에서 위치와 거리를 꺼내고, 거리가 `2`이면 더 이상 주변을 탐색하지 않는다.
5. 상하좌우의 칸 중 범위 안에 있고 방문하지 않은 칸을 확인한다.
6. 해당 칸이 `P`이면 즉시 `false`를 반환하고, `O`이면 거리를 1 증가시켜 큐에 넣는다. `X`는 건너뛴다.
7. 다른 응시자를 만나지 않고 탐색이 끝나면 `true`를 반환한다.
8. 위반이 발견되면 `isValid`를 `false`로 바꾸고, 대기실의 검사 결과를 `answer`에 추가한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool check(int row, int col, vector<string>& graph) {
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
    bool visited[5][5] = {false};
    queue<tuple<int,int,int>> q;
    q.push({row,col,0});
    visited[row][col] = true;
    while(!q.empty()) {
        auto [r, c, dist] = q.front();
        q.pop();
        if(dist == 2) continue;
        for(int i = 0 ; i < 4 ; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(nr >= 0 && nr < 5 && nc >= 0 && nc < 5 && !visited[nr][nc]) {
                if(graph[nr][nc] == 'P') return false;
                else if(graph[nr][nc] == 'O') {
                    q.push({nr,nc,dist+1});
                    visited[nr][nc] = true;
                }
            }
        }
    }
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    for(vector<string>& place : places) {
        bool isValid = true;
        for(int i = 0 ; i < 5 ; ++i) {
            for(int j = 0 ; j < 5 ; ++j) {
                if(place[i][j] == 'P' && !check(i, j, place)) {
                    isValid = false;
                    break;
                }
            }
        }
        answer.push_back(isValid);
    }
    return answer;
}
```
- `check`는 한 응시자 주변에서 거리두기 위반이 발생하는지 검사한다.
- `queue<tuple<int,int,int>>`는 현재 행, 열, 시작점으로부터의 이동 거리를 저장한다.
- `dr`, `dc`는 상하좌우 이동을 나타내며, `visited`는 같은 칸의 중복 방문을 막는다.
- `dist == 2`에서 탐색 확장을 멈추므로 거리 3 이상인 응시자는 검사하지 않는다.
- `graph[nr][nc] == 'P'`이면 거리 1 또는 2에서 다른 응시자를 발견한 것이므로 `false`를 반환한다.
- 위반 시 `break`는 안쪽 열 반복문만 종료한다. 이후 행을 검사하더라도 `isValid`는 `false`로 유지된다.
- `answer.push_back(isValid)`에서 `true`는 `1`, `false`는 `0`으로 변환되어 저장된다.
