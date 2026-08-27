# Programmers 17683 - 방금그곡

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17683)
- 기억한 멜로디 `m`과 곡 정보가 담긴 `musicinfos`가 주어진다.
- 각 곡 정보는 `시작 시각,종료 시각,곡 제목,악보` 형식이다.
- 실제 재생된 멜로디는 재생 시간만큼 악보를 반복하고, 재생 시간이 악보보다 짧으면 앞부분만 재생한다.
- 실제 재생된 멜로디에 `m`이 포함되는 곡의 제목을 반환한다.
- 조건을 만족하는 곡이 여러 개라면 재생 시간이 가장 긴 곡을, 재생 시간도 같다면 먼저 입력된 곡을 반환한다.
- 조건을 만족하는 곡이 없으면 `"(None)"`을 반환한다.

## 아이디어
- `C#`처럼 두 문자로 표현되는 음을 그대로 비교하면 `C`가 `C#`의 일부로 잘못 검색될 수 있다.
- 샵이 붙은 음을 하나의 소문자 문자로 치환한다. 예를 들어 `C#`은 `c`, `D#`은 `d`로 변환한다.
- 기억한 멜로디와 각 곡의 악보를 같은 방식으로 정규화하면 문자 하나가 음 하나를 나타내므로 안전하게 부분 문자열을 검색할 수 있다.
- 시작 및 종료 시각을 분 단위로 바꾸어 재생 시간을 계산한다.
- 정규화한 악보를 재생 시간만큼 반복해 실제 재생 멜로디를 만든다.
- 실제 재생 멜로디에 기억한 멜로디가 포함되고, 현재까지 선택한 곡보다 재생 시간이 긴 경우에만 정답을 갱신한다.
- 재생 시간이 같은 경우 갱신하지 않으므로 입력 순서가 빠른 곡이 유지된다.

## 시간복잡도
- 곡의 수를 `N`, 각 곡의 재생 시간을 `P_i`, 악보 길이를 `L_i`라 하자.
- 실제 재생 멜로디 생성과 부분 문자열 검색에는 곡마다 `O(P_i + L_i)`가 필요하다.
- 전체 시간복잡도는 `O(|m| + Σ(P_i + L_i))`이다.

## 풀이 과정
1. `transform` 함수로 기억한 멜로디의 샵 음을 소문자 한 글자로 변환한다.
2. 각 곡 정보에서 시작 시각, 종료 시각, 곡 제목, 악보를 분리한다.
3. 종료 시각과 시작 시각의 차이로 재생 시간을 구한다.
4. 곡의 악보도 `transform` 함수로 정규화한다.
5. 정규화한 악보를 순환하며 재생 시간 길이의 실제 재생 멜로디를 만든다.
6. 실제 재생 멜로디에서 기억한 멜로디를 찾는다.
7. 일치하는 곡의 재생 시간이 기존 최댓값보다 클 때 곡 제목과 최댓값을 갱신한다.
8. 모든 곡을 확인한 뒤 선택된 제목을 반환한다.

## 코드 설명
```cpp
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
```
- `transform`은 결과 문자열에 음을 추가하다가 `#`을 만나면 직전 대문자 음을 제거하고 소문자로 다시 넣는다.
- `first`, `second`, `third`는 곡 정보에 있는 쉼표의 위치이며, 이를 기준으로 제목과 악보를 추출한다.
- `60 * 시 + 분`으로 시각을 분 단위로 바꾼 뒤 두 시각의 차이를 계산한다.
- `melody[i % melody.size()]`를 사용해 악보를 반복하면서 실제 재생된 음을 만든다.
- `play.find(m)`으로 기억한 멜로디가 실제 재생 멜로디에 포함되는지 확인한다.
- `playtime > curtime`일 때만 갱신하여 재생 시간이 같은 곡 중 먼저 입력된 곡을 선택한다.
