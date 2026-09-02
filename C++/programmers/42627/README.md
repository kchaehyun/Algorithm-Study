# Programmers 42627 - 디스크 컨트롤러

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42627)
- 각 작업은 `[요청 시각, 소요 시간]` 형태로 주어진다.
- 하드디스크가 한 번에 하나의 작업만 수행할 수 있을 때, 작업의 요청부터 종료까지 걸린 시간의 평균을 최소화해야 한다.
- 대기 중인 작업은 소요 시간이 짧은 작업, 요청 시각이 빠른 작업, 작업 번호가 작은 작업 순으로 처리한다.
- 모든 작업의 반환 시간 평균에서 소수점 이하를 버린 값을 반환한다.

## 아이디어
- 작업을 요청 시각 기준으로 정렬해 현재 시각까지 들어온 작업을 차례대로 확인한다.
- 현재 처리할 수 있는 작업은 우선순위 큐에 넣는다.
- 우선순위 큐는 소요 시간이 짧은 작업이 먼저 나오도록 구성한다. 소요 시간이 같으면 요청 시각과 인덱스가 작은 작업을 우선한다.
- 작업을 하나 꺼내 처리한 뒤 `현재 시각 - 요청 시각`을 누적하면 해당 작업의 반환 시간을 구할 수 있다.
- 대기 중인 작업이 없다면 현재 시각을 다음 작업의 요청 시각으로 이동해 불필요한 반복을 피한다.

## 시간복잡도
- 작업 N개를 정렬하는 데 O(N log N)이 필요하다.
- 각 작업은 우선순위 큐에 한 번 삽입되고 한 번 제거되므로 O(N log N)이 필요하다.
- 전체 시간복잡도는 O(N log N)이고, 공간복잡도는 O(N)이다.

## 구현 과정
1. `jobs`를 요청 시각 기준으로 정렬한다.
2. 현재 시각 `curTime` 이전에 요청된 모든 작업을 우선순위 큐에 넣는다.
3. 대기 중인 작업이 있으면 우선순위가 가장 높은 작업을 꺼낸다.
4. 작업의 소요 시간만큼 `curTime`을 증가시키고 반환 시간을 `times`에 누적한다.
5. 대기 중인 작업이 없다면 `curTime`을 다음 작업의 요청 시각으로 이동한다.
6. 모든 작업을 처리할 때까지 위 과정을 반복한다.
7. 누적 반환 시간을 작업 수로 나눈 값을 반환한다.

## 코드 설명
```cpp
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Task {
    int time;
    int duration;
    int idx;
};

struct comp {
    bool operator()(Task a, Task b) {
        if(a.duration != b.duration) return a.duration > b.duration;
        if(a.time != b.time) return a.time > b.time;
        return a.idx > b.idx;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<Task, vector<Task>, comp> pq;
    int curTime = 0;
    int jobIdx = 0;
    int times = 0;
    sort(jobs.begin(), jobs.end());
    while(jobIdx < jobs.size() || !pq.empty()) {
        while(jobIdx < jobs.size() && curTime >= jobs[jobIdx][0]) {
            pq.push({jobs[jobIdx][0], jobs[jobIdx][1], jobIdx});
            ++jobIdx;
        }
        if(!pq.empty()) {
            Task curTask = pq.top();
            pq.pop();
            curTime += curTask.duration;
            times += curTime-curTask.time;
        }
        else curTime = jobs[jobIdx][0];
    }
    return times/jobs.size();
}
```
- `Task`는 작업의 요청 시각, 소요 시간, 정렬 후 인덱스를 저장한다.
- `comp`는 소요 시간, 요청 시각, 인덱스 순으로 우선순위를 비교한다.
- `jobIdx`는 아직 우선순위 큐에 넣지 않은 다음 작업을 가리킨다.
- `curTime`은 현재 시각이며, 작업을 처리할 때마다 소요 시간만큼 증가한다.
- `times`에는 각 작업의 종료 시각에서 요청 시각을 뺀 반환 시간을 누적한다.
- 정수 나눗셈인 `times / jobs.size()`를 반환하므로 평균의 소수점 이하는 자동으로 버려진다.
