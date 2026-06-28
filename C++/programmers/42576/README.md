# Programmers 42576 - 완주하지 못한 선수

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42576)
- 마라톤 참가자 배열 `participant`와 완주자 배열 `completion`이 주어진다.
- 참가자 중 단 한 명만 완주하지 못했을 때, 그 선수의 이름을 찾아 반환한다.
- 동명이인이 있을 수 있다.

## 아이디어
- `unordered_map`을 사용해 참가자 이름별 등장 횟수를 센다.
- 완주자 이름을 순회하면서 해당 이름의 횟수를 1씩 감소시킨다.
- 최종적으로 횟수가 0이 아닌 이름이 완주하지 못한 선수다.
- 동명이인이 있어도 이름별 개수를 관리하므로 정확히 처리할 수 있다.

## 시간복잡도
- O(N)

## 풀이 과정
1. 참가자 이름과 등장 횟수를 저장할 `unordered_map<string, int>`를 만든다.
2. `participant`를 순회하며 각 이름의 개수를 1씩 증가시킨다.
3. `completion`을 순회하며 각 이름의 개수를 1씩 감소시킨다.
4. 맵을 순회하면서 개수가 남아 있는 이름을 반환한다.

## 코드 설명
```cpp
string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> player;

    for(int i = 0 ; i < participant.size() ; ++i)
        player[participant[i]] ++;

    for(int i = 0 ; i < completion.size() ; ++i)
        player[completion[i]] --;

    for(auto x : player)
        if(x.second) return x.first;

    return "";
}
```
- `player[participant[i]]++`는 참가자 이름의 등장 횟수를 증가시킨다.
- `player[completion[i]]--`는 완주한 선수의 이름 개수를 감소시킨다.
- 모든 완주자를 제거한 뒤 값이 남아 있는 이름이 완주하지 못한 선수다.
