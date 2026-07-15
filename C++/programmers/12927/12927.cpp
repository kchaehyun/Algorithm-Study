#include <string>
#include <vector>
#include <queue>

using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    priority_queue<int> pq;
    for(int w : works) pq.push(w);
    for(int i = n ; i > 0 ; --i) {
        int maxVal = pq.top();
        if(!maxVal) return 0;
        pq.pop();
        pq.push(--maxVal);
    }
    while(!pq.empty()) {
        int n = pq.top();
        pq.pop();
        answer += n*n;
    }
    return answer;
}