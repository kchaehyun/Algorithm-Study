# Programmers 64064 - 불량 사용자

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/64064)
- 이벤트 응모자 아이디 목록 `user_id`와 불량 사용자 아이디 패턴 목록 `banned_id`가 주어진다.
- 불량 사용자 아이디에는 일부 문자를 가린 `*` 문자가 포함될 수 있다.
- 각 불량 사용자 패턴마다 매칭되는 응모자 아이디를 하나씩 골라 제재 아이디 목록을 만들 때, 가능한 서로 다른 목록의 개수를 구한다.
- 같은 응모자 아이디는 한 번만 선택할 수 있으며, 제재 아이디 목록의 순서가 다르더라도 포함된 아이디가 같으면 같은 경우로 본다.

## 아이디어
- `match` 함수로 응모자 아이디가 불량 사용자 패턴과 일치하는지 확인한다.
- 두 문자열의 길이가 다르면 매칭될 수 없다.
- 길이가 같다면 각 문자를 비교하되, 불량 사용자 패턴의 문자가 `*`이면 어떤 문자와도 일치한다고 처리한다.
- `banned_id`의 인덱스를 기준으로 DFS를 수행하면서 현재 패턴에 매칭되는 아직 선택하지 않은 `user_id`를 고른다.
- 모든 불량 사용자 패턴에 대해 아이디를 선택했다면, 선택된 아이디들을 `set<string>`으로 만든다.
- 같은 아이디 조합은 순서와 상관없이 하나의 경우로 세야 하므로 `set<set<string>>`에 저장해 중복을 제거한다.

## 시간복잡도
- 응모자 수를 `N`, 불량 사용자 패턴 수를 `M`, 아이디 최대 길이를 `L`이라고 하자.
- 한 번의 매칭 검사에는 O(L)이 필요하다.
- DFS는 각 패턴마다 아직 선택하지 않은 응모자를 시도하므로 최악의 경우 O(P(N, M))개의 선택 순서를 탐색한다.
- 따라서 전체 시간복잡도는 O(P(N, M) × N × L) 수준으로 볼 수 있다.
- 문제의 제한에서 `N`과 `M`이 작기 때문에 완전 탐색으로 해결할 수 있다.

## 풀이 과정
1. `visited` 배열로 이미 제재 아이디로 선택한 응모자를 표시한다.
2. DFS의 깊이 `num`은 현재 처리할 `banned_id`의 인덱스를 의미한다.
3. 모든 `user_id`를 순회하면서 이미 선택한 아이디는 건너뛴다.
4. 현재 응모자 아이디가 `banned_id[num]` 패턴과 일치하면 선택하고 다음 깊이로 이동한다.
5. 재귀 호출이 끝나면 다른 조합을 탐색하기 위해 선택 표시를 해제한다.
6. `num == banned_id.size()`가 되면 하나의 제재 아이디 목록이 완성된 것이다.
7. `visited`가 참인 아이디들을 `set<string>`에 담아 `set<set<string>>`에 삽입한다.
8. 탐색이 끝나면 중복이 제거된 조합의 개수인 `s.size()`를 반환한다.

## 코드 설명
```cpp
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
```
- `match`는 응모자 아이디와 불량 사용자 패턴이 일치하는지 검사한다.
- `*`는 어떤 문자와도 매칭될 수 있으므로 비교를 건너뛴다.
- `dfs`는 현재 불량 사용자 패턴에 배정할 수 있는 응모자 아이디를 하나씩 선택한다.
- `visited`는 같은 응모자 아이디가 중복 선택되는 것을 막는다.
- `set<string>`은 완성된 제재 아이디 목록을 순서와 무관한 집합으로 표현한다.
- `set<set<string>>`은 같은 아이디 조합이 여러 선택 순서로 만들어져도 한 번만 세기 위해 사용한다.
