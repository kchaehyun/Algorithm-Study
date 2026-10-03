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