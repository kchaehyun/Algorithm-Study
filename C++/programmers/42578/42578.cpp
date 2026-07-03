// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string,int> clo;
    for(auto c : clothes) {
        clo[c[1]]++;
    }
    for(auto c : clo) {
        answer *= (c.second+1);
    }
    return answer-1;
}

int main() {
    vector<vector<string>> clothes = {{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    cout << solution(clothes) << endl; // Output: 5
    return 0;
}
