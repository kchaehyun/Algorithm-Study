#include <string>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

vector<int> solution(vector<string> gems) {
    int gemssize = gems.size()+1;
    vector<int> answer = {1, gemssize};
    unordered_map<string,int> m;
    set<string> s;
    for(string g : gems) s.insert(g);
    int left = 0, right = 0;
    ++m[gems[0]];
    
    while(left < gems.size() && right < gems.size()) {
        if(m.size() == s.size()) {
            if(answer[1]-answer[0] > right-left)
                answer = {left+1, right+1};
            --m[gems[left]];
            if(!(m[gems[left]])) m.erase(gems[left]);
            ++left;
        }
        else if (m.size() < s.size()) {
            if(right == gems.size()-1) return answer;
            ++right;
            ++m[gems[right]];
        }
    }
    return answer;
}