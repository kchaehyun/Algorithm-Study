#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

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