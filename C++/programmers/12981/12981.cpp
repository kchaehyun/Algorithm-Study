#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    set<string> s;
    s.insert(words[0]);
    char before = words[0][words[0].size()-1];
    
    for(int i = 1 ; i < words.size() ; ++i) {
        if(words[i][0] != before || s.find(words[i]) != s.end())
            return {i%n + 1, i/n + 1};
        s.insert(words[i]);
        before = words[i][words[i].size()-1];
    }

    return {0,0};
}