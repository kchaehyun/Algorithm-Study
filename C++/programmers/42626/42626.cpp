#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> sco;
    for(auto s : scoville) sco.push(s);
    while(sco.top() < K) {
        int a = sco.top();
        sco.pop();
        int b = sco.top();
        sco.pop();
        sco.push(a+b*2);
        answer++;
        if(sco.size() == 1 && sco.top() < K) return -1;
    }
    return answer;
}