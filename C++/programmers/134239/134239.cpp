#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> seq;
    while(k != 1) {
        seq.push_back(k);
        if(!(k%2)) k /= 2;
        else k = k*3 + 1;
    }
    seq.push_back(1);
    
    int n = seq.size() - 1;
    for(vector<int> range : ranges) {
        if(range[0] > n + range[1]) {
            answer.push_back(-1.0);
            continue;
        }
        double area = 0.0;
        for(int i = range[0] ; i < n+range[1] ; ++i)
            area += (seq[i] + seq[i+1]) / 2.0;
        answer.push_back(area);
    }
    return answer;
}