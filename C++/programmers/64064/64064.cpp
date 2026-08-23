#include <string>
#include <vector>
#include <set>

using namespace std;

bool match(string user, string banned) {
    if(user.size() != banned.size()) return false;
    for(int i = 0 ; i < user.size() ; ++i) {
        if(banned[i] == '*') continue;
        if(user[i] != banned[i]) return false;
    }
    return true;
}

void dfs(int num, vector<string>& user_id, vector<string>& banned_id, vector<bool>& visited, set<set<string>>& s) {
    if(num == banned_id.size()) {
        set<string> cur;
        for(int i = 0 ; i < user_id.size() ; ++i)
            if(visited[i]) cur.insert(user_id[i]);
        s.insert(cur);
        return;
    }
    for(int i = 0 ; i < user_id.size() ; ++i) {
        if(visited[i]) continue;
        if(match(user_id[i], banned_id[num])) {
            visited[i] = true;
            dfs(num+1, user_id, banned_id, visited, s);
            visited[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    vector<bool> visited(user_id.size(), false);
    set<set<string>> s;
    dfs(0, user_id, banned_id, visited, s);
    return s.size();
}