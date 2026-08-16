#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    unordered_map<string, string> m;
    vector<pair<string, string>> records;
    for(auto rec : record) {
        string command, uid, nickname;
        stringstream ss(rec);
        ss >> command >> uid;
        if(command == "Enter") {
            ss >> nickname;
            m[uid] = nickname;
            records.push_back({command,uid});
        }
        else if(command == "Leave") {
            records.push_back({command,uid});
        }
        else if(command == "Change") {
            ss >> nickname;
            m[uid] = nickname;
        }
    
    }
    for(auto r : records) {
        string command = r.first;
        string uid = r.second;
        if(command == "Enter") {
            string comment = m[uid] + "님이 들어왔습니다.";
            answer.push_back(comment);
        }
        else if(command == "Leave") {
            string comment = m[uid] + "님이 나갔습니다.";
            answer.push_back(comment);
        }
    }
    return answer;
}