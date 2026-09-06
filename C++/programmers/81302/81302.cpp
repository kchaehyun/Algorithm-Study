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