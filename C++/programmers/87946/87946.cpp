#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int answer = 0;
vector<bool> visited(8,false);


void dfs(int tired, int num, vector<vector<int>>& dungeons) {
    answer = max(answer, num);
    for(int i = 0 ; i < dungeons.size() ; ++i) {
        if(!visited[i] && tired >= dungeons[i][0]) {
            visited[i] = true;
            dfs(tired - dungeons[i][1], num+1, dungeons);
            visited[i] = false;
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, 0, dungeons);
    return answer;
}