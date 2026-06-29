#include <iostream>
#include <vector>


using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int scores[3] = {0};
    int max_score = 0;
    vector<vector<int>> patterns = {{1,2,3,4,5},{2,1,2,3,2,4,2,5},{3,3,1,1,2,2,4,4,5,5}};
    
    for(int n = 0 ; n < answers.size() ; ++n)
        for (int i = 0 ; i < 3 ; ++i)
            if (patterns[i][n%patterns[i].size()] == answers[n]) scores[i]++;
    
    for(int i = 0 ; i < 3 ; ++i)
        if (max_score < scores[i]) max_score = scores[i];   
    
    for(int i = 0 ; i < 3 ; ++i)
        if (scores[i] == max_score) answer.push_back(i+1);

    return answer;
}

int main() {
    vector<int> answers = {1,2,3,4,5};
    vector<int> result = solution(answers);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}