#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    int w = 0;
    int total = brown + yellow;
    for(int h = 3 ; h*h <= total ; ++h) {
        if(total%h != 0) continue;
        w = total / h;
        if((h-2)*(w-2) == yellow)
            return {w,h};
    }
    return {};
}