#include <vector>
#include <string>
#include <queue>
#include <iostream>
#include <tuple>
#include <functional>

using namespace std;

const int INF = 1e9;

int getCost(int a, int b) {
    if (a < b) return (b-a)*(b-a);
    else if (a > b) return a-b;
    else return 0;
}

int main() {
    int n;
    int top_i, top_j;
    priority_queue<
        tuple<int,int,int>,
        vector<tuple<int,int,int>>,
        greater<tuple<int,int,int>>
    > pq;
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
    
    cin >> n;
    cin >> top_i >> top_j;

    
    vector<vector<int>> dist(n+2, vector<int>(n+2, INF));
    vector<vector<int>> mount(n+2, vector<int>(n+2));

    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= n ; ++j)
            cin >> mount[i][j];
    }

    dist[0][0] = 0;
    pq.push({0,0,0});
    
    while(!pq.empty()) {
        auto [cost, r, c] = pq.top();
        pq.pop();
        if(cost > dist[r][c]) continue;
        for(int i = 0 ; i < 4 ; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (0 <= nr && nr <= n+1 && 0 <= nc && nc <= n+1) {
                int nextCost = cost + getCost(mount[r][c], mount[nr][nc]);
                if (nextCost < dist[nr][nc]) {
                    dist[nr][nc] = nextCost;
                    pq.push({nextCost,nr,nc});
                }
            }
        }
    }
    
    cout << dist[top_i][top_j] << endl;
    return 0;
}