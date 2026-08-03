#include <string>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visited[11][11][4] = { false };
    int x = 5, y = 5;
    for(char c : dirs) {
        int nx = x, ny = y;
        int dir, rev;
        if(c == 'U') {
            ++ny;
            dir = 0;
            rev = 1;
        }
        else if(c == 'D') {
            --ny;
            dir = 1;
            rev = 0;
        }
        else if(c == 'R') {
            ++nx;
            dir = 2;
            rev = 3;
        }
        else if(c == 'L') {
            --nx;
            dir = 3;
            rev = 2;
        }
        
        if(0 <= nx && nx <= 10 && 0 <= ny && ny <= 10) {
            if(!visited[x][y][dir]) {
                ++answer;
                visited[x][y][dir] = true;
                visited[nx][ny][rev] = true;
            }
            x = nx;
            y = ny;
        }
    }
    return answer;
}