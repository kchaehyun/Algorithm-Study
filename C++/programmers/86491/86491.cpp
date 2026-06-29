#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int answer = 0;
    int tmp, max_w = 0, max_h = 0;
    for(int i = 0 ; i < sizes.size() ; ++i) {
        if (sizes[i][0] < sizes[i][1]) {
            // tmp = sizes[i][1];
            // sizes[i][1] = sizes[i][0];
            // sizes[i][0] = tmp;
            swap(sizes[i][0], sizes[i][1]);
        }
        if (max_w < sizes[i][0]) max_w = sizes[i][0];
        if (max_h < sizes[i][1]) max_h = sizes[i][1];
    }
    return max_w * max_h;
}

int main() {
    vector<vector<int>> sizes = {{60, 50}, {30, 70}, {60, 30}, {80, 40}};
    int result = solution(sizes);
    cout << result << endl; // Output: 4000

    return 0;
}