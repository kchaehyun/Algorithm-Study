#include <string>
#include <map>

using namespace std;

int solution(string str1, string str2) {
    map<string, int> a;
    map<string, int> b;
    for(int i = 0 ; i < str1.size()-1 ; ++i) {
        string s;
        char first = tolower(str1[i]);
        char second = tolower(str1[i+1]);
        if(isalpha(first) && isalpha(second)) {
            s += first;
            s += second;
            a[s]++;
        }
    }
    for(int i = 0 ; i < str2.size()-1 ; ++i) {
        string s;
        char first = tolower(str2[i]);
        char second = tolower(str2[i+1]);
        if(isalpha(first) && isalpha(second)) {
            s += first;
            s += second;
            b[s]++;
        }
    }
    int inter = 0;
    int uni = 0;
    for(auto [word, cnt] : a) {
        inter += min(cnt, b[word]);
        uni += max(cnt, b[word]);
    }
    for(auto [word, cnt] : b) {
        if(a.find(word) == a.end()) uni += cnt;
    }
    if(inter == 0 && uni == 0) return 65536;
    return inter*65536/uni;
}