#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

void combination(string& order, int start, int target, string cur, unordered_map<string, int>& count) {
    if(cur.size() == target) {
        count[cur]++;
        return;
    }
    for(int i = start ; i < order.size() ; ++i) {
        cur.push_back(order[i]);
        combination(order, i+1, target, cur, count);
        cur.pop_back();
    }
}

vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int c : course) {
        unordered_map<string,int> cnt;
        for(string order : orders) {
            sort(order.begin(), order.end());
            combination(order, 0, c, "", cnt);
        }
        int maxCnt = 0;
        for(auto cn : cnt)
            maxCnt = max(maxCnt, cn.second);
        if(maxCnt < 2) continue;
        for(auto cn : cnt)
            if(cn.second == maxCnt) answer.push_back(cn.first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}