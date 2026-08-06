#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string transform(int num, int n) {
    string digits = "0123456789ABCDEF";
    string s = "";
    while(num > 0) {
        s = digits[num%n] + s;
        num /= n;
    }
    return s;
}

string solution(int n, int t, int m, int p) {
    string answer = "";
    string nums = "0";
    int i = 1;
    while(nums.size() <= t*m) {
        nums += transform(i,n);
        ++i;
    }
    
    for(int i = p-1 ; i < p + t*m -1 ; i += m)
        answer += nums[i];
    
    return answer;
}