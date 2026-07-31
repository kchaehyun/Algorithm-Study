#include <bits/stdc++.h>

using namespace std;

string toBinary(long long n) {
    string result = "";
    while(n > 0) {
        result += n%2 + '0';
        n /= 2;        
    }
    reverse(result.begin(), result.end());
    return result;
}

long long toDecimal(string binary) {
    long long result = 0;
    for(char b : binary) {
        result *= 2;
        result += b - '0';
    }
    return result;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(long long n : numbers) {
        if(!(n%2)) {
            answer.push_back(n+1);
            continue;
        }
        string num = "0" + toBinary(n);
        for(int i = num.size()-1 ; i >= 0 ; --i) {
            if(num[i] == '0') {
                num[i] = '1';
                num[i+1] = '0';
                break;
            }
        }
        long long decimal = toDecimal(num);
        answer.push_back(decimal);        
    }
    return answer;
}