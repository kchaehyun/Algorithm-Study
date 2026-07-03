// #include <bits/stdc++.h>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n+1, 1);
    
    for(int i = 0 ; i < lost.size() ; ++i) {
        students[lost[i]]--;
    }
    for(int i = 0 ; i < reserve.size() ; ++i) {
        students[reserve[i]]++;
    }
    
    for(int i = 1 ; i < students.size() ; ++i) {
        if (!students[i]) {
            if (i > 1 && students[i-1] > 1) {
                students[i-1]--;
                students[i]++;
            }
            else if (i < n && students[i+1] > 1) {
                students[i+1]--;
                students[i]++;
            }
        }
    }
    
    for (int i = 1 ; i < students.size() ; ++i) {
        if (students[i] >= 1)
            answer++;
    }
    
    return answer;
}