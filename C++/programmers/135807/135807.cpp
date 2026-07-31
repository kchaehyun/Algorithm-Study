#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int maxA = 0, maxB = 0;
    int size = arrayA.size();
    int gcdA = arrayA[0], gcdB = arrayB[0];
    for(int i = 1 ; i < size ; ++i){
        gcdA = gcd(gcdA, arrayA[i]);
        gcdB = gcd(gcdB, arrayB[i]);
    }
    
    bool possible = true;
    for(int i = 0 ; i < size ; ++i) {
        if(!(arrayB[i] % gcdA)) {
            possible = false;
            break;
        }
    }
    if(!possible) gcdA = 0;
    
    possible = true;
    for(int i = 0 ; i < size ; ++i) {
        if(!(arrayA[i] % gcdB)) {
            possible = false;
            break;
        }
    }
    if(!possible) gcdB = 0;
    return max(gcdA,gcdB);
}