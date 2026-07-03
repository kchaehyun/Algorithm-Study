# Programmers 42584 - 주식가격

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42584)
- 초 단위로 기록된 주식 가격 배열 `prices`가 주어진다.
- 각 시점의 가격이 떨어지지 않은 기간이 몇 초인지 구해 배열로 반환한다.
- 가격이 바로 다음 초에 떨어지면 1초 동안은 가격이 떨어지지 않은 것으로 본다.

## 아이디어
- 아직 가격이 떨어진 시점을 찾지 못한 인덱스를 `stack`에 저장한다.
- 현재 가격 `prices[i]`가 스택의 top 인덱스 가격보다 낮다면, 해당 top 인덱스의 가격은 현재 시점에 처음 떨어진 것이다.
- 이때 유지 시간은 `i - st.top()`이므로 `answer`에 저장하고 스택에서 제거한다.
- 현재 가격보다 큰 이전 가격들이 여러 개 있을 수 있으므로 `while`로 모두 처리한다.
- 끝까지 가격이 떨어지지 않은 인덱스들은 마지막 시점까지 유지된 것이므로 `prices.size() - 1 - index`를 저장한다.

## 시간복잡도
- 각 인덱스는 스택에 한 번 들어가고 한 번 나오므로 O(N)

## 풀이 과정
1. `answer`를 `prices`와 같은 크기의 0으로 초기화한다.
2. 가격이 떨어진 시점을 아직 모르는 인덱스를 저장할 `stack<int> st`를 만든다.
3. `prices`를 앞에서부터 순회한다.
4. 스택이 비어 있지 않고 `prices[st.top()] > prices[i]`라면, top 인덱스의 가격은 현재 시점 `i`에서 떨어진 것이다.
5. `answer[st.top()] = i - st.top()`으로 유지 시간을 저장하고 pop한다.
6. 현재 인덱스 `i`를 스택에 넣는다.
7. 순회가 끝난 뒤 스택에 남은 인덱스들은 끝까지 가격이 떨어지지 않았으므로 마지막 인덱스까지의 거리를 저장한다.

## 코드 설명
```cpp
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size(), 0);
    stack<int> st;
    for(int i = 0 ; i < prices.size() ; ++i) {
        while(!st.empty() && prices[st.top()] > prices[i]) {
            answer[st.top()] = i - st.top();
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty()) {
        answer[st.top()] = prices.size() - 1 - st.top();
        st.pop();
    }
    return answer;
}
```
- `st`에는 가격이 아직 떨어지지 않은 시점의 인덱스가 저장된다.
- `prices[st.top()] > prices[i]`이면 현재 가격이 이전 가격보다 낮아졌다는 뜻이다.
- 가격이 떨어진 순간 유지 기간은 현재 인덱스와 이전 인덱스의 차이인 `i - st.top()`이다.
- 마지막까지 스택에 남은 인덱스는 가격이 떨어지지 않았으므로 배열의 마지막 위치까지 버틴 시간으로 계산한다.
