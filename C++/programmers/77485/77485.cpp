#include <string>
#include <vector>

using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> matrix(rows, vector<int>(columns));
    for(int i = 0 ; i < rows ; ++i) {
        for(int j = 0 ; j < columns ; ++j)
            matrix[i][j] = columns*i + j + 1;
    }
    for(vector<int> q : queries) {
        int x1 = q[0]-1;
        int y1 = q[1]-1;
        int x2 = q[2]-1;
        int y2 = q[3]-1;
        int prev = matrix[x1][y1];
        int minVal = 101*101;
        for(int y = y1+1 ; y <= y2 ; ++y) {
            int tmp = matrix[x1][y];
            minVal = min(tmp, minVal);
            matrix[x1][y] = prev;
            prev = tmp;
        }
        for(int x = x1+1 ; x <= x2 ; ++x) {
            int tmp = matrix[x][y2];
            minVal = min(tmp, minVal);
            matrix[x][y2] = prev;
            prev = tmp;
        }
        for(int y = y2-1 ; y >= y1 ; --y) {
            int tmp = matrix[x2][y];
            minVal = min(tmp, minVal);
            matrix[x2][y] = prev;
            prev = tmp;
        }
        for(int x = x2-1 ; x >= x1 ; --x) {
            int tmp = matrix[x][y1];
            minVal = min(tmp, minVal);
            matrix[x][y1] = prev;
            prev = tmp;
        }
        answer.push_back(minVal);
    }
    return answer;
}