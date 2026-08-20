# Programmers 132266 - 부대복귀

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/132266)
- `n`개의 지역과 두 지역을 왕복할 수 있는 길 정보 `roads`가 주어진다.
- 각 부대원이 위치한 지역 `sources`에서 목적지 `destination`까지 이동하는 최단 시간을 구한다.
- 모든 길을 이동하는 데 걸리는 시간은 1이며, 목적지에 도달할 수 없는 경우 `-1`을 반환한다.
- `sources`에 주어진 순서대로 각 부대원의 최단 시간을 반환한다.

## 아이디어
- 모든 길의 가중치가 1이므로 BFS를 사용하면 최단 거리를 구할 수 있다.
- 각 출발지에서 목적지까지 BFS를 반복하면 같은 지역을 여러 번 탐색하게 된다.
- 길은 양방향이므로 목적지에서 BFS를 한 번 수행하면 목적지에서 모든 지역까지의 최단 거리를 구할 수 있다.
- 양방향 그래프에서 목적지부터 각 지역까지의 거리는 각 지역에서 목적지까지의 거리와 같다.
- 거리 배열을 `-1`로 초기화하면 방문 여부와 목적지에 도달할 수 없는 경우를 함께 표현할 수 있다.

## 시간 복잡도
- 지역의 수를 `N`, 길의 수를 `E`, 부대원의 수를 `S`라고 할 때 그래프 생성과 BFS는 O(N + E)이다.
- 각 부대원의 거리를 결과에 추가하는 데 O(S)가 필요하므로 전체 시간 복잡도는 O(N + E + S)이다.
- 인접 리스트와 거리 및 방문 배열에 필요한 공간 복잡도는 O(N + E)이다.

## 풀이 과정
1. 각 지역의 연결 정보를 저장할 인접 리스트 `graph`를 만든다.
2. `roads`의 두 지역을 서로의 인접 리스트에 추가하여 양방향 그래프를 구성한다.
3. 거리 배열 `dist`를 `-1`로 초기화한다.
4. 목적지의 거리를 0으로 설정하고 목적지를 큐에 넣는다.
5. 큐에서 지역을 하나씩 꺼내 아직 방문하지 않은 인접 지역을 확인한다.
6. 인접 지역의 거리를 `현재 지역의 거리 + 1`로 설정하고 큐에 넣는다.
7. BFS가 끝나면 `sources`를 순회하며 각 출발지의 거리를 정답에 추가한다.
8. 목적지와 연결되지 않은 지역은 거리가 `-1`로 남아 있으므로 별도 처리 없이 그대로 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    vector<vector<int>> graph(n+1);
    for(auto r : roads) {
        int a = r[0];
        int b = r[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    vector<int> dist(n+1, -1);
    vector<bool> visited(n+1, false);
    queue<int> q;
    q.push(destination);
    visited[destination] = true;
    dist[destination] = 0;
    while(!q.empty()) {
        int road = q.front();
        q.pop();
        for(int connect : graph[road]) {
            if(!visited[connect]) { 
                visited[connect] = true;
                q.push(connect);
                dist[connect] = dist[road] + 1;
            }
        }
    }
    
    for(int s : sources)
        answer.push_back(dist[s]);
    
    return answer;
}
```
- `graph[a]`와 `graph[b]`에 서로를 추가하여 양방향 연결 관계를 저장한다.
- `destination`을 BFS의 시작점으로 사용해 모든 지역에서 목적지까지의 최단 거리를 한 번에 계산한다.
- `dist[connect] = dist[road] + 1`은 현재 지역과 연결된 다음 지역의 최단 거리를 기록한다.
- `visited`는 같은 지역이 큐에 중복으로 들어가는 것을 막는다.
- 목적지에 도달할 수 없는 지역은 `dist`의 초깃값인 `-1`이 유지된다.
- 마지막에는 각 `source`에 대응하는 `dist` 값을 순서대로 `answer`에 추가한다.
