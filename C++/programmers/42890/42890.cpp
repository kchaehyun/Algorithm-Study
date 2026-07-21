#include <string>
#include <vector>
#include <set>

using namespace std;

int solution(vector<vector<string>> relation) {
    int col = relation[0].size();
    int row = relation.size();
    vector<int> candidates = {};
    
    for(int i = 1 ; i <= (1<<col) ; ++i) {
        set<string> s;
        for(int r = 0 ; r < row ; ++r) {
            string comb = "";
            for(int c = 0 ; c < col ; ++c) {
                if((i & (1<<c)) != 0) comb += relation[r][c];
            }
            s.insert(comb);
        }
        if(s.size() == row) {
            bool isPossible = true;
            for(int key : candidates) {
                if((key&i) == key) {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) candidates.push_back(i);
        }
    }
    return candidates.size();
}