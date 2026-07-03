#include <string>
#include <vector>
#include <algorithm>
// #include <bits/stdc++.h>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size()-1;
    while(left <= right) {
        if(people[right] + people[left] <= limit)
            left++;
        answer++;
        right--;
    }
    return answer;
}