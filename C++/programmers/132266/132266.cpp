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