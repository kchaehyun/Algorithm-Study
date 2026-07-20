# Programmers 49189 - 가장 먼 노드

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/49189)
- 1번부터 `n`번까지 번호가 붙은 노드와 양방향 간선 정보 `edge`가 주어진다.
- 1번 노드에서 가장 멀리 떨어진 노드의 개수를 구한다.
- 가장 멀리 떨어진 노드는 최단 경로로 이동했을 때 거쳐야 하는 간선의 수가 가장 많은 노드다.

## 아이디어
- 모든 간선의 가중치가 같으므로 BFS를 사용해 1번 노드부터 각 노드까지의 최단 거리를 구한다.
- 양방향 간선 정보를 인접 리스트 `graph`에 저장한다.
- 거리 배열 `dist`를 `-1`로 초기화해 방문 여부와 최단 거리를 함께 관리한다.
- BFS에서 처음 방문한 노드의 거리는 `현재 노드의 거리 + 1`이다.
- 탐색이 끝난 뒤 가장 큰 거리와 같은 거리를 가진 노드의 개수를 센다.

## 시간복잡도
- 인접 리스트를 만들고 모든 노드와 간선을 한 번씩 확인하므로 O(N + E)
- `N`은 노드의 개수, `E`는 간선의 개수다.

## 풀이 과정
1. 각 노드의 연결 정보를 저장할 인접 리스트 `graph`를 만든다.
2. `edge`의 각 간선을 양쪽 노드의 인접 리스트에 추가한다.
3. 거리 배열 `dist`를 `-1`로 초기화한다.
4. 1번 노드의 거리를 0으로 설정하고 큐에 넣는다.
5. 큐에서 노드를 하나씩 꺼내 연결된 노드를 확인한다.
6. 아직 방문하지 않은 노드라면 현재 거리보다 1 큰 값을 기록하고 큐에 넣는다.
7. BFS가 끝나면 `dist`를 순회하며 최댓값과 그 개수를 갱신한다.
8. 가장 먼 거리를 가진 노드의 개수 `cnt`를 반환한다.

## 코드 설명
```cpp
int solution(int n, vector<vector<int>> edge) {
    int cnt = 0;
    int maxDist = 0;
    vector<vector<int>> graph(n+1);
    vector<int> dist(n+1, -1);
    queue<int> q;
    for (auto e : edge) {
        int a = e[0];
        int b = e[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    dist[1] = 0;
    q.push(1);
    while(!q.empty()) {
        int num = q.front();
        q.pop();
        for(int connect : graph[num]) {
            if(dist[connect] == -1) {
                q.push(connect);
                dist[connect] = dist[num] + 1;
            }
        }
    }
    
    for(int i = 1 ; i < n+1 ; ++i) {
        if(maxDist < dist[i]) {
            maxDist = dist[i];
            cnt = 1;
        }
        else if(maxDist == dist[i]) ++cnt;
    }
        
    return cnt;
}
```
- `graph[a]`와 `graph[b]`에 서로를 추가해 양방향 그래프를 만든다.
- `dist[i] == -1`이면 `i`번 노드를 아직 방문하지 않았다는 뜻이다.
- `dist[connect] = dist[num] + 1`로 1번 노드부터 연결 노드까지의 최단 거리를 기록한다.
- BFS는 가까운 노드부터 탐색하므로 각 노드를 처음 방문했을 때의 거리가 최단 거리다.
- 더 큰 거리를 발견하면 `maxDist`를 갱신하고 `cnt`를 1로 초기화한다.
- 현재 최댓값과 같은 거리를 발견하면 `cnt`를 1 증가시킨다.
