#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// #include <bits/stdc++.h>

using namespace std;

bool solution(vector<string> phone_book) {
    sort(phone_book.begin(), phone_book.end());
    for(int i = 1; i < phone_book.size() ; ++i) {
        if(phone_book[i].substr(0, phone_book[i-1].size()) == phone_book[i-1])
            return false;
    }
    return true;
}

int main() {
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    cout << solution(phone_book) << endl; // Output: false
    return 0;
}