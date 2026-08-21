#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<bool> is_available(vector<int>* arr, int n) {
    vector<bool> available;
    for(int a : *arr) {
        if(a-n < 0) available.push_back(false);
        else available.push_back(true);
    }
    return available;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int left = *min_element(stones.begin(), stones.end());
    int right = *max_element(stones.begin(), stones.end());
    
    while(left <= right) {
        int mid = (left + right)/2;
        vector<bool> av = is_available(&stones, mid);
        int maxlen = 0, curlen = 0;
        for(int i = 0 ; i < av.size() ; ++i) {
            if(!av[i]) ++curlen;
            else curlen = 0;
            maxlen = max(maxlen, curlen);
        }
        if(maxlen >= k)
            right = mid-1;
        
        else {
            left = mid+1;
            answer = mid;
        }
    }
    
    return answer;
}