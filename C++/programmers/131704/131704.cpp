#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> s;
    queue<int> q;
    queue<int> o;
    for(int i = 0 ; i < order.size() ; ++i) {
        q.push(i+1);
        o.push(order[i]);
    }
    while(!o.empty()) {
        if(!q.empty() && q.front() == o.front()) {
            ++answer;
            o.pop();
            q.pop();
        }
        else if(!s.empty() && s.top() == o.front()) {
            ++answer;
            o.pop();
            s.pop();
        }
        else if(!q.empty()) {
            s.push(q.front());
            q.pop();
        }
        else break;        
    }
    return answer;
}