#include <string>
#include <vector>

using namespace std;

int solution(vector<int> citations) {
    int n = citations.size();
    sort(citations.begin(), citations.end());
    for(int i = 0 ; i < citations.size() ; ++i) {
        if(citations[i] >= n-i) return n-i;
    }
    return 0;
}