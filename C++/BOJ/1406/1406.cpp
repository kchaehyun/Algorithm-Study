#include <vector>
#include <string>
#include <iostream>
#include <list>

using namespace std;


int main() {
    string s;
    list<char> editor;
    int n;
    char cmd;
    
    cin >> s >> n;
    for(auto c : s) editor.push_back(c);
    auto cursor = editor.end();
    auto tmpCursor = cursor;
    for(int i = 0 ; i < n ; ++i) {
        cin >> cmd;
        switch(cmd) {
            case 'L' :
                if(cursor == editor.begin()) continue;
                --cursor;
                break;
            case 'D' :
                if(cursor == editor.end()) continue;
                ++cursor;
                break;
            case 'B' :
                if(cursor == editor.begin()) continue;
                tmpCursor = cursor;
                --tmpCursor;
                editor.erase(tmpCursor);
                break;
            case 'P' :
                char x;
                cin >> x;
                editor.insert(cursor, x);
                break;
            
        }
    }
    for (auto c : editor) cout << c;
    return 0;
}