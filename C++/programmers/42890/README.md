# Programmers 42890 - 후보키

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42890)
- 관계형 데이터베이스의 릴레이션을 나타내는 2차원 문자열 배열 `relation`이 주어진다.
- 후보키는 각 튜플을 유일하게 식별할 수 있는 `유일성`과, 꼭 필요한 속성만 포함하는 `최소성`을 만족해야 한다.
- 주어진 릴레이션에서 만들 수 있는 후보키의 개수를 반환한다.

## 아이디어
- 열의 개수가 최대 8개이므로 열의 조합을 비트마스크로 표현해 모든 부분집합을 탐색한다.
- 비트마스크의 `c`번째 비트가 1이면 `c`번째 열을 키 조합에 포함한다.
- 각 행에서 선택된 열의 값을 이어 붙인 문자열을 `set`에 저장한다.
- `set`의 크기가 전체 행의 수와 같으면 모든 행을 구분할 수 있으므로 유일성을 만족한다.
- 이미 찾은 후보키가 현재 조합의 부분집합이라면 최소성을 만족하지 않으므로 제외한다.
- 유일성과 최소성을 모두 만족하는 비트마스크만 `candidates`에 저장한다.

## 시간복잡도
- 열의 수를 `C`, 행의 수를 `R`이라고 하면 모든 열 조합을 탐색하는 데 `2^C`가 필요하다.
- 각 조합마다 모든 행과 열을 확인하고 `set`에 값을 삽입하므로 O(2^C × R × (C + log R))이다.
- 열의 수가 최대 8이므로 완전 탐색으로 충분히 해결할 수 있다.

## 풀이 과정
1. 열의 수 `col`과 행의 수 `row`를 구한다.
2. 1부터 시작하는 비트마스크를 순회하며 비어 있지 않은 열 조합을 만든다.
3. 각 행마다 현재 비트마스크에 포함된 열의 문자열을 합쳐 `set`에 삽입한다.
4. `set`의 크기가 `row`와 같은지 확인해 유일성을 검사한다.
5. 유일성을 만족하면 기존 후보키 `key`에 대해 `(key & i) == key`인지 검사한다.
6. 위 조건이 참이면 기존 후보키가 현재 조합에 포함되어 있으므로 최소성을 만족하지 않는다.
7. 모든 기존 후보키를 포함하지 않는 조합만 새로운 후보키로 저장한다.
8. 탐색이 끝나면 저장된 후보키의 개수를 반환한다.

## 코드 설명
```cpp
int solution(vector<vector<string>> relation) {
    int col = relation[0].size();
    int row = relation.size();
    vector<int> candidates = {};
    
    for(int i = 1 ; i <= (1<<col) ; ++i) {
        set<string> s;
        for(int r = 0 ; r < row ; ++r) {
            string comb = "";
            for(int c = 0 ; c < col ; ++c) {
                if((i & (1<<c)) != 0) comb += relation[r][c];
            }
            s.insert(comb);
        }
        if(s.size() == row) {
            bool isPossible = true;
            for(int key : candidates) {
                if((key&i) == key) {
                    isPossible = false;
                    break;
                }
            }
            if(isPossible) candidates.push_back(i);
        }
    }
    return candidates.size();
}
```
- `i`는 현재 선택한 열의 조합을 나타내는 비트마스크이다.
- `i & (1 << c)`가 0이 아니면 현재 조합에 `c`번째 열이 포함되어 있다는 뜻이다.
- `s`에는 각 행에서 선택된 속성값을 조합한 문자열을 저장한다.
- `s.size() == row`이면 모든 행의 조합값이 서로 다르므로 유일성을 만족한다.
- `(key & i) == key`이면 기존 후보키 `key`의 모든 열이 현재 조합 `i`에 포함되어 있다는 뜻이다.
- 기존 후보키를 포함한 조합은 최소성을 만족하지 않으므로 `candidates`에 추가하지 않는다.
- 마지막에 `candidates.size()`를 반환해 후보키의 개수를 구한다.
