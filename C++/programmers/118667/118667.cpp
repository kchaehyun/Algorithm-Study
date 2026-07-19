#include <string>
#include <vector>
#include <numeric>
#include <queue>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    long long sum1 = accumulate(queue1.begin(), queue1.end(), 0);
    long long sum2 = accumulate(queue2.begin(), queue2.end(), 0);
    if((sum1+sum2) % 2 != 0) return -1;
    
    int answer = 0;
    int maxN = (queue1.size() + queue2.size())*2;
    queue<int> q1;
    queue<int> q2;
    for(int q : queue1) q1.push(q);
    for(int q : queue2) q2.push(q);
    
    while(sum1 != sum2 && answer < maxN) {
        if(sum1 < sum2) {
            int num = q2.front();
            q2.pop();
            q1.push(num);
            sum1 += num;
            sum2 -= num;
        }
        else if(sum1 > sum2) {
            int num = q1.front();
            q1.pop();
            q2.push(num);
            sum1 -= num;
            sum2 += num;
        }
        ++answer;
    }
    // if(sum1 == sum2) return answer;
    // return -1;
    return sum1 == sum2 ? answer : -1;
}