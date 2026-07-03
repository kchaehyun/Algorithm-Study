# Programmers 42583 - 다리를 지나는 트럭

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42583)
- 다리 길이 `bridge_length`, 다리가 견딜 수 있는 최대 무게 `weight`, 트럭 무게 배열 `truck_weights`가 주어진다.
- 트럭은 1초에 1만큼 이동한다.
- 다리 위 트럭들의 무게 합이 `weight`를 넘지 않도록 트럭을 올려야 한다.
- 모든 트럭이 다리를 건너는 데 걸리는 시간을 반환한다.

## 아이디어
- 다리 위에 있는 트럭만 `queue`로 관리한다.
- 큐에는 `{트럭 무게, 다리에서 나갈 시간}`을 저장한다.
- 매초 시간이 1씩 증가할 때, 큐의 앞 트럭이 나갈 시간이 되었으면 다리에서 제거한다.
- 다음 트럭을 올려도 최대 무게를 넘지 않으면 다리에 올린다.
- 모든 트럭이 다리에 올라갔고, 다리 위 큐도 비면 시뮬레이션을 종료한다.

## 시간복잡도
- 각 트럭은 큐에 한 번 들어가고 한 번 나오므로 O(N)

## 풀이 과정
1. 현재 시간 `time`, 다리 위 총 무게 `current_weight`, 다음 트럭 인덱스 `idx`를 초기화한다.
2. 다리 위 트럭을 저장할 `queue<pair<int, int>>`를 만든다.
3. 아직 대기 중인 트럭이 있거나 다리 위에 트럭이 있으면 반복한다.
4. 시간을 1 증가시킨다.
5. 큐의 앞 트럭이 현재 시간에 다리에서 나가야 하면 무게를 빼고 큐에서 제거한다.
6. 다음 트럭을 올릴 수 있으면 현재 무게에 더하고, 나갈 시간을 `time + bridge_length`로 저장한다.
7. 반복이 끝나면 `time`을 반환한다.

## 코드 설명
```cpp
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int time = 0, current_weight = 0, idx = 0;
    queue<pair<int, int>> bridge;

    while (!bridge.empty() || idx < truck_weights.size()) {
        time++;

        if (!bridge.empty() && bridge.front().second == time) {
            current_weight -= bridge.front().first;
            bridge.pop();
        }

        if (idx < truck_weights.size() && current_weight + truck_weights[idx] <= weight) {
            current_weight += truck_weights[idx];
            bridge.push({truck_weights[idx], time + bridge_length});
            idx++;
        }
    }

    return time;
}
```
- `bridge`는 현재 다리 위에 있는 트럭들을 저장한다.
- `bridge.front().second == time`이면 가장 앞 트럭이 다리를 빠져나갈 시간이다.
- `current_weight`로 다리 위 트럭들의 무게 합을 관리한다.
- 트럭을 새로 올릴 때는 해당 트럭이 다리에서 나갈 시간을 함께 저장한다.
