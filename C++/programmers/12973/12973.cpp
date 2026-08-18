#include <iostream>
#include <string>
#include <stack>

using namespace std;

int solution(string s)
{
    stack<char> st;
    for(char c : s) {
        if(!st.empty() && st.top() == c)
            st.pop();
        else
            st.push(c);
    }
    if(!st.empty()) return 0;
    return 1;
}