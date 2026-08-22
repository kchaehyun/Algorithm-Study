# Programmers 138476 - 귤 고르기

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/138476)
- 한 상자에 담으려는 귤의 개수 `k`와 귤의 크기를 담은 배열 `tangerine`이 주어진다.
- 귤을 크기별로 분류했을 때, 서로 다른 크기의 수를 최소화해서 `k`개의 귤을 골라야 한다.
- 이때 선택한 귤들의 서로 다른 크기 종류 수의 최솟값을 반환한다.

## 아이디어
- 귤의 실제 크기보다 각 크기가 몇 개씩 있는지가 중요하다.
- 같은 크기의 귤이 많이 있을수록 한 종류만 선택해도 더 많은 귤을 채울 수 있다.
- 따라서 크기별 개수를 센 뒤, 개수가 많은 크기부터 선택하면 필요한 크기 종류 수를 최소화할 수 있다.
- 개수를 내림차순으로 꺼내기 위해 `priority_queue`를 사용한다.

## 풀이 과정
1. `unordered_map<int, int>`에 귤 크기별 개수를 저장한다.
2. 저장된 개수들을 `priority_queue<int>`에 넣는다.
3. 현재까지 선택한 귤의 개수 `cnt`가 `k` 이상이 될 때까지 가장 큰 개수를 하나씩 꺼낸다.
4. 개수를 꺼낼 때마다 `cnt`에 더하고, 선택한 크기 종류 수 `answer`를 1 증가시킨다.
5. `cnt`가 `k` 이상이 되면 `answer`를 반환한다.

## 코드 설명
```cpp
int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt = 0;
    unordered_map<int,int> m;
    for(int t : tangerine) m[t]++;
    
    priority_queue<int> q;
    for(auto pair : m) q.push(pair.second);
    
    while(cnt < k) {
        int num = q.top();
        q.pop();
        cnt += num;
        ++answer;
    }
    return answer;
}
```
- `m[t]++`는 귤 크기 `t`가 몇 개 있는지 센다.
- `priority_queue<int>`는 기본적으로 가장 큰 값이 먼저 나오므로, 가장 많은 귤을 가진 크기부터 선택할 수 있다.
- `cnt`는 지금까지 선택한 귤의 총개수이다.
- `answer`는 선택한 서로 다른 귤 크기의 개수이다.
- `cnt`가 `k` 이상이 되는 순간 필요한 귤 개수를 채웠으므로 반복을 종료한다.

## 시간복잡도
- 귤의 개수를 `N`, 서로 다른 귤 크기의 개수를 `M`이라고 하면 크기별 개수를 세는 데 O(N)이 걸린다.
- `M`개의 개수를 우선순위 큐에 넣는 데 O(M log M)이 걸린다.
- 최악의 경우 모든 크기를 꺼낼 수 있으므로 우선순위 큐에서 꺼내는 과정은 O(M log M)이다.
- 따라서 전체 시간복잡도는 O(N + M log M)이다.
- `unordered_map`과 `priority_queue`에 최대 `M`개의 값이 저장되므로 공간복잡도는 O(M)이다.
