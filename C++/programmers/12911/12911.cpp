#include <string>
#include <vector>

using namespace std;

int oneCnt(int n) {
    int cnt = 0;
    while(n > 0) {
        if(n%2) ++cnt;
        n /= 2;
    }
    return cnt;
}

int solution(int n) {
    int answer = n+1;
    while(oneCnt(n) != oneCnt(answer)) ++answer;
    return answer;
}