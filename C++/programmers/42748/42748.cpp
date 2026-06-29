#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    for(int c = 0 ; c < commands.size() ; ++c) {
        vector<int> tmp(array.begin() + commands[c][0] - 1, array.begin() + commands[c][1]);
        sort(tmp.begin(), tmp.end());
        answer.push_back(tmp[commands[c][2]-1]);
    }
    return answer;
}

int main() {
    vector<int> array = {1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> commands = {{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    vector<int> result = solution(array, commands);

    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}