#include <string>
#include <vector>

using namespace std;

string transform(string s) {
    string m;
    for(int i = 0 ; i < s.size() ; ++i) {
        if(s[i] == '#') {
            m.pop_back();
            m += tolower(s[i-1]);
            continue;
        }
        m += s[i];
    }
    return m;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    int curtime = -1;
    m = transform(m);
    for(string music : musicinfos) {
        int first = music.find(',');
        int second = music.find(',', first+1);
        int third = music.find(',', second+1);
        
        int startH = stoi(music.substr(0,2));
        int startM = stoi(music.substr(3,2));
        int endH = stoi(music.substr(6,2));
        int endM = stoi(music.substr(9,2));
        
        string name = music.substr(second+1, third-second-1);
        string melody = transform(music.substr(third+1));
        int playtime = 60*endH + endM - 60*startH - startM;
        
        string play;
        for(int i = 0 ; i < playtime ; ++i) {
            play.push_back(melody[i%melody.size()]);
        }
        
        if(play.find(m) != string::npos) {
            if (playtime > curtime) {
                curtime = playtime;
                answer = name;
            }
        }
    }
    return answer;
}