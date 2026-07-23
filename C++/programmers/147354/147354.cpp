#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int sortCol;

bool cmp(vector<int>& a, vector<int>& b) {
    if(a[sortCol] == b[sortCol]) return a[0] > b[0];
    return a[sortCol] < b[sortCol];
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = 0;
    sortCol = col-1;
    sort(data.begin(), data.end(), cmp);
    for(int i = row_begin-1 ; i < row_end ; ++i) {
        int sum = 0;
        for(int j = 0 ; j < data[0].size() ; ++j)
            sum += data[i][j]%(i+1);
        answer ^= sum;
    }
    return answer;
}