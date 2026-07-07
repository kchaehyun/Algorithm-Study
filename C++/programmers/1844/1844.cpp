#include <vector>
#include <queue>


using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int R = maps.size();
    int C = maps[0].size();
    int dr[4] = {1, 0, -1, 0};
    int dc[4] = {0, 1, 0, -1};
    queue<pair<int,int>> q;
    q.push({0,0});
    // maps[0][0] = 1;
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        int r = cur.first;
        int c = cur.second;
        if(r == R-1 && c == C-1) return maps[r][c];
        for(int i = 0 ; i < 4 ; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if(0 <= nr && nr < R && 0 <= nc && nc < C && maps[nr][nc] == 1) {
                maps[nr][nc] = maps[r][c] + 1;
                q.push({nr,nc});
            }
        }
    }
    return -1;
}