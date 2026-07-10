# Programmers 42626 - 더 맵게

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42626)
- 모든 음식의 스코빌 지수를 `K` 이상으로 만들려고 한다.
- 스코빌 지수가 가장 낮은 두 음식을 섞어 새로운 음식을 만든다.
- 섞은 음식의 스코빌 지수는 `가장 맵지 않은 음식 + 두 번째로 맵지 않은 음식 * 2`이다.
- 모든 음식의 스코빌 지수를 `K` 이상으로 만들기 위해 섞어야 하는 최소 횟수를 반환한다.
- 모든 음식을 섞어도 `K` 이상으로 만들 수 없다면 `-1`을 반환한다.

## 아이디어
- 매번 스코빌 지수가 가장 낮은 음식 2개를 빠르게 꺼내야 한다.
- 최소값을 효율적으로 관리하기 위해 `priority_queue`를 최소 힙 형태로 사용한다.
- 현재 가장 작은 스코빌 지수가 `K`보다 작으면 가장 작은 값 2개를 꺼내 섞는다.
- 새로 만든 스코빌 지수를 다시 힙에 넣고 섞은 횟수를 증가시킨다.
- 음식이 1개만 남았는데도 `K`보다 작으면 더 이상 섞을 수 없으므로 `-1`을 반환한다.

## 시간복잡도
- 각 음식은 힙에 삽입되고 삭제될 수 있으며, 힙 연산은 O(log N)이다.
- 전체 시간복잡도는 O(N log N)이다.

## 풀이 과정
1. `priority_queue<int, vector<int>, greater<int>>`를 사용해 최소 힙을 만든다.
2. `scoville` 배열의 모든 값을 최소 힙에 넣는다.
3. 힙의 최솟값이 `K`보다 작은 동안 반복한다.
4. 가장 작은 값 `a`와 두 번째로 작은 값 `b`를 꺼낸다.
5. `a + b * 2`를 계산해 다시 힙에 넣는다.
6. 섞은 횟수 `answer`를 1 증가시킨다.
7. 음식이 1개만 남았고 그 값이 `K`보다 작으면 `-1`을 반환한다.
8. 반복이 끝나면 `answer`를 반환한다.

## 코드 설명
```cpp
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> sco;
    for(auto s : scoville) sco.push(s);
    while(sco.top() < K) {
        int a = sco.top();
        sco.pop();
        int b = sco.top();
        sco.pop();
        sco.push(a+b*2);
        answer++;
        if(sco.size() == 1 && sco.top() < K) return -1;
    }
    return answer;
}
```
- `priority_queue<int, vector<int>, greater<int>>`는 가장 작은 값이 `top()`에 오도록 하는 최소 힙이다.
- `sco.top() < K`이면 아직 조건을 만족하지 못한 음식이 있다는 뜻이다.
- `a`와 `b`는 현재 가장 맵지 않은 음식 2개의 스코빌 지수이다.
- `a + b * 2`로 새 스코빌 지수를 계산하고 다시 힙에 넣는다.
- 더 이상 섞을 음식이 부족한 경우 `-1`을 반환한다.
