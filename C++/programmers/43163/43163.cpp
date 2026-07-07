#include <string>
#include <vector>
#include <queue>

using namespace std;

bool isChange(const string& cur, const string& target) {
    int diff = 0;
    for(int i = 0 ; i < cur.size() ; ++i) {
        if(cur[i] != target[i]){
            diff++;
            if(diff > 1) return false;
        }
    }
    return true;
}

int bfs(const string& begin, const string& target, const vector<string>& words) {
    if(find(words.begin(), words.end(), target) == words.end()) return 0;
    int n = words.size();
    queue<pair<string,int>> q;
    q.push({begin,0});
    vector<bool> visited(n, false);
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.first == target) return cur.second;
        for(int i = 0 ; i < n ; ++i) {
            if(!visited[i] && isChange(cur.first, words[i])) {
                visited[i] = true;
                q.push({words[i],cur.second+1});
            }
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = bfs(begin,target,words);
    return answer;
}