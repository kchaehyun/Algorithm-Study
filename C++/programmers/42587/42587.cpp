// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int,int>> q;
    priority_queue<int> pq;
    for(int i = 0 ; i < priorities.size() ; ++i) {
        q.push({priorities[i],i});
        pq.push(priorities[i]);
    } 
    while(!q.empty()) {
        auto cur = q.front();
        q.pop();
        if(cur.first < pq.top())
            q.push(cur);
        else {
            answer++;
            pq.pop();
            if(cur.second == location) return answer;
        }
    }
    return answer;
}

int main() {
    vector<int> priorities = {2, 1, 3, 2};
    int location = 2;
    cout << solution(priorities, location) << endl; // Output: 1
    return 0;
}