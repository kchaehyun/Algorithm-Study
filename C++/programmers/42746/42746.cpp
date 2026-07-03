// #include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool comp(string a, string b) {
    return a+b > b+a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for(int n : numbers) nums.push_back(to_string(n));
    sort(nums.begin(), nums.end(), comp);
    if (nums[0] == "0") return "0";
    for(string n : nums) answer += n;
    return answer;
}

int main() {
    vector<int> numbers = {3, 30, 34, 5, 9};
    cout << solution(numbers) << endl; // Output: "9534330"
    return 0;
}