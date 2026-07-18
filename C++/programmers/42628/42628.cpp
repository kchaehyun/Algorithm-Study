#include <bits/stdc++.h>

using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<pair<int,int>> maxHeap;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
    vector<bool> valid(operations.size(), false);
    for(int i = 0 ; i < operations.size() ; ++i) {
        char command = operations[i][0];
        int num = stoi(operations[i].substr(2));
        if(command == 'I') {
            maxHeap.push({num, i});
            minHeap.push({num, i});
            valid[i] = true;
            continue;
        }
        if(num == 1) {
            while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();
            if(!maxHeap.empty()) {
                valid[maxHeap.top().second] = false;
                maxHeap.pop();
            }
        }
        else {
            while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
            if(!minHeap.empty()) {
                valid[minHeap.top().second] = false;
                minHeap.pop();
            }
        }
    }
    while(!maxHeap.empty() && !valid[maxHeap.top().second]) maxHeap.pop();
    while(!minHeap.empty() && !valid[minHeap.top().second]) minHeap.pop();
    
    if(maxHeap.empty() || minHeap.empty()) return {0,0};
    return {maxHeap.top().first, minHeap.top().first};
}