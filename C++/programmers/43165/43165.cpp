#include <string>
#include <vector>
#include <stack>

using namespace std;


int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack<pair<int,int>> s;
    s.push({0,0});
    while(!s.empty()) {
        auto cur = s.top();
        s.pop();
        int idx = cur.first;
        int sum = cur.second;
        if(idx == numbers.size()) {
            if(sum == target) answer++;
            continue;
        }
        s.push({idx + 1, sum+numbers[idx]});
        s.push({idx + 1, sum-numbers[idx]});
    }
    return answer;
}