# Programmers 43165 - 타겟 넘버

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/43165)
- 사용할 수 있는 숫자 배열 `numbers`와 목표값 `target`이 주어진다.
- 각 숫자는 순서를 유지한 채 더하거나 빼서 사용할 수 있다.
- 모든 숫자를 사용해 만든 합이 `target`이 되는 방법의 수를 반환한다.

## 아이디어
- 각 숫자마다 `+`로 사용하는 경우와 `-`로 사용하는 경우가 있다.
- 모든 경우를 탐색해야 하므로 DFS 방식으로 상태를 확장한다.
- 상태는 현재 처리한 숫자의 인덱스 `idx`와 지금까지의 합 `sum`으로 표현한다.
- `idx`가 `numbers.size()`에 도달했을 때 `sum`이 `target`과 같으면 정답을 1 증가시킨다.
- 재귀 대신 `stack`을 사용해 DFS를 반복문으로 구현한다.

## 시간복잡도
- O(2^N)

## 풀이 과정
1. 정답 개수 `answer`를 0으로 초기화한다.
2. `stack<pair<int, int>>`에 시작 상태 `{0, 0}`을 넣는다.
3. 스택이 빌 때까지 상태를 하나씩 꺼낸다.
4. 현재 인덱스가 모든 숫자를 처리한 위치라면 현재 합이 `target`인지 확인한다.
5. 아직 처리할 숫자가 남아 있다면 현재 숫자를 더한 상태와 뺀 상태를 스택에 넣는다.
6. 모든 상태 탐색이 끝나면 `answer`를 반환한다.

## 코드 설명
```cpp
int solution(vector<int> numbers, int target) {
    int answer = 0;
    stack<pair<int,int>> s;
    s.push({0,0});
    while(!s.empty()) {
        auto cur = s.top();
        s.pop();
        int idx = cur.first;
        int sum = cur.second;
        if(idx == numbers.size()) {
            if(sum == target) answer++;
            continue;
        }
        s.push({idx + 1, sum+numbers[idx]});
        s.push({idx + 1, sum-numbers[idx]});
    }
    return answer;
}
```
- `s`는 DFS에서 방문해야 할 상태를 저장한다.
- `{idx, sum}`은 `idx`번째 숫자를 처리하기 전까지 만든 합이 `sum`이라는 뜻이다.
- `idx == numbers.size()`이면 모든 숫자를 사용한 상태이므로 `target`과 비교한다.
- `sum + numbers[idx]`는 현재 숫자를 더하는 경우이다.
- `sum - numbers[idx]`는 현재 숫자를 빼는 경우이다.
- 모든 가능한 부호 조합을 탐색하므로 `target`을 만들 수 있는 모든 방법을 셀 수 있다.
