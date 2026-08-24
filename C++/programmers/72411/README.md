# Programmers 72411 - 메뉴 리뉴얼

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/72411)
- 손님들이 주문한 단품 메뉴 조합 `orders`와 새 코스요리의 메뉴 개수 후보 `course`가 주어진다.
- 각 코스요리 메뉴 개수마다, 손님들이 가장 많이 함께 주문한 메뉴 조합을 찾아야 한다.
- 코스요리 후보는 최소 2명 이상의 손님에게 주문된 조합이어야 한다.
- 조건을 만족하는 모든 메뉴 조합을 오름차순으로 정렬해 반환한다.

## 아이디어
- 같은 메뉴 조합을 같은 문자열로 세기 위해 각 주문 문자열을 먼저 정렬한다.
- 코스 길이 `c`마다 모든 주문에서 길이 `c`인 조합을 만든다.
- 조합 문자열별 등장 횟수는 `unordered_map<string, int>`로 저장한다.
- 해당 길이에서 가장 많이 등장한 횟수를 구한 뒤, 그 횟수가 2 이상인 조합만 정답에 추가한다.
- 모든 코스 길이에 대한 탐색이 끝나면 정답 배열을 사전순으로 정렬한다.

## 시간복잡도
- 주문 수를 `N`, 주문 하나의 최대 메뉴 수를 `M`, 코스 길이 후보 수를 `K`라고 하자.
- 각 주문을 정렬하는 데 O(M log M)이 걸린다.
- 길이 `c`인 조합을 만드는 데 주문 하나당 O(C(M, c) × c)가 필요하다.
- 따라서 전체 시간복잡도는 대략 O(K × N × (M log M + C(M, c) × c)) 수준이다.
- 문제의 주문 문자열 길이가 작기 때문에 조합을 완전 탐색해도 충분하다.

## 풀이 과정
1. `course`의 각 길이 `c`에 대해 조합 등장 횟수를 저장할 `cnt`를 만든다.
2. 모든 주문 문자열을 정렬한다.
3. `combination` 함수로 현재 주문에서 길이 `c`인 모든 메뉴 조합을 생성한다.
4. 생성된 조합 문자열을 `cnt`에 기록한다.
5. `cnt`를 순회하며 가장 큰 등장 횟수 `maxCnt`를 구한다.
6. `maxCnt`가 2보다 작으면 코스요리 후보가 될 수 없으므로 건너뛴다.
7. 다시 `cnt`를 순회하면서 등장 횟수가 `maxCnt`인 조합을 정답에 추가한다.
8. 모든 길이에 대한 처리가 끝나면 정답을 오름차순으로 정렬해 반환한다.

## 코드 설명
```cpp
void combination(string& order, int start, int target, string cur, unordered_map<string, int>& count) {
    if(cur.size() == target) {
        count[cur]++;
        return;
    }
    for(int i = start ; i < order.size() ; ++i) {
        cur.push_back(order[i]);
        combination(order, i+1, target, cur, count);
        cur.pop_back();
    }
}
```
- `combination`은 `order`에서 `target`개 메뉴를 고르는 모든 조합을 만든다.
- `start`는 다음에 선택할 수 있는 메뉴의 시작 인덱스이다.
- `cur`의 길이가 `target`이 되면 하나의 조합이 완성되므로 `count[cur]`를 증가시킨다.
- 재귀 호출 후 `pop_back()`으로 방금 선택한 메뉴를 제거해 다음 조합을 탐색한다.

```cpp
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    for(int c : course) {
        unordered_map<string,int> cnt;
        for(string order : orders) {
            sort(order.begin(), order.end());
            combination(order, 0, c, "", cnt);
        }
        int maxCnt = 0;
        for(auto cn : cnt)
            maxCnt = max(maxCnt, cn.second);
        if(maxCnt < 2) continue;
        for(auto cn : cnt)
            if(cn.second == maxCnt) answer.push_back(cn.first);
    }
    sort(answer.begin(), answer.end());
    return answer;
}
```
- 코스 길이별로 조합 빈도를 따로 계산해야 하므로 `cnt`는 반복마다 새로 만든다.
- 주문 문자열을 정렬하면 같은 메뉴 조합이 항상 같은 문자열로 표현된다.
- `maxCnt`가 2 이상인 경우에만 가장 많이 주문된 조합들을 정답에 넣는다.
- 마지막 `sort(answer.begin(), answer.end())`는 문제에서 요구하는 사전순 정렬을 맞추기 위한 처리이다.
