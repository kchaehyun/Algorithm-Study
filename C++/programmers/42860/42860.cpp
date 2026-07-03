#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int up(char target, char original) {
    return target-original;
}

int down(char target, char original) {
    return original+26-target;
}

int solution(string name) {
    int answer = 0;
    int next = 0;
    int name_size = name.size();
    int move = name_size - 1;
    for(int i = 0 ; i < name_size ; ++i) {
        answer += min(up(name[i],'A'), down(name[i],'A'));
        
        // 연속된 A 구간 찾기
        next = i+1;
        while(next < name_size && name[next] == 'A') next++;
        
        // 최소 이동 횟수
        move = min(move, i*2 + (name_size-next));
        move = min(move, (name_size-next)*2 + i);
        
    }
    return answer+move;
}