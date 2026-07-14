#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    for(int m : money) {
        for(int i = m ; i < n+1 ; ++i) {
            dp[i] += dp[i-m];
        }
    }
    return dp[n];
}