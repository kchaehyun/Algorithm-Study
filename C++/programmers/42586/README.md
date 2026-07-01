# Programmers 42586 - 기능개발

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42586)
- 각 기능의 현재 진행률 `progresses`와 하루 개발 속도 `speeds`가 주어진다.
- 기능은 앞에 있는 기능이 배포되어야 뒤의 기능도 함께 배포될 수 있다.
- 각 배포마다 몇 개의 기능이 배포되는지 순서대로 반환한다.

## 아이디어
- 각 기능이 완료되기까지 필요한 날짜를 먼저 계산해 `days`에 저장한다.
- 첫 번째 기능의 완료 날짜를 현재 배포 기준일 `day`로 둔다.
- 뒤 기능의 완료 날짜가 `day` 이하라면 앞 기능과 같은 날 배포할 수 있으므로 개수를 증가시킨다.
- 뒤 기능의 완료 날짜가 `day`보다 크다면 지금까지 묶은 기능 수를 `answer`에 넣고, 새로운 배포 묶음을 시작한다.

## 시간복잡도
- 기능의 개수를 `N`이라고 하면 O(N)

## 풀이 과정
1. 각 기능마다 `100 - progresses[i]`를 `speeds[i]`로 나누어 필요한 완료 일수를 구한다.
2. 나누어떨어지지 않으면 하루를 더해 올림 처리한다.
3. 첫 번째 기능의 완료 일수를 배포 기준일 `day`로 설정하고, 현재 배포 기능 수 `func`를 1로 시작한다.
4. 두 번째 기능부터 순회하면서 완료 일수가 `day` 이하인지 확인한다.
5. `day` 이하라면 같은 배포에 포함되므로 `func`를 증가시킨다.
6. `day`보다 크다면 `func`를 `answer`에 추가하고, 해당 기능을 기준으로 새 배포를 시작한다.
7. 순회가 끝난 뒤 마지막 배포 묶음의 `func`를 `answer`에 추가한다.

## 코드 설명
```cpp
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> days;
    for(int i = 0 ; i < progresses.size() ; ++i) {
        if((100-progresses[i])%speeds[i] == 0)
            days.push_back((100-progresses[i])/speeds[i]);
        else
            days.push_back((100-progresses[i])/speeds[i]+1);
    }
    int day = days[0];
    int func = 1;
    for(int i = 1 ; i < days.size() ; ++i) {
        if(days[i] <= day)
            func++;
        else {
            answer.push_back(func);
            func = 1;
            day = days[i];
        }
    }
    answer.push_back(func);
    return answer;
}
```
- `days`는 각 기능이 완료되기까지 걸리는 날짜를 저장한다.
- `(100 - progresses[i]) / speeds[i]`로 기본 완료 일수를 계산한다.
- 나머지가 있으면 정확히 하루가 더 필요하므로 `+1`을 한다.
- `day`는 현재 배포 묶음에서 가장 앞 기능의 완료 날짜다.
- `days[i] <= day`이면 앞 기능이 배포될 때 함께 배포할 수 있다.
- `days[i] > day`이면 새로운 배포 날짜가 필요하므로 기존 묶음을 `answer`에 저장한다.
