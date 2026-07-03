// #include <bits/stdc++.h>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st;
    for(int i = 0 ; i < prices.size() ; ++i) {
        while(!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }
    return answer;
}

int main() {
    vector<int> prices = {1, 2, 3, 2, 3};
    vector<int> result = solution(prices);
    for(int i = 0; i < result.size(); ++i) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}