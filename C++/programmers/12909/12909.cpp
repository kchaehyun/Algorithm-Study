#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> sta;
    for(char c : s) {
        if (c == '(') sta.push(c);
        else {
            if (sta.empty()) return false;
            sta.pop();
        }
    }
    return sta.empty();    
}

int main() {
    string s = "(()())()";
    cout << solution(s) << endl; // Output: 1 (true)
    
    s = ")()(";
    cout << solution(s) << endl; // Output: 0 (false)
    
    s = "(()(";
    cout << solution(s) << endl; // Output: 0 (false)
    
    return 0;
}