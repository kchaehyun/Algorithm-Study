#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> arr) {
    int answer = 1;
    unordered_map<int,int> m;
    for(int a : arr) {
        for(int i = 2 ; i <= a ; ++i) {
            int cnt = 0;
            while(!(a%i)) {
                a /= i;
                ++cnt;
            }
            if(cnt != 0) m[i] = max(m[i], cnt);
        }
    }
    for(auto nums : m) {
        int num = nums.first;
        int times = nums.second;
        for(int i = 1 ; i <= times; ++i) answer *= num;
    }
    return answer;
}