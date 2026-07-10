
#include <string>
#include <vector>
#include <stack>

using namespace std;

void dfs(int i, vector<vector<int>> computers, vector<bool>& visited) {
    visited[i] = true;
    stack<int> s;
    s.push(i);
    while(!s.empty()) {
        int cur = s.top();
        s.pop();
        for(int j = 0 ; j < computers.size() ; ++j) {
            if(computers[cur][j] == 1 && !visited[j]) {
                visited[j] = true;
                s.push(j);
            }
        }
        
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> v(n, false);
    for(int i = 0 ; i < n ; ++i) {
        if(!v[i]) {
            answer++;
            dfs(i,computers,v);
        }
    }
    
    return answer;
}