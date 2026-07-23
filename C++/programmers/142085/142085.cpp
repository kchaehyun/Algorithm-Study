#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int i = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    pq.push(enemy[0]);
    while(!pq.empty() && i < enemy.size()) {
        pq.push(enemy[i]);
        if(pq.size() > k) {
            int minNum = pq.top();
            pq.pop();
            if(n < minNum) return i;
            n -= minNum;
        }
        ++i;
    }
    return enemy.size();
}