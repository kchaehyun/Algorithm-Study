#include <string>
#include <vector>

using namespace std;

long long solution(string expression) {
    long long answer = 0;
    vector<string> combinations = {"+-*", "+*-", "-+*", "-*+", "*+-", "*-+"};
    vector<long long> nums;
    vector<char> ops;
    string tmp;
    for(char c : expression) {
        if(c == '+' || c == '-' || c == '*') {
            nums.push_back(stoll(tmp));
            ops.push_back(c);
            tmp = "";
            continue;
        }
        tmp += c;
    }
    nums.push_back(stoll(tmp));
    for(string combination : combinations) {
        vector<long long> tmpNums = nums;
        vector<char> tmpOps = ops;
        for(char c : combination) {
            int i = 0;
            while(i < tmpOps.size()) {
                if(c == tmpOps[i]) {
                    if(c == '+') {
                        tmpNums[i] += tmpNums[i+1];
                    }
                    else if(c == '-') {
                        tmpNums[i] -= tmpNums[i+1];
                    }
                    else if(c == '*') {
                        tmpNums[i] *= tmpNums[i+1];
                    }
                    tmpNums.erase(tmpNums.begin() + i+1);
                    tmpOps.erase(tmpOps.begin() + i);
                    continue;
                }
                ++i;
            }
        }
        answer = max(answer, abs(tmpNums[0]));
    }
    return answer;
}