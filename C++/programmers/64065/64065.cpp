#include <string>
#include <vector>
#include <unordered_set>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> l;
    unordered_set<int> used;
    vector<int> cur;
    string num;
    for(char c : s) {
        if(isdigit(c)) {
            num += c;
            continue;
        }
        if(!(num.empty())) {
            cur.push_back(stoi(num));
            num.clear();
        }
        if(c == '}' && !(cur.empty())) {
            l.push_back(cur);
            cur.clear();
        }
    }
    
    sort(l.begin(), l.end(), cmp);
    for(vector<int> li : l) {
        for(int n : li) {
            if(used.find(n) == used.end()) {
                answer.push_back(n);
                used.insert(n);
            }
        }
    }
    return answer;
}