#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    if(A.front() > B.back()) return 0;
    
    int answer = 0;
    int i = 0, j = 0;
    
    while(i < A.size() && j < B.size()) {
        if(A[i] < B[j]) {
            ++i;
            ++j;
            ++answer;
        }
        else ++j;
    }
    
    return answer;
}