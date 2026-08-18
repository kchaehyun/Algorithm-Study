# Programmers 42888 - 오픈채팅방

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42888)
- 오픈채팅방에 들어오고 나가거나 닉네임을 변경한 기록 `record`가 주어진다.
- 사용자는 고유한 `uid`를 가지고, 닉네임은 `Enter`와 `Change` 명령에서 바뀔 수 있다.
- 최종 닉네임을 기준으로 채팅방 출입 메시지를 만들어 반환한다.

## 아이디어
- 같은 `uid`의 닉네임은 마지막으로 설정된 닉네임이 최종 닉네임이다.
- `Enter`와 `Change` 명령에서 `uid`별 닉네임을 `unordered_map`에 갱신한다.
- 실제 출력 메시지는 `Enter`와 `Leave`에 대해서만 만들어야 한다.
- 따라서 첫 번째 순회에서 닉네임을 갱신하면서 출력이 필요한 명령만 따로 저장한다.
- 모든 기록을 처리한 뒤 저장해 둔 명령들을 최종 닉네임으로 변환해 정답을 만든다.

## 시간복잡도
- 기록의 개수를 `N`, 각 문자열의 길이를 `L`이라고 하면 전체 기록을 파싱하는 데 O(N × L)이 필요하다.
- 이후 출력 대상 기록을 한 번 더 순회하므로 O(N)이다.
- 전체 시간복잡도는 O(N × L)이다.

## 풀이 과정
1. 최종 닉네임을 저장할 `unordered_map<string, string>`을 만든다.
2. 출력해야 하는 `Enter`, `Leave` 기록을 저장할 `vector<pair<string, string>>`을 만든다.
3. `record`를 순회하며 `stringstream`으로 명령어와 `uid`를 분리한다.
4. 명령어가 `Enter`이면 닉네임을 갱신하고 `{command, uid}`를 저장한다.
5. 명령어가 `Leave`이면 출력 대상이므로 `{command, uid}`를 저장한다.
6. 명령어가 `Change`이면 닉네임만 갱신하고 출력 대상에는 저장하지 않는다.
7. 저장해 둔 출력 대상 기록을 순회한다.
8. 각 `uid`의 최종 닉네임을 `map`에서 찾아 입장 또는 퇴장 메시지를 만들어 `answer`에 추가한다.
9. 모든 메시지를 만든 뒤 `answer`를 반환한다.

## 코드 설명
```cpp
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
```
- `m`은 `uid`별 최종 닉네임을 저장한다.
- `records`는 최종 메시지로 출력해야 하는 `Enter`, `Leave` 기록만 저장한다.
- `Change`는 닉네임 변경만 의미하므로 `m[uid]`만 갱신하고 `records`에는 넣지 않는다.
- 첫 번째 순회가 끝나면 `m`에는 모든 사용자의 최종 닉네임이 들어 있다.
- 두 번째 순회에서 `records`에 저장된 명령과 `uid`를 이용해 최종 닉네임 기준의 메시지를 만든다.
