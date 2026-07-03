# Programmers 42587 - 프로세스

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42587)
- 실행 대기 큐에 있는 프로세스들의 우선순위 배열 `priorities`와 알고 싶은 프로세스의 위치 `location`이 주어진다.
- 큐의 앞 프로세스를 꺼냈을 때, 더 높은 우선순위의 프로세스가 남아 있으면 다시 큐의 뒤에 넣는다.
- 더 높은 우선순위가 없으면 해당 프로세스를 실행한다.
- `location`에 있던 프로세스가 몇 번째로 실행되는지 반환한다.

## 아이디어
- 실제 대기 순서는 `queue`로 관리한다.
- 현재 남아 있는 가장 높은 우선순위는 `priority_queue`로 관리한다.
- 큐에서 꺼낸 프로세스의 우선순위가 현재 최댓값보다 작으면 다시 뒤로 보낸다.
- 현재 최댓값과 같으면 실행하고, 실행 횟수를 증가시킨다.
- 실행한 프로세스의 원래 위치가 `location`이면 그때의 실행 횟수가 정답이다.

## 시간복잡도
- 각 프로세스가 여러 번 큐 뒤로 이동할 수 있으므로 최악의 경우 O(N^2)
- `priority_queue` 삽입과 삭제 비용은 O(log N)이다.

## 풀이 과정
1. `queue<pair<int, int>>`에 `{우선순위, 원래 위치}`를 저장한다.
2. `priority_queue<int>`에 모든 우선순위를 저장한다.
3. 큐가 빌 때까지 앞 프로세스를 꺼낸다.
4. 꺼낸 프로세스의 우선순위가 `pq.top()`보다 작으면 다시 큐 뒤에 넣는다.
5. 우선순위가 `pq.top()`과 같으면 실행 처리하고 `answer`를 1 증가시킨다.
6. 실행한 프로세스의 원래 위치가 `location`이면 `answer`를 반환한다.

## 코드 설명
```cpp
int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    priority_queue<int> pq;

    for (int i = 0; i < priorities.size(); ++i) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        if (cur.first < pq.top()) {
            q.push(cur);
        } else {
            answer++;
            pq.pop();
            if (cur.second == location) return answer;
        }
    }

    return answer;
}
```
- `q`는 프로세스의 현재 대기 순서를 저장한다.
- `pq.top()`은 아직 실행되지 않은 프로세스 중 가장 높은 우선순위다.
- `cur.first < pq.top()`이면 더 중요한 프로세스가 남아 있으므로 현재 프로세스를 뒤로 보낸다.
- 실행할 때마다 `answer`를 증가시키고, 실행된 프로세스의 원래 인덱스가 `location`인지 확인한다.
