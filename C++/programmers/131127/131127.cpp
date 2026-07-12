#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    for(int i = 0 ; i+9 < discount.size() ; ++i) {
        unordered_map<string, int> product;
        for(int j = i ; j < i+10 ; ++j)
            product[discount[j]]++;
        bool possible = true;
        for(int j = 0 ; j < want.size() ; ++j) {
            if(product[want[j]] != number[j]) {
                possible = false;
                break;
            }
        }
        if(possible) answer++;
    }
    return answer;
}