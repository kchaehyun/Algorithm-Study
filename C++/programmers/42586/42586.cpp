
// #include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i = 0 ; i < progresses.size() ; ++i) {
        if((100-progresses[i])%speeds[i] == 0)
            days.push_back((100-progresses[i])/speeds[i]);
        else
            days.push_back((100-progresses[i])/speeds[i]+1);
    }
    int day = days[0];
    int func = 1;
    for(int i = 1 ; i < days.size() ; ++i) {
        if(days[i] <= day) 
            func++;
        else {
            answer.push_back(func);
            func = 1;
            day = days[i];
        }
    }
    answer.push_back(func);
    return answer;
}

int main() {
    vector<int> progresses = {93, 30, 55};
    vector<int> speeds = {1, 30, 5};
    vector<int> result = solution(progresses, speeds);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}