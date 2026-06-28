#include <string>
#include <vector>
#include <iostream>
// #include <algorithm>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> player;
    for(int i = 0 ; i < participant.size() ; ++i)
        player[participant[i]] ++;
    for(int i = 0 ; i < completion.size() ; ++i)
        player[completion[i]] --;
    for(auto x : player)
        if(x.second) return x.first;
    return "";
    // sort(participant.begin(), participant.end());
    // sort(completion.begin(), completion.end());
    // for(size_t i = 0 ; i < completion.size() ; ++i) {
    //     if(participant[i] != completion[i])
    //         return participant[i];
    // }
    // return participant.back();
}

int main() {
    vector<string> participant = {"leo", "kiki", "eden"};
    vector<string> completion = {"eden", "kiki"};
    cout << solution(participant, completion) << endl;
}