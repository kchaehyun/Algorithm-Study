# Programmers 42885 - 구명보트

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42885)
- 사람들의 몸무게 배열 `people`과 구명보트의 무게 제한 `limit`이 주어진다.
- 구명보트는 한 번에 최대 2명까지 탈 수 있고, 탑승한 사람들의 몸무게 합이 `limit` 이하여야 한다.
- 모든 사람을 구출하기 위해 필요한 구명보트 개수의 최솟값을 반환한다.

## 아이디어
- 몸무게를 오름차순으로 정렬한다.
- 가장 무거운 사람은 반드시 현재 보트에 태워야 한다.
- 가장 무거운 사람과 가장 가벼운 사람을 함께 태울 수 있으면 둘을 같이 태운다.
- 함께 태울 수 없다면 가장 무거운 사람만 혼자 태운다.
- 이 과정을 반복하면 매번 한 대의 보트에 대해 가능한 최선의 선택을 하게 된다.

## 시간복잡도
- 정렬에 O(N log N)
- 투 포인터 순회에 O(N)
- 전체 시간복잡도는 O(N log N)

## 풀이 과정
1. `people`을 오름차순으로 정렬한다.
2. 가장 가벼운 사람의 위치를 가리키는 `left`를 0으로 둔다.
3. 가장 무거운 사람의 위치를 가리키는 `right`를 `people.size() - 1`로 둔다.
4. `left <= right`인 동안 반복한다.
5. `people[left] + people[right] <= limit`이면 두 사람을 함께 태울 수 있으므로 `left`를 1 증가시킨다.
6. 가장 무거운 사람은 혼자 타든 같이 타든 현재 보트에 태웠으므로 `right`를 1 감소시킨다.
7. 보트 한 대를 사용했으므로 `answer`를 1 증가시킨다.
8. 반복이 끝나면 `answer`를 반환한다.

## 코드 설명
```cpp
int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int left = 0, right = people.size()-1;
    while(left <= right) {
        if(people[right] + people[left] <= limit)
            left++;
        answer++;
        right--;
    }
    return answer;
}
```
- `sort`로 몸무게를 정렬해 가장 가벼운 사람과 가장 무거운 사람을 양끝에서 확인할 수 있게 한다.
- `right`는 아직 구출하지 않은 사람 중 가장 무거운 사람을 가리킨다.
- `left`는 아직 구출하지 않은 사람 중 가장 가벼운 사람을 가리킨다.
- 두 사람의 합이 `limit` 이하라면 같이 태우고, 아니면 가장 무거운 사람만 태운다.
- 반복마다 보트 한 대가 사용되므로 `answer++`를 수행한다.
