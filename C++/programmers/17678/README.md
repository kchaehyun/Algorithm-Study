# Programmers 17678 - 셔틀버스

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/17678)
- 셔틀버스는 `09:00`부터 `t`분 간격으로 총 `n`회 운행하며, 한 번에 최대 `m`명이 탑승할 수 있다.
- 크루들의 도착 시각이 담긴 `timetable`이 주어진다.
- 셔틀은 출발 시각까지 도착한 크루를 도착 순서대로 태운다.
- 콘은 같은 시각에 도착한 크루 중 가장 뒤에 줄을 선다.
- 셔틀을 타고 사무실에 갈 수 있는 콘의 가장 늦은 도착 시각을 `HH:MM` 형식으로 반환한다.

## 아이디어
- `HH:MM` 형식은 시와 분이 두 자리로 고정되어 있으므로 문자열을 정렬하면 도착 시각순으로 정렬된다.
- 시각을 분 단위로 변환하여 셔틀 출발 시각과 비교한다.
- 각 셔틀에 먼저 도착한 크루부터 최대 `m`명씩 태우며, 다음에 탑승할 크루의 위치를 `idx`로 관리한다.
- 마지막 셔틀에 빈자리가 있다면 콘은 마지막 셔틀의 출발 시각에 도착해도 된다.
- 마지막 셔틀이 만석이라면 마지막으로 탑승한 크루보다 1분 일찍 도착해야 한다. 같은 시각에 도착하면 콘이 뒤에 서므로 탈 수 없다.

## 시간복잡도
- 크루의 수를 `N`, 셔틀 운행 횟수를 `n`이라 하면 정렬에 `O(N log N)`이 필요하다.
- `idx`는 앞으로만 이동하므로 전체 탑승 처리에 `O(N + n)`이 필요하다.
- 전체 시간복잡도는 `O(N log N + n)`이다.

## 풀이 과정
1. `timetable`을 오름차순으로 정렬한다.
2. 다음에 탑승할 크루를 가리키는 `idx`를 `0`으로 초기화한다.
3. 각 셔틀의 출발 시각을 `540 + t * i`로 계산한다. `540`은 `09:00`을 분으로 변환한 값이다.
4. 출발 시각까지 도착한 크루를 최대 `m`명 태우며 `people`과 `idx`를 증가시킨다.
5. 마지막 셔틀에서 `people < m`이면 출발 시각을 정답으로 정한다.
6. 만석이면 마지막으로 탑승한 크루의 도착 시각에서 1분을 뺀 값을 정답으로 정한다.
7. 정답 시각을 `HH:MM` 형식으로 변환하여 반환한다.

## 코드 설명
```cpp
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
```
- `time`은 `HH:MM` 문자열을 `60 * 시 + 분`으로 변환한다.
- `toTime`은 분 단위 시각을 문자열로 변환하며, 시와 분이 한 자리이면 앞에 `0`을 붙인다.
- `idx`는 아직 탑승하지 않은 첫 번째 크루의 인덱스이며, 셔틀이 바뀌어도 유지된다.
- `people`은 현재 셔틀에 탑승한 크루 수로, 셔틀마다 `0`으로 초기화한다.
- `while`문은 남은 크루가 있고, 해당 크루가 출발 시각까지 도착했으며, 좌석이 남아 있을 때 탑승시킨다.
- 마지막 셔틀이 만석일 때 `--idx`로 마지막 탑승 크루를 가리킨 뒤 도착 시각에서 1분을 뺀다.
