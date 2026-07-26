#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<int> elements) {
    int size = elements.size();
    set<int> sums;
    for(int i = 1 ; i <= size ; ++i) {
        for(int j = 0 ; j < size ; ++j) {
            int sum = 0;
            for(int k = 0 ; k < i ; ++k)
                sum += elements[(j+k)%size];
            sums.insert(sum);
        }
    }
    return sums.size();
}