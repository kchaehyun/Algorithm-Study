#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(string s) {
    int i = 0;
    int zero = 0;
    while(s != "1") {
        ++i;
        string str;
        for(char c : s) {
            if(c == '0') {
                ++zero;
                continue;
            }
            str.push_back(c);
        }
        int num = str.size();
        string tmp;
        while(num > 0) {
            tmp.push_back((num%2) + '0');
            num /= 2;
        }
        reverse(tmp.begin(), tmp.end());
        s = tmp;
    }
    return {i,zero};
}