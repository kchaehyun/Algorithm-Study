#include <string>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt = 0;
    unordered_map<int,int> m;
    for(int t : tangerine) m[t]++;
    
    priority_queue<int> q;
    for(auto pair : m) q.push(pair.second);
    
    while(cnt < k) {
        int num = q.top();
        q.pop();
        cnt += num;
        ++answer;
    }
    return answer;
}