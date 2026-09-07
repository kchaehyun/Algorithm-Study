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