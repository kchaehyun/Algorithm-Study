# Programmers 67268 - 보석 쇼핑

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/67268)
- 진열대에 놓인 보석 이름 배열 `gems`가 주어진다.
- 모든 종류의 보석을 적어도 하나씩 포함하는 가장 짧은 구간을 찾아야 한다.
- 구간의 길이가 같다면 시작 진열대 번호가 가장 작은 구간을 반환한다.
- 진열대 번호는 1번부터 시작한다.

## 아이디어
- 전체 보석 종류의 개수는 `set`에 모든 보석 이름을 넣어 구한다.
- 현재 구간에 포함된 보석별 개수는 `unordered_map<string, int>`로 관리한다.
- 투 포인터를 사용해 `[left, right]` 구간을 유지한다.
- 현재 구간이 모든 보석 종류를 포함하면 정답 후보를 갱신하고, 더 짧은 구간을 찾기 위해 `left`를 오른쪽으로 이동한다.
- 현재 구간에 포함된 보석 종류가 부족하면 `right`를 오른쪽으로 이동하며 보석을 추가한다.

## 시간복잡도
- 각 포인터는 최대 `N`번씩 이동한다.
- `unordered_map`의 삽입, 삭제, 조회는 평균 O(1)이고, `set`에 전체 보석 종류를 저장하는 데 O(N log N)이 필요하다.
- 따라서 전체 시간복잡도는 O(N log N)이다.

## 풀이 과정
1. `set`에 모든 보석 이름을 넣어 필요한 보석 종류의 수를 구한다.
2. `left`와 `right`를 0으로 두고 첫 번째 보석을 현재 구간에 추가한다.
3. 현재 구간의 보석 종류 수가 전체 종류 수와 같으면 모든 보석을 포함한 구간이다.
4. 기존 정답보다 현재 구간이 더 짧으면 1-based 인덱스로 정답을 갱신한다.
5. `gems[left]`의 개수를 줄이고, 개수가 0이 되면 `unordered_map`에서 제거한 뒤 `left`를 증가시킨다.
6. 현재 구간의 보석 종류 수가 부족하면 `right`를 증가시키고 새 보석을 구간에 추가한다.
7. `right`가 마지막 위치인데도 종류가 부족하면 더 이상 구간을 확장할 수 없으므로 현재 정답을 반환한다.

## 코드 설명
```cpp
vector<int> solution(vector<string> gems) {
    int gemssize = gems.size()+1;
    vector<int> answer = {1, gemssize};
    unordered_map<string,int> m;
    set<string> s;
    for(string g : gems) s.insert(g);
    int left = 0, right = 0;
    ++m[gems[0]];
    
    while(left < gems.size() && right < gems.size()) {
        if(m.size() == s.size()) {
            if(answer[1]-answer[0] > right-left)
                answer = {left+1, right+1};
            --m[gems[left]];
            if(!(m[gems[left]])) m.erase(gems[left]);
            ++left;
        }
        else if (m.size() < s.size()) {
            if(right == gems.size()-1) return answer;
            ++right;
            ++m[gems[right]];
        }
    }
    return answer;
}
```
- `answer`는 `{시작 번호, 끝 번호}` 형태로 저장하며, 초기 끝 번호를 `gems.size() + 1`로 두어 첫 후보가 반드시 갱신되게 한다.
- `s.size()`는 전체 보석 종류 수이고, `m.size()`는 현재 구간에 포함된 보석 종류 수이다.
- `m.size() == s.size()`이면 현재 구간이 모든 보석을 포함하므로 정답 후보가 된다.
- `answer[1] - answer[0] > right - left`로 구간 길이를 비교한다.
- `left`를 이동할 때 보석 개수가 0이 된 경우 `m.erase`로 제거해야 현재 구간의 보석 종류 수가 정확히 유지된다.
- `right`가 마지막 인덱스에 도달한 상태에서 모든 종류를 포함하지 못하면 더 이상 탐색할 구간이 없으므로 바로 반환한다.
