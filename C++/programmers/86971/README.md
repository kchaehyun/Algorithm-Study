# Programmers 86971 - 전력망을 둘로 나누기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/86971)
- `n`개의 송전탑이 `n - 1`개의 전선으로 연결된 트리가 주어진다.
- `wires`의 각 원소 `[v1, v2]`는 두 송전탑을 연결하는 전선을 의미한다.
- 전선 하나를 끊어 전력망을 두 개로 나눌 때, 두 전력망에 속한 송전탑 수의 차이를 최소화해야 한다.
- 가능한 송전탑 수 차이의 최솟값을 반환한다.

## 아이디어
- 트리는 모든 정점이 연결되어 있고 사이클이 없으므로, 간선 하나를 제거하면 정확히 두 개의 연결 요소로 나뉜다.
- 모든 전선을 하나씩 끊어 보며 두 전력망의 크기를 비교한다.
- 인접 리스트에서 전선을 실제로 삭제하는 대신, DFS에서 끊을 전선의 양 끝점 사이로 이동하지 않도록 한다.
- 1번 송전탑에서 DFS를 수행해 방문한 송전탑 수가 `cnt`라면, 다른 전력망의 송전탑 수는 `n - cnt`이다.
- 어느 전선을 끊더라도 1번 송전탑은 두 전력망 중 하나에 속하므로, 시작점을 항상 `1`로 고정해도 된다.
- 각 경우의 차이 `abs(cnt - (n - cnt))`를 구하고 최솟값을 갱신한다.

## 시간복잡도
- 송전탑 수를 `n`이라 하면 전선 수는 `n - 1`개이며, 인접 리스트를 만드는 데 `O(n)`이 필요하다.
- DFS 한 번은 방문 배열을 초기화하고 최대 `n`개의 정점과 `n - 1`개의 간선을 확인하므로 `O(n)`이다.
- 모든 전선에 대해 DFS를 수행하므로 전체 시간복잡도는 `O(n²)`이다.
- 인접 리스트, 방문 배열, 스택에 필요한 공간복잡도는 `O(n)`이다.

## 풀이 과정
1. 최솟값을 저장할 `answer`를 `n`으로 초기화한다.
2. `wires`의 각 전선을 양방향으로 인접 리스트 `graph`에 추가한다.
3. 각 전선의 양 끝점을 `cutA`, `cutB`로 지정하고, 1번 송전탑에서 DFS를 시작한다.
4. 시작 정점을 방문 처리한 뒤 스택에 넣고, 방문한 송전탑 수 `cnt`를 `0`으로 초기화한다.
5. 스택에서 정점을 꺼낼 때마다 `cnt`를 증가시킨다.
6. 인접한 정점 중 끊기로 한 전선을 통해 연결된 정점은 건너뛰고, 아직 방문하지 않은 정점은 방문 처리 후 스택에 넣는다.
7. DFS가 끝나면 `cnt`와 `n - cnt`의 차이로 `answer`를 갱신한다.
8. 모든 전선을 확인한 뒤 `answer`를 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;

int dfs(int start, int cutA, int cutB, vector<vector<int>>& graph) {
    vector<bool> v(graph.size(), false);
    stack<int> s;
    v[start] = true;
    s.push(start);
    int cnt = 0;
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        ++cnt;
        for(int i = 0 ; i < graph[cur].size() ; ++i) {
            if((cur == cutA && graph[cur][i] == cutB) || cur == cutB && graph[cur][i] == cutA) continue;
            if(!v[graph[cur][i]]) {
                v[graph[cur][i]] = true;
                s.push(graph[cur][i]);
            }
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    vector<vector<int>> graph(n+1);
    for(auto w : wires) {
        graph[w[0]].push_back(w[1]);
        graph[w[1]].push_back(w[0]);
    }
    for(auto w : wires) {
        int cnt = dfs(1, w[0], w[1], graph);
        answer = min(answer, abs(cnt - (n-cnt)));
    }
    return answer;
}
```
- `graph`는 송전탑 번호를 인덱스로 사용하는 인접 리스트이며, 번호가 1부터 시작하므로 크기를 `n + 1`로 만든다.
- `dfs`는 지정한 전선을 제외하고 `start`에서 도달할 수 있는 송전탑 수를 반환한다.
- `cutA → cutB`와 `cutB → cutA`를 모두 건너뛰어 양방향 전선이 끊어진 상태를 구현한다.
- `v`는 DFS를 호출할 때마다 새로 생성되므로, 전선을 바꿔 확인할 때 이전 방문 기록이 남지 않는다.
- `stack<int>`를 사용해 재귀 호출 없이 DFS를 수행하며, 스택에 넣을 때 방문 처리하여 같은 정점이 중복으로 들어가는 것을 막는다.
- `abs(cnt - (n-cnt))`는 두 전력망의 송전탑 수 차이이며, `min`으로 모든 경우 중 가장 작은 차이를 남긴다.
