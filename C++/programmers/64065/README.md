# Programmers 64065 - 튜플

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/64065)
- 중복되는 원소가 없는 튜플을 집합의 집합 형태로 표현한 문자열 `s`가 주어진다.
- 튜플의 앞에서부터 원소를 하나씩 추가해 만든 집합들은 원소의 개수가 1개, 2개, ..., `n`개가 된다.
- 집합에서는 원소의 순서가 바뀔 수 있으므로, 각 집합에 포함된 원소를 이용해 원래 튜플의 순서를 구해야 한다.

## 아이디어
- 문자열 `s`를 순회하면서 연속된 숫자를 하나의 정수로 변환하고, 각 중괄호 안의 숫자들을 하나의 집합으로 저장한다.
- 파싱한 집합들을 원소 개수가 적은 순서대로 정렬한다.
- 크기가 1인 집합부터 차례대로 확인하면, 이전 집합에는 없던 원소가 매 단계 하나씩 새롭게 추가된다.
- `unordered_set`에 이미 정답에 포함한 원소를 기록하고, 처음 등장한 원소를 정답 벡터에 추가한다.

## 시간복잡도
- 문자열 파싱에는 O(|s|)가 필요하다.
- 집합의 개수를 `N`이라고 하면 집합 정렬에는 O(N log N)이 필요하다.
- 정렬한 모든 집합의 원소를 확인하는 데 O(N²)이 필요하다.
- 따라서 전체 시간복잡도는 O(|s| + N log N + N²)이며, 간단히 O(|s| + N²)로 볼 수 있다.

## 풀이 과정
1. 문자열을 순회하며 숫자인 문자는 `num`에 이어 붙인다.
2. 숫자가 아닌 문자를 만나면 지금까지 모은 `num`을 정수로 변환해 `cur`에 추가한다.
3. 닫는 중괄호 `}`를 만났을 때 `cur`이 비어 있지 않다면 하나의 집합 파싱이 끝난 것이므로 `l`에 추가한다.
4. 모든 집합을 원소 개수가 적은 순서대로 정렬한다.
5. 정렬된 집합을 차례로 순회하며 아직 `used`에 없는 원소를 찾는다.
6. 새롭게 발견한 원소를 `answer`에 추가하고 `used`에도 기록한다.
7. 튜플의 모든 원소가 순서대로 저장된 `answer`를 반환한다.

## 코드 설명
```cpp
bool cmp(vector<int> a, vector<int> b) {
    return a.size() < b.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> l;
    unordered_set<int> used;
    vector<int> cur;
    string num;
    for(char c : s) {
        if(isdigit(c)) {
            num += c;
            continue;
        }
        if(!(num.empty())) {
            cur.push_back(stoi(num));
            num.clear();
        }
        if(c == '}' && !(cur.empty())) {
            l.push_back(cur);
            cur.clear();
        }
    }
    
    sort(l.begin(), l.end(), cmp);
    for(vector<int> li : l) {
        for(int n : li) {
            if(used.find(n) == used.end()) {
                answer.push_back(n);
                used.insert(n);
            }
        }
    }
    return answer;
}
```
- `cmp`는 각 집합의 크기를 비교하여 작은 집합이 앞에 오도록 정렬한다.
- `num`에는 여러 자리 숫자를 처리할 수 있도록 연속된 숫자 문자를 저장한다.
- `cur`은 현재 파싱 중인 집합의 원소들을 저장하고, 닫는 중괄호를 만나면 `l`로 옮겨진다.
- `used`는 이미 튜플에 추가한 원소를 평균 O(1)에 확인하기 위해 사용한다.
- 크기순으로 정렬된 각 집합에서 `used`에 없는 원소가 바로 현재 순서에 추가될 튜플의 원소이다.
