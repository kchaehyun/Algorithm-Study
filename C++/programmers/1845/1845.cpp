#include <iostream>
#include <vector>
#include <unordered_set>
// #include <bits/stdc++.h>

using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    unordered_set<int> poke;
    for(int n : nums) poke.insert(n);
    if (nums.size()/2 > poke.size()) return poke.size();
    return nums.size()/2;
}

int main() {
    vector<int> nums = {3, 1, 2, 3};
    cout << solution(nums) << endl; // Output: 2
    return 0;
}