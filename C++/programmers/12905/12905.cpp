// #include <bits/stdc++.h>
#include <string>
#include <vector>


using namespace std;

int solution(vector<vector<int>> board)
{
    int maxLen = 0;
    
    for(int i = 0 ; i < board.size() ; ++i) {
        for(int j = 0 ; j < board[0].size() ; ++j) {
            if(board[i][j] != 0 && i > 0 && j > 0)
                board[i][j] = min({board[i-1][j], board[i][j-1], board[i-1][j-1]}) + 1;
            maxLen = max(maxLen, board[i][j]);
        }
    }

    return maxLen * maxLen;
}