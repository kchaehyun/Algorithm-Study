# Programmers 92341 - 주차 요금 계산

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/92341)
- 주차장의 요금표 `fees`와 차량의 입·출차 기록 `records`가 주어진다.
- 차량별 누적 주차 시간을 구한 뒤 요금표에 따라 주차 요금을 계산한다.
- 입차 기록만 있고 출차 기록이 없는 차량은 `23:59`에 출차한 것으로 처리한다.
- 차량 번호가 작은 순서대로 각 차량의 주차 요금을 반환한다.

## 아이디어
- 입차 중인 차량의 입차 시각은 `unordered_map<int, string> parking`에 저장한다.
- 출차 기록을 만나면 입차 시각과 출차 시각의 차이를 계산하여 `totalTime`에 누적하고, 해당 차량을 `parking`에서 제거한다.
- 모든 기록을 처리한 뒤 `parking`에 남은 차량은 `23:59`에 출차한 것으로 간주하여 시간을 누적한다.
- `totalTime`을 `map<int, int>`으로 관리하면 차량 번호가 작은 순서대로 자동 정렬되므로, 순서대로 요금을 계산해 정답에 넣을 수 있다.
- 기본 시간을 초과한 경우 단위 시간은 올림하여 계산한다.

## 시간복잡도
- 기록의 개수를 `N`, 차량의 수를 `M`이라고 할 때 `map` 삽입과 순회가 포함되므로 O(N log M)이다.

## 풀이 과정
1. `fees`에서 기본 시간, 기본 요금, 단위 시간, 단위 요금을 꺼낸다.
2. 각 기록을 `stringstream`으로 분리하여 시각, 차량 번호, 입·출차 상태를 얻는다.
3. `IN`이면 차량 번호와 입차 시각을 `parking`에 저장한다.
4. `OUT`이면 입차부터 출차까지의 시간을 `totalTime`에 더하고 `parking`에서 삭제한다.
5. 기록 처리가 끝난 후 남아 있는 차량은 `23:59`까지의 주차 시간을 더한다.
6. 차량 번호순으로 누적 시간을 확인하여 요금을 계산한다.
7. 기본 시간 초과분은 `(초과 시간 + 단위 시간 - 1) / 단위 시간`으로 올림 처리한다.

## 코드 설명
```cpp
int calcTime(string t1, string t2) {
    int h1 = stoi(t1.substr(0,2));
    int h2 = stoi(t2.substr(0,2));
    
    int m1 = stoi(t1.substr(3,2));
    int m2 = stoi(t2.substr(3,2));
    
    if((m2-m1) < 0) return (h2-h1-1)*60 + (60+(m2-m1));
    return (h2-h1)*60 + (m2-m1);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    unordered_map<int,string> parking;
    map<int,int> totalTime;
    int defaultTime = fees[0];
    int defaultFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    string time, carNum, state;
    for(string r : records) {
        stringstream ss(r);
        ss >> time >> carNum >> state;
        int carNumber = stoi(carNum);
        if(state == "IN") parking[carNumber] = time;
        else {
            totalTime[carNumber] += calcTime(parking[carNumber], time);
            parking.erase(carNumber);
        }
    }
    
    for(auto [carNum, time] : parking) {
        totalTime[carNum] += calcTime(time, "23:59");
    }
    
    for(auto [carNum, time] : totalTime) {
        if(time <= defaultTime) answer.push_back(defaultFee);
        else
            answer.push_back(defaultFee + (time - defaultTime + unitTime - 1) / unitTime * unitFee);
    }
    return answer;
}
```
- `calcTime`은 두 시각의 시와 분을 분리하여 주차 시간을 분 단위로 반환한다.
- `parking`은 현재 주차 중인 차량의 입차 시각을 저장한다.
- `totalTime`은 차량별 누적 주차 시간을 저장하며, `map`을 사용해 차량 번호순 정렬도 함께 처리한다.
- `parking.erase(carNumber)`로 출차한 차량을 주차 중 목록에서 제거한다.
- `(time - defaultTime + unitTime - 1) / unitTime`은 기본 시간 초과분을 단위 시간으로 나눈 값을 올림한다.
