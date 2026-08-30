#include <string>
#include <vector>

using namespace std;

bool correct(string u) {
    int cnt = 0;
    for(char c : u) {
        if(c == '(') ++cnt;
        else --cnt;
        if(cnt < 0) return false;
    }
    if(!cnt) return true;
    return false;
}

string solution(string p) {
    string answer = "";
    if(p == "") return "";
    int cnt = 0;
    string u, v;
    for(int i = 0 ; i < p.size() ; ++i) {
        if(p[i] == '(') ++cnt;
        else --cnt;
        if(!cnt) {
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    if(correct(u)) return u + solution(v);
    else {
        answer += '(';
        answer += solution(v);
        answer += ')';
        for(int i = 1 ; i < u.size() - 1 ; ++i) {
            if(u[i] == '(') answer += ')';
            else answer += '(';
        }
    }
    return answer;
}