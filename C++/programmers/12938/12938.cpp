#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    if(n > s) return {-1};
    int remainder = s%n;
    vector<int> answer(n, s/n);
    for(int i = n-1 ; i >= n-remainder ; --i)
        answer[i]++;
    return answer;
}