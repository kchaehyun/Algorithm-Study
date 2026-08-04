#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr2[0].size(), 0));
    for(int r = 0 ; r < arr1.size() ; ++r) {
        for(int c = 0 ; c < arr2[0].size() ; ++c) {
            for(int n = 0 ; n < arr1[0].size() ; ++n) {
                answer[r][c] += arr1[r][n] * arr2[n][c];
            }
        }
    }
    return answer;
}