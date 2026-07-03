// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int time = 0, current_weight = 0, idx = 0;
    queue<pair<int,int>> bridge;
    while(!bridge.empty() || idx < truck_weights.size()) {
        time++;
        if(!bridge.empty() && bridge.front().second == time) {
            current_weight -= bridge.front().first;
            bridge.pop();
        }
        if(idx < truck_weights.size() && current_weight + truck_weights[idx] <= weight) {
            current_weight += truck_weights[idx];
            bridge.push({truck_weights[idx],time+bridge_length});
            idx++;
        }
    }
    return time;
}

int main() {
    vector<int> truck_weights = {7, 4, 5, 6};
    int bridge_length = 2;
    int weight = 10;
    cout << solution(bridge_length, weight, truck_weights) << endl; // Output: 8
    return 0;
}