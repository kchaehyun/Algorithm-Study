#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> nums;
    long long factorial[21];
    factorial[0] = 1;
    for(int i = 1 ; i <= 20 ; ++i) {
        factorial[i] = factorial[i-1] * i;
    }
    for(int i = 1 ; i <= n ; ++i) nums.push_back(i);
    k--;
    for(int i = n ; i > 0 ; --i) {
        if(i == 1) {
            answer.push_back(nums[0]);
            break;
        }
        long long digit = factorial[i-1];
        answer.push_back(nums[k/digit]);
        nums.erase(nums.begin() + k/digit);
        k = k%digit;
        
    }
    return answer;
}