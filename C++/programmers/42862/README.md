# Programmers 42862 - 체육복

## 문제 설명
- [문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/42862)
- 전체 학생 수 `n`, 체육복을 도난당한 학생 번호 배열 `lost`, 여벌 체육복을 가져온 학생 번호 배열 `reserve`가 주어진다.
- 여벌 체육복이 있는 학생은 바로 앞번호 또는 뒷번호 학생에게만 체육복을 빌려줄 수 있다.
- 체육수업을 들을 수 있는 학생의 최댓값을 반환한다.

## 아이디어
- 학생별 체육복 개수를 저장하는 배열 `students`를 만든다.
- 처음에는 모든 학생이 체육복을 1개 가지고 있다고 보고, `lost`는 1개 감소시키고 `reserve`는 1개 증가시킨다.
- 체육복이 0개인 학생을 앞번호부터 확인한다.
- 앞 학생에게 여벌이 있으면 먼저 빌리고, 없으면 뒤 학생에게 빌린다.
- 앞에서부터 처리하면 각 학생이 빌릴 수 있는 가장 가까운 선택을 확정하면서 최대로 많은 학생을 수업에 참여시킬 수 있다.

## 시간복잡도
- 학생 수를 `N`, 도난당한 학생 수를 `L`, 여벌 체육복을 가진 학생 수를 `R`이라고 하면 O(N + L + R)

## 풀이 과정
1. 학생 번호를 그대로 인덱스로 쓰기 위해 크기가 `n + 1`인 `students` 벡터를 만들고 1로 초기화한다.
2. `lost`를 순회하며 해당 학생의 체육복 개수를 1 감소시킨다.
3. `reserve`를 순회하며 해당 학생의 체육복 개수를 1 증가시킨다.
4. 1번 학생부터 n번 학생까지 순회한다.
5. 현재 학생의 체육복이 0개라면 먼저 앞 학생에게 여벌이 있는지 확인한다.
6. 앞 학생에게 빌릴 수 없으면 뒤 학생에게 여벌이 있는지 확인한다.
7. 빌릴 수 있으면 빌려준 학생의 개수를 1 감소시키고, 현재 학생의 개수를 1 증가시킨다.
8. 마지막으로 체육복이 1개 이상인 학생 수를 세어 반환한다.

## 코드 설명
```cpp
int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> students(n+1, 1);
    
    for(int i = 0 ; i < lost.size() ; ++i) {
        students[lost[i]]--;
    }
    for(int i = 0 ; i < reserve.size() ; ++i) {
        students[reserve[i]]++;
    }
    
    for(int i = 1 ; i < students.size() ; ++i) {
        if (!students[i]) {
            if (i > 1 && students[i-1] > 1) {
                students[i-1]--;
                students[i]++;
            }
            else if (i < n && students[i+1] > 1) {
                students[i+1]--;
                students[i]++;
            }
        }
    }
    
    for (int i = 1 ; i < students.size() ; ++i) {
        if (students[i] >= 1)
            answer++;
    }
    
    return answer;
}
```
- `students[i]`는 i번 학생이 가진 체육복 개수를 의미한다.
- 도난과 여벌 정보를 모두 반영하면, 여벌이 있지만 도난도 당한 학생은 자연스럽게 `1`이 되어 다른 학생에게 빌려줄 수 없다.
- `students[i-1] > 1`은 앞 학생에게 빌려줄 여벌 체육복이 있다는 뜻이다.
- 앞 학생에게 빌리지 못했을 때만 `students[i+1] > 1`을 확인해 뒤 학생에게 빌린다.
- 마지막 반복문에서 체육복을 1개 이상 가진 학생만 수업에 참여할 수 있는 학생으로 센다.
