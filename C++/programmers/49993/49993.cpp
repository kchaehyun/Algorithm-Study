#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for(string st : skill_trees) {
        string word;
        for(char c : st) {
            if(find(skill.begin(), skill.end(), c) != skill.end()) word += c;
        }
        if(skill.starts_with(word)) ++answer;
    }
    return answer;
}