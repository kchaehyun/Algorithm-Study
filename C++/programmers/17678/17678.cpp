#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int time(string s) {
    int hour = stoi(s.substr(0,2));
    int min = stoi(s.substr(3));
    int t = 60*hour + min;
    return t;
}

string toTime(int t) {
    string h = to_string(t/60);
    string m = to_string(t%60);
    if(t/60 < 10) h = "0" + to_string(t/60);    
    if(t%60 < 10) m = "0" + to_string(t%60);
    return h + ":" + m;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(), timetable.end());
    int idx = 0;
    int busTime;
    for(int i = 0 ; i < n ; ++i) {
        busTime = 540 + t*i;
        int people = 0;
        while(idx < timetable.size() && time(timetable[idx]) <= busTime && people < m) {
            ++people;
            ++idx;
        }
        if(i == n-1) {
            if(people < m) answer = toTime(busTime);
            else answer = toTime(time(timetable[--idx])-1);
        }
    }
    return answer;
}